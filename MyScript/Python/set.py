#!/usr/bin/env python
# -*- coding: utf-8 -*-

s = set([1,2,3])
print s

s.add(4)
print s

s.remove(3)
print s

s1 = set([1,2,3])
s2 = set([2,3,4])
s3 = s1&s2
print s3
