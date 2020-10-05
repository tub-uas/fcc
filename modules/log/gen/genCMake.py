from idl import Idl

import re
import os
import shutil

class GenCMake():

    def __init__(self, types, src, dst):
        self._fileName = "CMakeLists.txt"
        self._types = types
        self._src = src
        self._dst = dst
        self._data = list()

    @property
    def addLibrary(self):
        c = list()
        for t in self._types:
            c.extend(["add_library(Data%s ../%s/idl/Data%s.cxx ../%s/idl/Data%sPubSubTypes.cxx)\n" % (Idl.toUp(t), Idl.toLow(t), Idl.toUp(t), Idl.toLow(t), Idl.toUp(t))])
        return c

    @property
    def targetLink(self):
        c = list()
        for t in self._types:
            c.extend(["target_link_libraries(${PROJECT_NAME} Data%s)\n" % (t)])
        return c

    def gen(self):
        # copyfile(self._src, self._fileName)
        with open(self._src, 'r') as f:
            self._data = f.readlines()

        with open(os.path.join(self._dst, self._fileName), 'w') as f:
            for d in self._data:
                f.write(d)
                if '###PYTHON_GEN_ADD_LIBRARY' in d:
                    f.writelines(self.addLibrary)
                elif '###PYTHON_GEN_TARGET_LINK' in d:
                    f.writelines(self.targetLink)
