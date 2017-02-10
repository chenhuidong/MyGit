#!/usr/bin/env python
# -*- coding: utf-8 -*-

def f(x):
	return x * x

print map(f, [1, 2, 3, 4, 5, 6, 7, 8, 9])

print map(str, [1, 2, 3, 4, 5, 6, 7, 8, 9])

def add(x, y):
	return x + y

print reduce(add, [1, 3, 5, 7, 9])

def fn(x, y):
	return x * 10 + y

reduce(fn, [1, 3, 5, 7, 9])