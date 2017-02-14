#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
def lazy_sum(*args):
    def sum():
        ax = 0
        for n in args:
            ax = ax + n
        return ax
    return sum

f = lazy_sum(1, 3, 5, 7, 9)

print f
print f()
'''

def count():
	fs = []
	for i in range(1, 4):
		def f(j):
			def g():
				return j*j
			return g
		fs.append(f(i))
	return fs

f1, f2, f3 = count()
print f1()
print f2()
print f3()