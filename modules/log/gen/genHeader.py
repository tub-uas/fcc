from idl import Idl

import re
import os
import shutil

class GenHeader():

    def __init__(self, types, src, dst):
        self._fileName = "log.h"
        self._types = types
        self._src = src
        self._dst = dst
        self._data = list()

    @property
    def pubSub(self):
        c = list()
        for t in self._types:
            c.extend(["#include \"./../%s/idl/Data%sPubSubTypes.h\"\n" % (Idl.toLow(t), Idl.toUp(t))])
        return c

    @property
    def dataMutex(self):
        c = list()
        for t in self._types:
            c.extend(["\tData%s data%s;\n" % (Idl.toUp(t), Idl.toUp(t)),
                      "\tstd::mutex data%sMutex;\n" % (Idl.toUp(t)),
                      "\tstd::atomic_bool newData%s;\n" % (Idl.toUp(t))])
        return c

    @property
    def topic(self):
        c = list()
        for t in self._types:
            c.extend(["\teprosima::fastdds::dds::Topic       *topic%s;\n" % (Idl.toUp(t)),
                      "\teprosima::fastdds::dds::DataReader  *reader%s;\n" % (Idl.toUp(t)),
                      "\teprosima::fastdds::dds::TypeSupport  type%s;\n" % (Idl.toUp(t))])
        return c

    @property
    def files(self):
        c = list()
        for t in self._types:
            c.extend(["\tstd::fstream %sFile;\n" % (Idl.toLow(t))])
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
            for d in self._data:
                f.write(d)
                if '/***PYTHON_GEN_PUBSUB*/' in d:
                    f.writelines(self.pubSub)
                elif '/***PYTHON_GEN_DATA_MUTEX*/' in d:
                    f.writelines(self.dataMutex)
                elif '/***PYTHON_GEN_TOPIC*/' in d:
                    f.writelines(self.topic)
                elif '/***PYTHON_GEN_FILES*/' in d:
                    f.writelines(self.files)
