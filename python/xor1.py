#!/usr/bin/env python
# coding: UTF-8
'''
XOR calculation samples.
'''


Enc = lambda plain, key: ''.join([chr(ord(x) ^ key) for x in plain])
Dec = Enc

print(Dec(Enc("abcd", 0x4f), 0x4f)) # => "abcd"

