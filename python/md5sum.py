#!/usr/bin/python
# coding: UTF-8
'''
Print or check MD5 (128-bit) checksums.
'''

import sys
import os

try:
    import hashlib
except ImportError:
    import md5
    class _hashlib:
        md5 = __call__ = md5.new
    hashlib = _hashlib()


### TODO: With no FILE, or when FILE is -, read standard input.
def main():
    targets = []
    param = sys.argv[1:]
    while param:
        f = param.pop()
        targets.append(f)
    if not targets:
        sys.exit('Usage: {0} [FILE]...'.format(sys.argv[0]))

    targets.sort()
    for f in targets:
        if os.path.isdir(f):
            print('md5sum: {}: Is a directory'.format(f))
            continue
        _md5 = hashlib.md5()
        _md5.update(file(f, 'rb').read())
        checksum = _md5.hexdigest()
        print(checksum + " *" +  f)


if __name__ == '__main__':
    main()

