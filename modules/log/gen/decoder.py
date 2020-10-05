import conf
import idl
import dec

import os
import pprint as pp
import sys
import struct
import argparse

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Logfile decoder')
    parser.add_argument("-s", "--srcDir", type=str, required=True, help="path to binary log files")
    parser.add_argument("-d", "--dstDir", type=str, default="decoded", help="directory that will house the decoded log files")
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

    # pp.pprint(conf.activeIdlPaths)
    # pp.pprint(conf.activeModules)
    # pp.pprint(conf.allModules)
    # pp.pprint(conf.allIdlPaths)
    # pp.pprint(conf.currentDir)

    for mod, dir in conf.activeIdlPaths.items():

        print("Decoding " + mod + " ...", end='')

        i = idl.Idl(mod, dir)
        i.decodeIdl()
        # pp.pprint(i.objs)

        srcFile = os.path.join(args.srcDir, mod + ".log")
        dstFile = os.path.join(args.dstDir, mod + ".txt")
        # print(srcFile)
        # print(dstFile)

        d = dec.Dec(mod, srcFile, dstFile, i.objs)
        d.decode()

        print(" done")
