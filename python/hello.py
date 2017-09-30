# -*- coding: utf-8 -*-

# Python 2.x
print "Hello, world!"

# Python 3.x
print("Hello, world!")

# Multi byte characters should be encoded.
print ((u'ハロー').encode('utf-8'))

# If not, UnicodeEncodeError occurs.
#print u'ハロー'


'''
How to run

python hello.py

'''
