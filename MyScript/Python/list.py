#!/usr/bin/env python
# -*- coding: utf-8 -*-

classmates = ['Michael', 'Bob', 'Tracy']
print classmates 
print classmates[0]
print len(classmates)
print classmates[-1]
classmates.append('Adam')
classmates.insert(1, 'Jack')
print classmates 
classmates.pop()
print classmates 
classmates.pop(1)
print classmates


L = ['Apple', 123, True]
print L

s = ['python', 'java', ['asp', 'php'], 'scheme']
print s
print len(s)

print range(1, 11)
print [x * x for x in range(1, 11)]
print [m + n for m in 'ABC' for n in 'XYZ']

import os
print [d for d in os.listdir('.')]