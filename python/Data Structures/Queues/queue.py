class Node:
    def __init__(self,data):
        self.next = None
        self.data = data
class Queue:
    def __init__(self):
        self.head = None
    def printQueue(self):
        tmp = self.head
        x =''
        if (tmp):
            while(tmp.next):
                x += str(tmp.data) + '->'
                tmp = tmp.next
            x+=str(tmp.data)
            print(x)
        else:
            print("The queue is empty")
    
    def enqueue(self,data):
        tmp = self.head
        if tmp:
            tmp2 = Node(data)
            tmp2.next = tmp
            self.head = tmp2
        else:
            self.head = Node(data)
            
    
    def dequeue(self):
        tmp = self.head
        if tmp:
            if tmp.next:
                while(tmp.next.next):
                    tmp = tmp.next
                a = tmp.data
                tmp.next = None
                return a
            else:
                a = self.head.data
                self.head = None
                return a
        else:
            print("Empty Stack")
            return None
            
    
    
    def empty(self):
        if self.head == None:
            return True
        else:
            return False
    
    
            
def convertArrayToQueue(arr):
    arrQueue = Queue()
    for i in arr:
        arrQueue.enqueue(i)
    return arrQueue
