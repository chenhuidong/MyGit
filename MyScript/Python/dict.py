#!/usr/bin/env python
# -*- coding: utf-8 -*-

d = {'Mich':95, 'Bob':75, 'Tracy':50}
print d['Mich']

d['Adam'] = 67
print d

print 'Adam' in d

print d.get('Bob')
print d.get('Bob1',-1)

s = set([1,2,3])
print s

s.add(4)
print s

s.remove(3)
print s