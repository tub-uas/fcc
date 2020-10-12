from util.idl import Idl

import yaml
import os

class Conf():

    def __init__(self):
        self._modules = list()

    @property
    def allModules(self):
        allModules = list()
        for root, dirs, files in os.walk(self.currentDir, topdown=True):
            for file in files:
                if file.endswith('.idl'):
                    allModules.extend([os.path.splitext(file)[0][4:]])
        return list(Idl.toLow(e) for e in allModules)

    @property
    def activeModules(self):
        return self._modules

    @property
    def activeModulesUp(self):
        return list(map(lambda x:x[0].upper()+x[1:], self._modules))

    @property
    def activeModulesLow(self):
        return list(map(lambda x:x[0].lower()+x[1:], self._modules))

    @property
    def currentDir(self):
        cwd = os.getcwd().split("fcc", 1)
        return os.path.join(cwd[0], "fcc")

    @property
    def allIdlPaths(self):
        allIdlPaths = {}
        for root, dirs, files in os.walk(self.currentDir, topdown=True):
            for file in files:
                if file.endswith('.idl'):
                    allIdlPaths[os.path.splitext(file)[0][4:]] = os.path.join(root, file)
        return dict((Idl.toLow(k), v) for k,v in allIdlPaths.items())

    @property
    def activeIdlPaths(self):
        return {key: self.allIdlPaths[key] for key in self.activeModulesLow}

    def readConf(self):
        with open("config.yaml", 'r') as stream:
            self._modules= yaml.safe_load(stream)['active-modules']
