#!/usr/bin/env python
# -*- coding: utf-8 -*-

sorted([36, 5, 12, 9, 21])

def reversed_cmp(x, y):
    if x > y:
        return -1
    if x < y:
        return 1
    return 0

sorted([36, 5, 12, 9, 21], reversed_cmp)
sorted(['bob', 'about', 'Zoo', 'Credit'])