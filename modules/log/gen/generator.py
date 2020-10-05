from util import conf
from gen import genCMake
from gen import genHeader
from gen import genSource

import os
import argparse
import shutil

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Logger generator')
    parser.add_argument("-g", "--generatedDir", type=str, default="../generated", help="directory that will house the generated c++ files")
    parser.add_argument("-t", "--templateDir", type=str, default="../template", help="path to template c++ files")
    args = parser.parse_args()

    if not os.path.exists(args.generatedDir):
        try:
            os.makedirs(args.generatedDir)
        except OSError as exc: # Guard against race condition
            if exc.errno != errno.EEXIST:
                raise

    conf = conf.Conf()
    conf.readConf()

    genCM = genCMake.GenCMake(conf.activeModulesUp, os.path.join(args.templateDir, "CMakeLists.txt"), args.generatedDir)
    genCM.gen()

    genH = genHeader.GenHeader(conf.activeModulesUp, os.path.join(args.templateDir, "log.h"), args.generatedDir)
    genH.gen()

    genS = genSource.GenSource(conf.activeModulesUp, conf.activeIdlPaths, os.path.join(args.templateDir, "log.cpp"), args.generatedDir)
    genS.gen()

    shutil.copyfile(os.path.join(args.templateDir, "main.cpp"), os.path.join(args.generatedDir, "main.cpp"))
