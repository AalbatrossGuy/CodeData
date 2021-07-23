# Coding=UTF8
#! /usr/bin/env python3
# python3

mylist = [x for x in range(0, 20)]


def func(n:tuple):
    if n[0]%2==0:
        return True
    else:
        return False

#print(tuple(filter(func, enumerate(mylist))))


