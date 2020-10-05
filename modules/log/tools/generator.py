from util import conf
from gen import genCMake
from gen import genHeader
from gen import genSource

import os
import argparse
import shutil

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Logger generator')
    parser.add_argument("-s", "--srcDir", type=str, default="template", help="path to template c++ files")
    parser.add_argument("-d", "--dstDir", type=str, default="../generated", help="directory that will house the generated c++ files")
    args = parser.parse_args()

    if not os.path.exists(args.dstDir):
        try:
            os.makedirs(args.dstDir)
        except OSError as exc: # Guard against race condition
            if exc.errno != errno.EEXIST:
                raise

    conf = conf.Conf()
    conf.readConf()

    genCM = genCMake.GenCMake(conf.activeModulesUp, os.path.join(args.srcDir, "CMakeLists.txt"), args.dstDir)
    genCM.gen()

    genH = genHeader.GenHeader(conf.activeModulesUp, os.path.join(args.srcDir, "log.h"), args.dstDir)
    genH.gen()

    genS = genSource.GenSource(conf.activeModulesUp, conf.activeIdlPaths, os.path.join(args.srcDir, "log.cpp"), args.dstDir)
    genS.gen()

    shutil.copyfile(os.path.join(args.srcDir, "main.cpp"), os.path.join(args.dstDir, "main.cpp"))
