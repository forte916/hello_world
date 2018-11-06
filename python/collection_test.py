#!/bin/python3
# -*- coding: utf-8 -*-
# vim:fenc=utf-8


#### tuple
t = ()
t = tuple()


#### list
l = []
l = list()

l.append('apple')
l.append('banana')
l.append('cherry')
print(l)
l.insert(0, 'orange')
print(l)
l.remove('cherry') # Delete by value
print(l)
del l[2]           # Delete by index
print(l)
#l.remove('grape')  # ValueError
#print(l)


#### dict
d = {}
d = dict()

d[19] = 'KitKat'
d[21] = 'Lollipop'
d[23] = 'Marshmallow'
d[24] = 'Nougat'
d[26] = 'Oreo'
d[28] = 'Pie'
print(d)
del d[19]
print(d)


### set
s = {}  # NG!! This means dict
s = set()

