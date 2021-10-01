import random

data = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-=.,</>"
amount = input("Please input the amount of password to generate: ")
amount = int(amount)

pwlength = input("Please input the length of password: ")
pwlength = int(pwlength)

print("\n\nHere are the passwords:")

for i in range(amount):
    pw = ''
    for j in range(pwlength):
        pw += random.choice(data)
    print(pw)