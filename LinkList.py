class Node(object):
    def __init__(self,val=0,next=None,prev=None):
        self.__prev=prev
        self.__val=val
        self.__next=next
    def getVal(self):
        return self.__val
    def getNext(self):
        return self.__next
    def getPrev(self):
        return self.__prev
    def setVal(self,val):
        self.__val=val
    def setNext(self,next):
        self.__next=next
    def setPrev(self,prev):
        self.__prev=prev
class Deque(object):
    def __init__(self,val):
        nodo=Node(val)
        self.__head=nodo
        self.__tail=nodo
    def push_back(self,val):
        next=Node(val,None,self.__tail)
        self.__tail.setNext(next)
        self.__tail=self.__tail.getNext()
    def push_front(self,val):
        prev=Node(val,self.__head,None)
        self.__head.setPrev(prev)
        self.__head=prev
    def get_back(self):
        return self.__tail.getVal()
    def get_front(self):
        return self.__head.getVal()
    def pop_back(self):
        self.__tail=self.__tail.getPrev()
        self.__tail.setNext(None)
    def pop_front(self):
        self.__head=self.__head.getNext()
        self.__head.setPrev(None)
prueba=Deque(1)
# 1
print(prueba.get_front())
print(prueba.get_back())
prueba.push_back(2)
# 1 2
print(prueba.get_back())
prueba.push_back(5)
# 1 2 5
print(prueba.get_back())
prueba.push_back(6)
# 1 2 5 6
print(prueba.get_back())
print(prueba.get_front())
prueba.push_front(7)
# 7 1 2 5 6
print(prueba.get_front())
print('#####')
prueba.pop_back()
# 7 1 2 5
print(prueba.get_back())

prueba.pop_front()
# 1 2 5
print(prueba.get_front())

prueba.pop_front()
# 2 5
print(prueba.get_front())