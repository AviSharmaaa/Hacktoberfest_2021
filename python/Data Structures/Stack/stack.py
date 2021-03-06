# Author : Adwait Patil
# Stack in python
# https://github.com/adwait41001/
class Node:
    def __init__(self,data):
        self.next = None
        self.data = data
class Stack:
    def __init__(self):
        self.head = None
    def printstack(self):
        tmp = self.head
        x =''
        if (tmp):
            while(tmp.next):
                x += str(tmp.data) + '->'
                tmp = tmp.next
            x+=str(tmp.data)
            print(x)
        else:
            print("The stack is empty")
    def push(self,data):
        tmp = self.head
        if tmp:
            while(tmp.next):
                tmp = tmp.next
            tmp.next = Node(data)
        else:
            self.head = Node(data)
            
    def top(self):
        tmp = self.head
        if tmp:
            while(tmp.next):
                tmp = tmp.next
            return tmp.data
        else:
            return "Empty Stack"
            
    def pop(self):
        tmp = self.head
        num = 0
        if tmp:
            if tmp.next:
                while(tmp.next.next):
                    tmp = tmp.next
                num = tmp.next.data
                tmp.next = None
                return num
            else:
                num = self.head.data
                self.head = None
                return num
        else:
            print("Empty Stack")
            return None
            
    def find(self,key):
        tmp = self.head 
        if tmp:
            while(tmp):
                if tmp.data == key :
                    return True
                tmp = tmp.next
        return False
    
    def empty(self):
        if self.head == None:
            return True
        else:
            return False
