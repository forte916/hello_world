# -*- coding: utf-8 -*-
# Python 2.x

import sys

def usage():
        print 'Usage:  {} num1 num2'.format(sys.argv[0])
        print '   eg)  {} 11 22'.format(sys.argv[0])
        print '   eg)  echo 33 44 | {}'.format(sys.argv[0])


def add(x, y):
    return x + y

def main():
    print '{} start {}'.format('-'*5, '-'*5)
    if len(sys.argv) < 3:
        line = sys.stdin.readline()
        if not line:
            usage()
        else:
            x, y = map(int, line.strip().split())
    else:
        #### Read from command line args
        x = int(sys.argv[1])
        y = int(sys.argv[2])

    ret = add(x, y)
    print '{} + {} = {}'.format(x, y, ret)
    sys.exit(0)


if __name__ == '__main__':
    main()

