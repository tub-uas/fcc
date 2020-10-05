from idl import Idl

import re
import os
import shutil
import struct

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
            'float': 4,
            'boolean': 1,
            'unsigned short': 2,
        }[x]

    def typeLookup(self, x):
        return {
            'unsigned long long': 'Q',
            'float': 'f',
            'boolean': 'b', # or '?' for True / False instead of 1 / 0
            'unsigned short': 'H', # or '?' for True / False instead of 1 / 0
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
