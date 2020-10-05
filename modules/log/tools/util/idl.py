import pprint as pp

class Idl():

    def __init__(self, name, dir):
        self._name = name
        self._dir = dir
        self._objs = []
        self._expObjs = []

    @property
    def name(self):
        return self._name

    @property
    def nameUp(self):
        return self.toUp(self._name)

    @property
    def nameLow(self):
        return self.toLow(self._name)

    @staticmethod
    def toUp(name):
        return name[0].upper()+name[1:]

    @staticmethod
    def toLow(name):
        return name[0].lower()+name[1:]

    @property
    def dir(self):
        return self._dir

    @property
    def objs(self):
        return self._objs

    @property
    def expObjs(self):
        return self._expObjs

    @property
    def objsNames(self):
        return list(map(lambda x: x[0], self._objs))

    def expandArrays(self, x):
        expanded = list()
        for obj in self._objs:
            if obj[0][-1] == "]":
                name = obj[0].split("[", 1)[0]
                nums = int(obj[0].split("[", 1)[1][:-1])
                for i in range(0, nums):
                    expanded.append([name+"["+str(i)+"]", obj[1]])
            else:
                expanded.append(obj)
        return expanded

    def decodeIdl(self):
        with open(self.dir) as f:
            line = f.readline()
            while line:
                line = line.split("//", 1)[0] # remove comments from idl
                self._objs.append(line.split())
                line = f.readline()

        # TODO check format of idl
        # if any (k in self._types for k in line.split()):
        #     print(line.split())

        self._objs = list(map(lambda x: [x[-1][:-1], ' '.join(x[:-1])], self._objs[1:-1]))
        self._expObjs = self.expandArrays(self._objs)
