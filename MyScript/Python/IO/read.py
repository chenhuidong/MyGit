#!/usr/bin/env python
# -*- coding: utf-8 -*-

with open('/home/chenhuidong/MyProgram/MyGithub/MyGit/MyScript/Python/IO/test.txt', 'r') as f:
    #print f.read(3)
    for line in f.readlines():
    	print(line.strip())