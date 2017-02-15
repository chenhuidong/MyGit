#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Animal(object):
    def run(self):
        print 'Animal is running...'

class Dog(Animal):
    def run(self):
        print 'Dog is running...'
    def eat(self):
        print 'Eating meat...'

class Cat(Animal):
    def run(self):
        print 'Cat is running...'
    def eat(self):
        print 'Eating fish...'

dog = Dog()
dog.run()

cat = Cat()
cat.run()

def run_twice(animal):
    animal.run()
    animal.run()

run_twice(Dog())