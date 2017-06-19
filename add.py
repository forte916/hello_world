# -*- coding: utf-8 -*-
# Python 2.x

import sys

def usage():
        print 'usage: {} num1 num2'.format(sys.argv[0])
        print '   eg) {} 11 22'.format(sys.argv[0])
        print '   eg) echo 33 44 | {}'.format(sys.argv[0])


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
            ret = add(x, y)
            print '{} + {} = {}'.format(x, y, ret)
    else:
        ret = add(int(sys.argv[1]), int(sys.argv[2]))
        print '{} + {} = {}'.format(sys.argv[1], sys.argv[2], ret)

    sys.exit(0)


if __name__ == '__main__':
    main()

