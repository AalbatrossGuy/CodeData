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

mystring = """Im happy Today
Im glad today

Hello
Goodmorning

Hi
Goodnight

Good

What's up
Hello"""


lst = mystring.replace('\n', '')

x = "\n".join(["".join(lst[i:i+5]) for i in range(0,len(lst),5)])
print(x)
