# -*- coding: utf-8 -*-
from __future__ import print_function
import sys
import struct

"""
Description:
    Show a GIF header info.

Input:
    Pass the path of GIF file to this script.

    A pseudocode of GIF header format.
        struct {
            char  signature[3];
            char  version[3];
            u16   logicalScreenWidth;
            u16   logicalScreenHeight;
            u8    flags; //GCTF 1bit, CR 3bit, SF 1bit, SGCT 3bit
            u8    backgroundColorIndex;
            u8    pixelAspectRatio;
            struct {
                u8 R;
                u8 G;
                u8 B;
            } globalColorTable[n]; // 0 <= n <= 255
        } GIF_header;

Output:
    A GIF header info.
"""

def usage():
    print("Usage:  %s example.gif" % sys.argv[0])
    sys.exit(1)


def ShowGIFHeaderInfo(h):
    print('Sig   : %s' % h['sig'])
    print('Ver   : %s' % h['ver'])
    print('Width : %d' % h['width'])
    print('Height: %d' % h['height'])
    print('Flags : %s' % format(h['flags'], 'b'))
    print('    GCGF: %x' % h['gcgf'])
    print('    CR  : %x' % h['cr'])
    print('    SF  : %x' % h['sf'])
    print('    SGCT: %x' % h['sgct'])
    print('    Size: %d' % h['tableSize'])
    print('BgIdx : %d' % h['bgidx'])
    print('Ratio : %x' % h['ratio'])
    print('Palette: %s' % h['palette'])


def ReadGIFHeader(infile):
    try:
        fin  = open(infile, 'rb')
    except IOError as e:
        print('%s: %s' % (type(e).__name__, str(e)), file=sys.stderr)
        return
    try:
        h = {} # header
        h['sig'] = str(fin.read(3))                  # signature, 3bytes

        if  h['sig'] != 'GIF':
            print('Invalid GIF signature: %s' % h['sig'], file=sys.stderr)
            return

        h['ver'] = str(fin.read(3))                  # version, 3bytes
        if  h['ver'] not in ['87a', '89a']:
            print('Invalid GIF version: %s' % h['ver'], file=sys.stderr)
            return


        h['width']  = struct.unpack("<H", fin.read(2))[0]  # logicalScreehWidth, 2bytes
        h['height'] = struct.unpack("<H", fin.read(2))[0]  # logicalScreehHeight, 2bytes

        h['flags']  = struct.unpack("<B", fin.read(1))[0]  # flags
        h['bgidx']  = struct.unpack("<B", fin.read(1))[0]  # backgroundColorIndex
        h['ratio']  = struct.unpack("<B", fin.read(1))[0]  # pixelAspectRatio

        #h['gcgf'] = h['flags'] & int("10000000", 2)  # Global Color Table Flags
        h['gcgf'] = (h['flags'] >> 7) & 1            # Global Color Table Flags

        #h['cr'] = h['flags'] & int("01110000", 2)    # Color Resolution
        h['cr'] = (h['flags'] >> 4) & 7              # Color Resolution

        #h['sf'] = h['flags'] & int("00001000", 2)    # Sort Flag
        h['sf'] = (h['flags'] >> 3) & 1              # Sort Flag

        #h['sgct'] = h['flags'] & int("00000111", 2)  # Size of Global Color Table
        h['sgct'] = (h['flags'] & 7)                 # Size of Global Color Table

        #h['tableSize'] = 3 * 2**( h['sgct'] + 1 )    # actual table size
        h['tableSize'] = (2 << h['sgct']) * 3        # actual table size

        if h['gcgf']:
            h['gct'] = fin.read(h['tableSize'])
            paletteSize = int(len(h['gct']) / 3)
            h['palette'] = []
            for pos in range(0, paletteSize):
                h['palette'].append(struct.unpack_from('<BBB', h['gct'], pos * 3))

        ShowGIFHeaderInfo(h)

    finally:
        fin.close()

#
# main
#
if __name__ == '__main__':
    if (len(sys.argv) != 2):
        usage()
    else:
        infile  = sys.argv[1]

    ReadGIFHeader(infile)

