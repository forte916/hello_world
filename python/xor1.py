#!/usr/bin/env python
# coding: UTF-8
'''
XOR encode and decode samples.
'''


Enc = lambda plain, key: ''.join([chr(ord(x) ^ key) for x in plain])
Dec = Enc

print(Dec(Enc("abcd", 0x4f), 0x4f)) # => "abcd"

