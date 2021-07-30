from util.idl import Idl

import os
import pprint as pp

class GenSource():

    def __init__(self, modules, paths, src, dst):
        self._fileName = "log.cpp"
        self._modules = modules
        self._paths = paths
        self._src = src
        self._dst = dst
        self._data = list()

    @property
    def dataCallback(self):
        c = list()
        c.extend(["\tif (topic.compare(\"Data%s\") == 0)\n" % (Idl.toUp(self._modules[0]))])
        c.extend(self.dataCallbackHelper(self._modules[0]))
        for m in self._modules[1:]:
            c.extend(["\t}\n",
                      "\telse if (topic.compare(\"Data%s\") == 0)\n" % (Idl.toUp(m))])
            c.extend(self.dataCallbackHelper(m))
        c.extend(["\t} else {\n",
                  "\t\t\n",
                  "\t}\n"])
        return c

    def dataCallbackHelper(self, m):
        c = list()
        c.extend(["\t{\n"
                  "\t\tstd::unique_lock<std::mutex> data%sLock {data%sMutex};\n" % (Idl.toUp(m), Idl.toUp(m)),
                  "\t\tif(reader->take_next_sample(&data%s, &info) == ReturnCode_t::RETCODE_OK) \n\t\t{\n" % (Idl.toUp(m)),
                  "\t\t\tif(info.instance_state == eprosima::fastdds::dds::ALIVE_INSTANCE_STATE && info.valid_data) \n\t\t\t{\n",
                  "\t\t\t\t newData%s = true;\n" % (Idl.toUp(m)),
                  "\t\t\t}\n",
                  "\t\t}\n",
                  "\t\tdata%sLock.unlock();\n" % (Idl.toUp(m))])
        return c

    @property
    def constr(self):
        c = list()
        for m in self._modules[:-1]:
            c.extend(self.constrHelper(m))
            c.extend([",\n"])
        c.extend(self.constrHelper(self._modules[-1]))
        c.extend([" {\n"])
        return c

    def constrHelper(self, m):
        c = list()
        c.extend(["             topic%s(nullptr),\n" % (Idl.toUp(m)),
                  "             reader%s(nullptr),\n" % (Idl.toUp(m)),
                  "             type%s(new Data%sPubSubType())" % (Idl.toUp(m), Idl.toUp(m))])
        return c

    @property
    def delete(self):
        c = list()
        for m in self._modules:
            c.extend(["\tif (reader%s != nullptr) {\n" % (Idl.toUp(m)),
                      "\t\tsubscriber->delete_datareader(reader%s);\n" % (Idl.toUp(m)),
                      "\t}\n",
                      "\tif (topic%s != nullptr) {\n" % (Idl.toUp(m)),
                      "\t\tparticipant->delete_topic(topic%s);\n" % (Idl.toUp(m)),
                      "\t}\n"])
        return c

    @property
    def close(self):
        c = list()
        for m in self._modules:
            c.extend(["\t%sFile.close();\n" % (Idl.toLow(m))])
        return c

    @property
    def registerType(self):
        c = list()
        for m in self._modules:
            c.extend(["\t// Register the Type\n",
                      "\ttype%s.register_type(participant);\n" % (Idl.toUp(m)),
                      "\t// Create the subscriptions Topic\n",
                      "\ttopic%s = participant->create_topic(\"Data%s\", \"Data%s\", eprosima::fastdds::dds::TOPIC_QOS_DEFAULT);\n" % (Idl.toUp(m), Idl.toUp(m), Idl.toUp(m)),
                      "\tif (topic%s == nullptr) {\n" % (Idl.toUp(m)),
                      "\t\treturn false;\n",
                      "\t}\n"])
        return c

    @property
    def createDatareader(self):
        c = list()
        for m in self._modules:
            c.extend(["\t// Create the DataReader\n",
                      "\treader%s = subscriber->create_datareader(topic%s, eprosima::fastdds::dds::DATAREADER_QOS_DEFAULT, &listener);\n" % (Idl.toUp(m), Idl.toUp(m)),
                      "\tif (reader%s == nullptr) {\n" % (Idl.toUp(m)),
                      "\t\treturn false;\n",
                      "\t}\n"])
        return c

    @property
    def openFiles(self):
        c = list()
        for m in self._modules:
            c.extend(["\t%sFile.open(logdir.str() + \"/%s.log\", std::ios::app | std::fstream::in | std::fstream::out | std::ios::binary);\n" % (Idl.toLow(m), Idl.toLow(m))])
        return c

    @property
    def writeFiles(self):
        c = list()
        for mod, dir in self._paths.items():
            c.extend(["\t\tif (listener.newData%s) {\n" % (Idl.toUp(mod)),
                      "\t\t\tstd::unique_lock<std::mutex> data%sLock {listener.data%sMutex};\n" % (Idl.toUp(mod), Idl.toUp(mod)),
                      "\t\t\t// std::cout << \"newData%s\" << std::endl;\n" % (Idl.toUp(mod))])
            i = Idl(mod, dir)
            i.decodeIdl()
            for t in i.objs:
                if t[0][-1] == "]":
                    t[0] = t[0].split("[", 1)[0]
                    c.extend(["\t\t\tfor (unsigned int i=0; i<listener.data%s.%s().size(); i++) {\n" % (Idl.toUp(mod), Idl.toLow(t[0]))])
                    c.extend(["\t\t\t\t%sFile.write(reinterpret_cast<const char*>(&listener.data%s.%s().at(i)), sizeof(listener.data%s.%s().at(i)));\n" % (Idl.toLow(mod), Idl.toUp(mod), Idl.toLow(t[0]), Idl.toUp(mod), Idl.toLow(t[0]))])
                    c.extend(["\t\t\t}\n"])
                else:
                    c.extend(["\t\t\t%sFile.write(reinterpret_cast<const char*>(&listener.data%s.%s()), sizeof(listener.data%s.%s()));\n" % (Idl.toLow(mod), Idl.toUp(mod), Idl.toLow(t[0]), Idl.toUp(mod), Idl.toLow(t[0]))])

            c.extend(["\t\t\t%sFile.flush();\n" % (Idl.toLow(mod)),
                      "\t\t\tlistener.newData%s = false;\n" % (Idl.toUp(mod)),
                      "\t\t\tdata%sLock.unlock();\n" % (Idl.toUp(mod)),
                      "\t\t}\n"])
        return c

    def gen(self):
        # copyfile(self._src, self._fileName)
        with open(self._src, 'r') as f:
            self._data = f.readlines()

        if not os.path.exists(self._dst):
            try:
                os.makedirs(self._dst)
            except OSError as exc: # Guard against race condition
                if exc.errno != errno.EEXIST:
                    raise

        with open(os.path.join(self._dst, self._fileName), 'w') as f:
            for l in self._data:
                f.write(l)
                if '/***PYTHON_GEN_ON_DATA_CALLBACK*/' in l:
                    f.writelines(self.dataCallback)
                elif '/***PYTHON_GEN_CONSTR*/' in l:
                    f.writelines(self.constr)
                elif '/***PYTHON_GEN_DELETE*/' in l:
                    f.writelines(self.delete)
                elif '/***PYTHON_GEN_CLOSE_FILES*/' in l:
                    f.writelines(self.close)
                elif '/***PYTHON_GEN_REGISTER_TYPE*/' in l:
                    f.writelines(self.registerType)
                elif '/***PYTHON_GEN_CREATE_DATAREADER*/' in l:
                    f.writelines(self.createDatareader)
                elif '/***PYTHON_GEN_OPEN_FILES*/' in l:
                    f.writelines(self.openFiles)
                elif '/***PYTHON_GEN_WRITE_FILES*/' in l:
                    f.writelines(self.writeFiles)
