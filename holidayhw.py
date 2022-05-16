# Coding=UTF8
#! /usr/bin/env python3
# python3

import cmath, math

# Problem 1

def convert_day(day: int) -> str:

    assert isinstance(day, int), "Number of days should be in integer format."

    year, month, week = int(day/365), int(day/30), int(day/7)
    return f"{year} years {month} months and {week} weeks"

# Problem 2
def check_isNested(num: int) -> str:

    assert isinstance(num, int) and len(str(num)) == 3, "Number should be in three digit integer format only."

    num = "The number is a 3 digit even number" if num%2==0 else "The number is a 3 digit odd number"
    return num


# Problem 3
def monthName(mnum: int) -> str:

    assert isinstance(mnum, int), "Number should be in integer format."

    # Way 1 (The school preferred way)
    match mnum:
        case 1:
            return "January"
        case 2:
            return "February"
        case 3:
            return "March"
        case 4:
            return "April"
        case 5:
            return "May"
        case 6:
            return "June"
        case 7:
            return "July"
        case 8:
            return "August"
        case 9:
            return "September"
        case 10:
            return "October"
        case 11:
            return "November"
        case 12:
            return "December"

    # Way 2 is to make a dictionary and do a key-value in a "month_number" : "month_name" format and then just call the value :/

# Problem 4
def quadratic_equation(a: int, b: int, c: int):

    assert isinstance(a, int) and isinstance(b, int) and isinstance(c, int), "Number should be in integer format."

    # Way 1 : Using the cmath library....idk if it's in java or not :/
    a = 16
    b = -40
    c = 9
    d = (b**2) - (4*a*c)
    sol = f"{-b-cmath.sqrt(d)/(2*a)}, {-b+cmath.sqrt(d)/(2*a)}"


    # Way 2 : Using just the math library.
    sqrt_val = math.sqrt(abs(d))
    sol2 = f"{-b+sqrt_val/(2*a)}, {-b-sqrt_val/(2*a)}"
    return sol

#Problem 5
def lcm_gcd(num1: int, num2: int) -> str:

    assert isinstance(num1, int) and isinstance(num2, int), "Numbers should be in integer format."

    def calculate_lcm(x, y):
        if x > y: greater = x
        else: greater = y
        while True:
            if greater%x==0 and greater%y == 0:
                lcm = greater
                break
            greater += 1
        return lcm

    def calculate_gcd(a, b):
        prod, lcm = a*b, calculate_lcm(a, b)
        return int(prod/lcm)

    return f"The L.C.M of {num1} and {num2} is {calculate_lcm(num1, num2)} and their G.C.D is {calculate_gcd(num1, num2)}"

# print(convert_day(100.99))
