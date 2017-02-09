#!/usr/bin/env python
# -*- coding: utf-8 -*-

print abs(-20)
print cmp(1,2)
print int('123')
print str(123)
bool(1)
bool('')

def my_abs(x):
	if x>=0:
		return x
	else:
		return -x

print my_abs(-30)