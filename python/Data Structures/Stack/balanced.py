# Author : Adwait Patil
# Stack in python
# https://github.com/adwait41001/
from stack import Stack
def IsBalanced(s):
    """Check if the brackets in a string s are balanced.
    """
    x = Stack()
    braces = ['[','(','{']
    closeBraces = [']',')','}']
    for char in s:
        if char in braces:
            x.push(char)
        elif char in closeBraces:
            if x.empty():
                return False
            top = x.pop()
            if((top == '[' and char != ']') | (top == '(' and char != ')') | (top == '{' and char != '}')):
                return False
    return x.empty()
