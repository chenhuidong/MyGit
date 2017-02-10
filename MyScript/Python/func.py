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

def nop():
	pass

def add_end(L=None):
    if L is None:
        L = []
    L.append('END')
    return L

def calc(*numbers):
    sum = 0
    for n in numbers:
        sum = sum + n * n
    return sum

nums = [1, 2, 3]
print calc(*nums)

def func(a, b, c=0, *args, **kw):
    print 'a =', a, 'b =', b, 'c =', c, 'args =', args, 'kw =', kw
func(1, 2)
func(1, 2, c=3)
func(1, 2, 3, 'a', 'b')
func(1, 2, 3, 'a', 'b', x=99)   

args = (1, 2, 3, 4)
kw = {'x': 99}
func(*args, **kw)

def fact(n):
    if n==1:
        return 1
    return n * fact(n - 1)
fact(5)


def fact1(n):
    return fact_iter(n, 1)

def fact_iter(num, product):
    if num == 1:
        return product
    return fact_iter(num - 1, num * product)