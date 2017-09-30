# -*- coding: utf-8 -*-

import sys
import os
import glob
import datetime

def showToday():
    today = datetime.datetime.now()
    print('today....' + str(today))

def testPathSeparator():
    entries1 = glob.glob(os.path.join('.git', 'hooks', 'pre*')) # work both cygwin and msys
    print(entries1)

    entries2 = glob.glob('.git/hooks/pre*')      # work both cygwin and msys
    print(entries2)

    entries3 = glob.glob('.git\hooks\pre*')      # NOT work cygwin, work msys
    print(entries3)

    entries4 = glob.glob('.git\\hooks\\pre*')     # NOT work cygwin, work msys
    print(entries4)

    entries5 = glob.glob('.git/hooks/pre*'.replace('/', os.sep))  # work both cygwin and msys
    print(entries5)


if __name__ == '__main__':
    print '{} start {}'.format('-'*5, '-'*5)
    showToday()
    testPathSeparator()

