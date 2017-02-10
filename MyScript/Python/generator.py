#!/usr/bin/env python
# -*- coding: utf-8 -*-

g = (x * x for x in range(10))
g.next()

for n in g:
	print n

def fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b
        a, b = b, a + b
        n = n + 1

g = fib(6)
for n in g:
	print n