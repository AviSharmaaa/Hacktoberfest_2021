# This program takes the role of a Cashier figuring out how many minimum coins to give to a customer to make a certain amount of change.
# In US there are 4 main coin denomination.
# 1cent, 5cent, 10 cent, 25  cent.

import math

n = float(input("Change owed: ")) # Taking input for how much amount you want the change. n is in dollars.
n = n * 100 # multiplying it to 100 to convert into cents.
n = round(n) # rounding the value of cents.

count = 0 # count variable will count the number of coins.

# while loop will prompt till user don't give a positive number (n>0)
while (n < 0):
    n = float(input("Change owed: "))
    n = n * 100
    n = round(n)

# if value of n >=25 then this loop will execute.
while (n >= 25):
    n = n - 25
    count += 1

# if value of n >=10 then this loop will execute.
while (n >= 10):
    n = n - 10
    count += 1

# if value of n >=5 then this loop will execute.
while (n >= 5):
    n = n - 5
    count += 1

count += n

print(count) # printing how many coins I have to give for change.

# I/P = Change owed: 1
# O/P = 4

# I/P = Change owed: 0.35
# O/P = 2

# I/P = Change owed: -1
# I/P = Change owed: -0.41
# I/P = Change owed: 0.41
# O/P = 4

# Mohammad Modassir Iqbal
