#!/usr/bin/env python
# -*- coding: utf-8 -*-

d = {'a': 1, 'b': 2, 'c': 3}
for key in d:
	print key , d.get(key)

for k, v in d.iteritems():
	print k, '=', v

print [k + '=' + v for k, v in d.iteritems()]

L = ['Hello', 'World', 'IBM', 'Apple']
print [s.lower() for s in L]