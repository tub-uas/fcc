from util.idl import Idl
from util import conf
from util import idl

import os
import pprint as pp
import sys
import struct
import argparse
import os
import shutil

class Dec():

    def __init__(self, name, srcPath, dstPath, types):
        self._name = name
        self._srcPath = srcPath
        self._dstPath = dstPath
        self._types = types
        self._data = list()
        self._sepChar = " "

    def sizeLookup(self, x):
        return {
            'unsigned long long': 8,
            'unsigned short': 2,
            'float': 4,
            'double': 8,
            'boolean': 1,
        }[x]

    def typeLookup(self, x):
        return {
            'unsigned long long': 'Q',
            'unsigned short': 'H',
            'float': 'f',
            'double': 'd',
            'boolean': 'b', # or '?' for True/False instead of 1/0
        }[x]

    @property
    def packetSize(self):
        return sum(list(map(lambda x: self.sizeLookup(x), [i[1] for i in self._types])))

    @property
    def header(self):
        h = str()
        for t in self._types:
            h += t[0] + self._sepChar
        return h + "\n"

    def decodePacket(self, chunk):
        p = str()
        for t in self._types:
            size = self.sizeLookup(t[1])
            data = chunk[0:size]
            p += str(struct.unpack(self.typeLookup(t[1]), data)[0]) + self._sepChar
            chunk = chunk[size:]
        return p + "\n"

    def decode(self):
        with open(self._srcPath, "rb") as fpSrc:
            with open(self._dstPath, "w") as fpDst:
                fpDst.write(self.header)
                chunk = fpSrc.read(self.packetSize)
                while chunk:
                    fpDst.write(self.decodePacket(chunk))
                    chunk = fpSrc.read(self.packetSize)

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Logfile decoder')
    parser.add_argument("-s", "--srcDir", type=str, required=True, help="path to binary log files")
    parser.add_argument("-d", "--dstDir", type=str, default="../decoded", help="directory that will house the decoded log files")
    args = parser.parse_args()

    # print(args.srcDir)
    # print(args.dstDir)

    if not os.path.isdir(args.srcDir):
        raise ValueError("srcDir is not a directory")

    if not os.path.exists(args.dstDir):
        try:
            os.makedirs(args.dstDir)
        except OSError as exc: # Guard against race condition
            if exc.errno != errno.EEXIST:
                raise

    conf = conf.Conf()
    conf.readConf()

    # pp.pprint(conf.activeIdlPaths)
    # pp.pprint(conf.activeModules)
    # pp.pprint(conf.allModules)
    # pp.pprint(conf.allIdlPaths)
    # pp.pprint(conf.currentDir)

    for mod, dir in conf.activeIdlPaths.items():

        print("Decoding " + mod + " ...", end='')

        i = Idl(mod, dir)
        i.decodeIdl()
        pp.pprint(i.objs)

        srcFile = os.path.join(args.srcDir, mod + ".log")
        dstFile = os.path.join(args.dstDir, mod + ".txt")
        # print(srcFile)
        # print(dstFile)

        d = Dec(mod, srcFile, dstFile, i.objs)
        d.decode()

        print(" done")
