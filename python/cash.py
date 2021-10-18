import math

n = float(input("Change owed: "))
n = n * 100
n = round(n)

count = 0

while (n < 0):
    n = float(input("Change owed: "))
    n = n * 100
    n = round(n)

while (n >= 25):
    n = n - 25
    count += 1

while (n >= 10):
    n = n - 10
    count += 1

while (n >= 5):
    n = n - 5
    count += 1

count += n

print(count)
