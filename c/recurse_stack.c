/**
 * How to run
 *   $ gcc -o recurse_stack recurse_stack.c
 *   $ ./recurse_stack
 */

#include <stdio.h>

void recurse_stack(int depth)
{
	char str[65535]  = {0};
	printf("depth %3d: stack %p \n", depth, &str);
	recurse_stack(depth + 1);
}


int main(int argc, char *argv[])
{
	printf("Hello, world!\n");

	int depth = 0;
	recurse_stack(depth);

	return 0;
}


/*
手元の実行結果では、大量の stack を確保するとアプリがクラッシュすることが確認できました

Console output:

// On Mac
$ gcc -o recurse_stack recurse_stack.c
$ ./recurse_stack
Hello, world!
depth   0: stack 0x7fff5602c960
depth   1: stack 0x7fff5601c920
depth   2: stack 0x7fff5600c8e0
depth   3: stack 0x7fff55ffc8a0
depth   4: stack 0x7fff55fec860
depth   5: stack 0x7fff55fdc820
depth   6: stack 0x7fff55fcc7e0
depth   7: stack 0x7fff55fbc7a0
depth   8: stack 0x7fff55fac760
depth   9: stack 0x7fff55f9c720
depth  10: stack 0x7fff55f8c6e0
depth  11: stack 0x7fff55f7c6a0
depth  12: stack 0x7fff55f6c660
depth  13: stack 0x7fff55f5c620
depth  14: stack 0x7fff55f4c5e0
depth  15: stack 0x7fff55f3c5a0
depth  16: stack 0x7fff55f2c560
depth  17: stack 0x7fff55f1c520
depth  18: stack 0x7fff55f0c4e0
depth  19: stack 0x7fff55efc4a0
depth  20: stack 0x7fff55eec460
depth  21: stack 0x7fff55edc420
depth  22: stack 0x7fff55ecc3e0
depth  23: stack 0x7fff55ebc3a0
depth  24: stack 0x7fff55eac360
depth  25: stack 0x7fff55e9c320
depth  26: stack 0x7fff55e8c2e0
depth  27: stack 0x7fff55e7c2a0
depth  28: stack 0x7fff55e6c260
depth  29: stack 0x7fff55e5c220
depth  30: stack 0x7fff55e4c1e0
depth  31: stack 0x7fff55e3c1a0
depth  32: stack 0x7fff55e2c160
depth  33: stack 0x7fff55e1c120
depth  34: stack 0x7fff55e0c0e0
depth  35: stack 0x7fff55dfc0a0
depth  36: stack 0x7fff55dec060
depth  37: stack 0x7fff55ddc020
depth  38: stack 0x7fff55dcbfe0
depth  39: stack 0x7fff55dbbfa0
depth  40: stack 0x7fff55dabf60
depth  41: stack 0x7fff55d9bf20
depth  42: stack 0x7fff55d8bee0
depth  43: stack 0x7fff55d7bea0
depth  44: stack 0x7fff55d6be60
depth  45: stack 0x7fff55d5be20
depth  46: stack 0x7fff55d4bde0
depth  47: stack 0x7fff55d3bda0
depth  48: stack 0x7fff55d2bd60
depth  49: stack 0x7fff55d1bd20
depth  50: stack 0x7fff55d0bce0
depth  51: stack 0x7fff55cfbca0
depth  52: stack 0x7fff55cebc60
depth  53: stack 0x7fff55cdbc20
depth  54: stack 0x7fff55ccbbe0
depth  55: stack 0x7fff55cbbba0
depth  56: stack 0x7fff55cabb60
depth  57: stack 0x7fff55c9bb20
depth  58: stack 0x7fff55c8bae0
depth  59: stack 0x7fff55c7baa0
depth  60: stack 0x7fff55c6ba60
depth  61: stack 0x7fff55c5ba20
depth  62: stack 0x7fff55c4b9e0
depth  63: stack 0x7fff55c3b9a0
depth  64: stack 0x7fff55c2b960
depth  65: stack 0x7fff55c1b920
depth  66: stack 0x7fff55c0b8e0
depth  67: stack 0x7fff55bfb8a0
depth  68: stack 0x7fff55beb860
depth  69: stack 0x7fff55bdb820
depth  70: stack 0x7fff55bcb7e0
depth  71: stack 0x7fff55bbb7a0
depth  72: stack 0x7fff55bab760
depth  73: stack 0x7fff55b9b720
depth  74: stack 0x7fff55b8b6e0
depth  75: stack 0x7fff55b7b6a0
depth  76: stack 0x7fff55b6b660
depth  77: stack 0x7fff55b5b620
depth  78: stack 0x7fff55b4b5e0
depth  79: stack 0x7fff55b3b5a0
depth  80: stack 0x7fff55b2b560
depth  81: stack 0x7fff55b1b520
depth  82: stack 0x7fff55b0b4e0
depth  83: stack 0x7fff55afb4a0
depth  84: stack 0x7fff55aeb460
depth  85: stack 0x7fff55adb420
depth  86: stack 0x7fff55acb3e0
depth  87: stack 0x7fff55abb3a0
depth  88: stack 0x7fff55aab360
depth  89: stack 0x7fff55a9b320
depth  90: stack 0x7fff55a8b2e0
depth  91: stack 0x7fff55a7b2a0
depth  92: stack 0x7fff55a6b260
depth  93: stack 0x7fff55a5b220
depth  94: stack 0x7fff55a4b1e0
depth  95: stack 0x7fff55a3b1a0
depth  96: stack 0x7fff55a2b160
depth  97: stack 0x7fff55a1b120
depth  98: stack 0x7fff55a0b0e0
depth  99: stack 0x7fff559fb0a0
depth 100: stack 0x7fff559eb060
depth 101: stack 0x7fff559db020
depth 102: stack 0x7fff559cafe0
depth 103: stack 0x7fff559bafa0
depth 104: stack 0x7fff559aaf60
depth 105: stack 0x7fff5599af20
depth 106: stack 0x7fff5598aee0
depth 107: stack 0x7fff5597aea0
depth 108: stack 0x7fff5596ae60
depth 109: stack 0x7fff5595ae20
depth 110: stack 0x7fff5594ade0
depth 111: stack 0x7fff5593ada0
depth 112: stack 0x7fff5592ad60
depth 113: stack 0x7fff5591ad20
depth 114: stack 0x7fff5590ace0
depth 115: stack 0x7fff558faca0
depth 116: stack 0x7fff558eac60
depth 117: stack 0x7fff558dac20
depth 118: stack 0x7fff558cabe0
depth 119: stack 0x7fff558baba0
depth 120: stack 0x7fff558aab60
depth 121: stack 0x7fff5589ab20
depth 122: stack 0x7fff5588aae0
depth 123: stack 0x7fff5587aaa0
depth 124: stack 0x7fff5586aa60
depth 125: stack 0x7fff5585aa20
depth 126: stack 0x7fff5584a9e0
Segmentation fault: 11



// On cygwin
$ ./recurse_stack
Hello, world!
depth   0: stack 0xfffecbc0
depth   1: stack 0xfffdcb90
depth   2: stack 0xfffccb60
depth   3: stack 0xfffbcb30
depth   4: stack 0xfffacb00
depth   5: stack 0xfff9cad0
depth   6: stack 0xfff8caa0
depth   7: stack 0xfff7ca70
depth   8: stack 0xfff6ca40
depth   9: stack 0xfff5ca10
depth  10: stack 0xfff4c9e0
depth  11: stack 0xfff3c9b0
depth  12: stack 0xfff2c980
depth  13: stack 0xfff1c950
depth  14: stack 0xfff0c920
depth  15: stack 0xffefc8f0
depth  16: stack 0xffeec8c0
depth  17: stack 0xffedc890
depth  18: stack 0xffecc860
depth  19: stack 0xffebc830
depth  20: stack 0xffeac800
depth  21: stack 0xffe9c7d0
depth  22: stack 0xffe8c7a0
depth  23: stack 0xffe7c770
depth  24: stack 0xffe6c740
depth  25: stack 0xffe5c710
depth  26: stack 0xffe4c6e0
depth  27: stack 0xffe3c6b0
depth  28: stack 0xffe2c680
depth  29: stack 0xffe1c650
depth  30: stack 0xffe0c620
Segmentation fault (コアダンプ)

*/
