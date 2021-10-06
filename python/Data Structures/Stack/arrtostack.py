# Author : Adwait Patil
# Stack in python
# https://github.com/adwait41001/
from stack import Stack
def convertArrayToStack(arr):
    arrStack = Stack()
    for i in range(len(arr)):
        arrStack.push(arr[0-i-1])
    return arrStack
