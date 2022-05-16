# x = ("123", 56, 65.4)
# print(type(x))
# print(x)
# print(x.count(56))
# print(x.index(65.4))
# yz = set()

# yz.add(1)

# print(yz)
# print(set(x))

# print(True)

# print(11 <= 1)
# files = open('EXTENSIONS FOR VSC.txt')

# print(files.read())

# file = open("EXTENSIONS FOR VSC.txt")
# files = open("E:\DOWNLOADS\The XceLsior\cmd_IPconfig.txt")
# print(files.read())
# file.close()
# files.close()
# print(file.read())
# file.seek(0)
# print(file.readlines())
# print(file.read())

# reading=file.read()
# print(reading)
# with open("E:\DOWNLOADS\The XceLsior\Python_Learning\python Notes 1.txt", mode="a+") as test :
# print(test.read())
# test.seek(0)
# print(test.read())
# test.write("Hello ma friends")
# test.seek(0)
# print(test.read())
# print("Hello users. Whatever numbers you give will be solved by using this formula:- (x + y)(x - y)")
# x = input("Enter a value for 'x'\n> ")
# y = input("Enter a value for 'y'\n> ")

# def equation(x, y):
# x = int(x)
# y = int(y)

# yo = [56, 88, 100, 200]
# lst = [x for x in yo]
# print((lst))

# def check_even(nums):
# return nums%2==0


# my = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# print(list(filter(check_even, my)))


# import os, time
# my_time = time.asctime(time.localtime())
# print(os.getcwd())
# print(os.listdir())
# os.makedirs("Wallah-Just-A-Test/Sub-dir-101") This Is an Example!!!
# print(os.stat("lalalla 2.jpg")) This Is an Example!!!
# print(os.environ.get("The industrial revolution viii.pdf")) For Printing out your environment variable.
# print(list(map(lambda x: x ** 3, my_list)))
# class Dog:
#     def __init__(self, breed):
#         self.mybreed = breed
#
#
# my_dog = Dog(breed="Rottweiler")
# print(my_dog.mybreed)

# class Dog():
#
#     def __init__(self, breed, name):
#         self.breed = breed
#         self.name = name
#
#     def wallahBark(self):
#         print("Wallah! Habibi! My name is {}".format(self.name))
#         return ""
#
#
# my_dog = Dog("rottweiler", "Sinjan")
# print(my_dog.wallahBark())

# class Wallah():
#     def __init__(self, food, toppings, salad=False):
#         self.food = food
#         self.toppings = toppings
#         self.salad = salad
#
#     def __str__(self):
#         return f'The food you ordered is {self.food}'
#                                                               This Is An Example Of Magic/Dunder Methods
#     def __bool__(self):
#         return self.salad
#
#     def __del__(self):
#         return f'Food Order, {self.food} has been cleared!'
#
#
# my_food = Wallah('Biryani', 'Tangri kabab', salad=False)



# def hola_ppl(originalword):
#     def some():
#         print("hello!")
#         originalword()
#         print("line end")
#     return some
#                                                       Example of decorators in python.
#
# @hola_ppl
# def meow():
#     print('test run')
#
# meow()


# from collections import Counter
# lolua = [1, 2, 1, 3, 2, 3, 5, 4, 5, 3, 1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9]
#
# count_keeps = Counter(lolua)
# # prints the most common words/floating numbers/integers as a dictionary.
# print(count_keeps)
# # Shows the most common repeated set as a tuple
# print(count_keeps.most_common())
# # prints the required set of the most-commons
# print(count_keeps.most_common(2))
# # prints only the keys of the most common values in the dictionary respective
# print(list(count_keeps))


# import os
# import shutil # similar to the os module but is used for high level operations with files like copying moving etc.
# os.getcwd()  # prints the current working directory
# os.listdir()  # prints the directories present
# os.listdir('/home/user/Miscs')  # prints the directories present in the given path
# shutil.move('TCP_Connectivity_data.txt', '/home/user/Miscs/The_XceLsior') # moves a file into another directory...the first parameter should be of the file to be moved and the second parameter should be of the destination.
#
# # Three Ways To Delete A File
# # Number 1 :
# os.unlink(path) # deletes the file at the path provided.
# # Number 2
# os.rmdir(path) # deletes a folder at the path provided....the folder must be empty....
# # Number 3
# shutil.rmtree(path) # this is the most dangerous as it will remove all files and folders contained in the path...
#
# # WARNING!!!!!!!! ALL OF THESE METHODS CANNOT BE REVERSED....SO IF A FILE IS BEEN DELETED ONCE, IT CANNOT BE
# # RECOVERED AGAIN.

# import math
# import random
#
# value = 4.35
# math.floor(value)  # returns the integer version of the decimal value
# round(4.35)  # rounds of the value....built-in with python..
# random.randint(0, 100)  # returns some random integer between the two specified values
# random.seed(101)
# random.randint(0, 100)  # returns a same number again and again...can only be changed if random.seed(any value) is
# # written again.
#
# mylist = list(range(0, 20))
# random.choice(mylist)  # chooses a random number every time run-ed from the given list.
# random.choices(population=mylist, k=15)  # chooses 15 set of random numbers from the given list and returns a list
# # value. This is sample with replacement...so there can be a possibility of one number getting repeated twice.
# random.sample(population=mylist, k=10)  # returns a list of random number in the range of 10(k)...This is a sample
# # without replacement...hence there can be no chances of a number getting repeated twice.
# random.shuffle(mylist)  # shuffles the number inside the given argument(list/tuple) and shows the list...this change #
# # ## is permanent hence no need of assigning it to a variable.
#
# random.uniform(a=10, b=20)  # chooses any random number between a and b....can be a floating point value.

#import re

# pattern = r'\d{3}-\d{3}-\d{4}'
#
# text = 'my phone number is 123-456-7891'    prints out the required argument, i.e, pattern in this case.
#
# print(re.findall(pattern, text))

# from PIL import Image       # Imports the image module from teh pillow package
#
# var = Image.open('maybe_3.jpg') # Opens teh image but DOES NOT shows it
# print(var.show())     # Shows the image
#
# print(var.size)       # shows teh picture size
# print(var.format_description) # shows more info about the image.


# import PyPDF2                             module for working with pdf's
# file = open('A Sample PDF.pdf', mode='rb')  opens the designated file (rb = read binary)
# read = PyPDF2.PdfFileReader(file)             reads through it
# read = read.getPage(0)                    reads the page which has been given as the index position
# read = read.extractText()                 extracts the text
# print(read)                               prints it.

import psutil
from pypresence import Presence
import time

client_id = '676414187131371520'  # Fake ID, put your real one here
RPC = Presence(client_id,pipe=0)  # Initialize the client class
RPC.connect() # Start the handshake loop


while True:  # The presence will stay on as long as the program is running
    cpu_per = round(psutil.cpu_percent(),1) # Get CPU Usage
    mem = psutil.virtual_memory()
    mem_per = round(psutil.virtual_memory().percent,1)
    print(RPC.update(details="RAM: "+str(mem_per)+"%", state="CPU: "+str(cpu_per)+"%"))  # Set the presence
    time.sleep(15) # Can only update rich presence every 15 seconds