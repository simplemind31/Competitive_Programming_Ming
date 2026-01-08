state_capitals = {
 'Arkansas': 'Little Rock',
 'Colorado': 'Denver',
 'California': 'Sacramento',
 'Georgia': 'Atlanta'
}

l=list(state_capitals)
my_list = [-7,3,2,1,0,'b','a']
my_set = set(my_list)
#print(state_capitals.get('a'))
#print(state_capitals.get('a'))
state_capitals['a']=0
#print(state_capitals.get('a'))
#print(state_capitals)
"""
x=input()
print(x)
"""
import math
import collections
stat = collections.defaultdict(lambda: 'Boston')
x=math.__doc__
#print(x)
x='dcaaa'
s="""holaaaa"""
import datetime
today=datetime.datetime.now()
a_str='Hello World'

int_num=10 #int value
float_num=10.2 #float value
complex_num=1+0j #complex value
complex_num1=2+0j
complex_num=complex_num/complex_num1
list1 = ['hello']
sett=set('holaav')
#print(sett)
"""
print(list) #will output whole list. [123,'abcd',10.2,'d']
print(list[1:3]) #will output first two element of list. [123,'abcd']
print(list1 * 2) #will gave list1 two times. ['hello','world','hello','world']
print(list + 2*list1) #will gave concatenation of both the lists.
[123,'abcd',10.2,'d','hello','world']
"""
dic={'name':'red','age':10}

nue=list(dic.values())
dt = datetime.datetime.strptime("2016-04-15T08:27:18-0500", "%Y-%m-%dT%H:%M:%S%z")
"""
from enum import Enum
class Color(Enum):
 red = 1
 green = "ade"
 blue = 3
 yellow = 2
print(Color.blue) # Color.red
print(Color("ade")) # Color.red
print(Color['red']) # Color.red
print([c for c in Color])
"""
a=3
b=2
(x,y,z)=[4,5,6]
x=3
str="string"
import os
_, extension = os.path.splitext("esvrmk ewfw.vsrrv d")
'''
for i in extension:
    print(i)
print(_)
print(extension)
'''
ttt=[w.split('-') for w in ['ape', 'ape-man efs wefwc+fesv', 'hand-me-down']]
tttt=[x**2 if x%3!=0 else 7 for x in range(10, 21)]
ssss=[x**2 for x in range(10, 21) if x%3!=0]
#print(tttt)
#print(ssss)
"""
class Power(object):
    #A class that computes a specific power of other numbers.
    #In other words, it raises numbers by a constant exponent.
    default_exponent = 2
    def __init__(self, exponent=default_exponent):
        self.exponent = exponent
    def of(self, x):
        return x ** self.exponent
class RealPower(Power): # A subclass of Power for real numbers
    def of(self, x):
        if isinstance(self.exponent, int) or x >= 0:
            return x ** self.exponent
        raise ValueError('Fractional powers of negative numbers are imaginary')
print('Power:', Power)
print('Power.default_exponent:', Power.default_exponent)
square = Power()
root = Power(0.5)
print('square: ', square)
print('square.of(3) =', square.of(3))
print('root.of(3) =', root.of(3))
print('root.of(-3) =', root.of(-3))
real_root = RealPower(0.5)
print('real_root.of(3) =', real_root.of(3))
print('real_root.of(-3) =', real_root.of(-3))
print('Done.')
"""
"""
1-A Write a Python list comprehension that returns the individual characters of a string
that are not whitespace characters. Apply it to the string "4 and 20 blackbirds.\n"
"""
xxxx=[i for i in "4 and 20 blackbirds.\n" if(i!=' ' and i!='\n')]
#print(xxxx)

for i in range(8,-1,-1):
    pass
import random
import timeit
xdd=1e9+7
random.seed(xdd) # Set random number generator
arr=[]
for i in range(10):
    arr.append(random.randrange(10000)) # Insert random numbers
#print(arr)
c='A'
res=ord(c)
#res=65
a=65
res=chr(a)
#res=A
def counter():
    num = 0
    def incrementer():
        nonlocal num
        num += 1
        return num
    return incrementer
"""
c=counter()
print(c())
#c=1
print(c())
#c=2
print(counter()())
#1
"""
numeee=5
def fffffff():
    global numeee
    numeee+=1
    return numeee
#print(fffffff())
"""
num=70
def counter():
    global num
    print(num)
    del num
    def incrementer():
        return num+100
    return incrementer
counter()
print(num)
"""
#print(counter()())
xddddd=20
def foo():
    if True:
        xddddd = 5
    print(xddddd) # ok
"""
b=3
def bar():
    print(b) # UnboundLocalError: local variable 'b' referenced before assignment
    if 6<1:
        b = 5
bar()
"""
foo = 1
def func():
    foo = 2 # creates a new variable foo in local scope, global foo is not affected
    print(foo) # prints 2
    # global variable foo still exists, unchanged:
    print(globals()['foo']) # prints 1
    print(locals()['foo']) # prints 2
import random

#print(random.randrange(1, 10))
age = 36
txt = f"My name is John, I am {age}"
#print(txt)
txt = "Hello\rWorld!"
#This example erases one character (backspace):
txt = "Hello \bWorld!"
txt = "HelLo World!"
y=txt.center(20,'-')
txt= "eStO eS. uNa? Prueba"
txt2="aaaaaaa"
#print(txt2.count('a',0,1))
#print((8==8)==8)
thislist = ["apple", "banana", "cherry"]
#print([print(x) for x in thislist])
thislist = ["orange", "mango", "kiwi", "pineapple", "banana"]
thislist.sort(reverse = True)
#print(thislist)
def myfunc(a):
  return -a

thislist = [100, 50, 65, 82, 23,-3]
thislist.sort(key = myfunc)
#print(thislist)
thislist = ["banana", "Orange", "Kiwi", "cherry"]
thislist.reverse()
#print(thislist)
thistuple = ("apple", "banana", "cherry")
y = ("orange","")
th=thistuple+ y

fruits = ("apple", "banana", "cherry", "strawberry", "raspberry")

(green, *yellow, red) = fruits
"""
print(green)
print(yellow)
print(red)
"""
car = {
"brand": "Ford",
"model": "Mustang",
"year": 1964
}

x = car.items()

#print(x) #before the change

car["color"] = "white"

#print(x) #after the change
i = 1
while i < 6:
    break
    print(i)
    i += 1
else:
    print("i is no longer less than 6")
def my_function(greeting,*names):
  for name in names:
    print(greeting, name)

#my_function("Hello", "Emil", "Tobias", "Linus")
def changecase(func):
    def myinner():
        return func().upper()
    return myinner
#myfunction=changecase(myfunction)
#so the return must be a function and not a string 
@changecase
def myfunction():
  return "Hello Sally"
#print(myfunction.__name__)
#print(myfunction())
def myfunction():
  return "Have a great day!"

#print(myfunction.__name__)
x={
    1:2,
    2:4,
    3:6,
    4:8
}
y=list(x)
#print(y)
numbers = [1, 2, 3, 4, 5]
doubled = list(map(lambda x: x * 2, numbers))
import sys
sys.setrecursionlimit(2000)
#print(sys.getrecursionlimit())
#default number of recursion 1000
def count_up_to(n):
  count = 1
  while count <= n:
    yield count
    count += 1
"""
for num in count_up_to(5):
  print(num)
"""
def fun():
    yield "A"
    yield "B"
    yield "C"
f = fun()
#print(next(f))
#print(next(f))# List comprehension - creates a list
list_comp = [x * x for x in range(5)]
#print(list_comp)

# Generator expression - creates a generator
gen_exp = (x * x for x in range(5))
#print(gen_exp)
#print(list(gen_exp))
#print(list(range(5)))
#print(list(range(1, 6)))
#print(list(range(5, 20, 3)))
class MyNumbers:
  def __iter__(self):
    self.a = 1
    return self

  def __next__(self):
    x = self.a
    self.a += 1
    return x

myclass = MyNumbers()
myiter = iter(myclass)
"""
print(next(myiter))
print(next(myiter))
print(next(myiter))
print(next(myiter))
print(next(myiter))
"""
class MyNumbers:
  def __iter__(self):
    self.a = 1
    return self

  def __next__(self):
    if self.a <= 20:
      x = self.a
      self.a += 1
      return x
    else:
      raise StopIteration

myclass = MyNumbers()
myiter = iter(myclass)
"""
for x in myiter:
  print(x)
"""
"""
say that I have a python file called mymodule
import mymodule as mx

then it is mx
a = mx.person1["age"]
print(a)
"""
import platform

x = dir(platform)
#print(x)
import platform

x = platform.system()
#print(x)
import datetime
x=datetime.datetime.now()
#print(x)
import datetime

x = datetime.datetime.now()
"""
print(x.year)
print(x.strftime("%A"))
"""
x=datetime.datetime(2020, 5, 17,1,1,1)

#print(x)
import re

txt = "The rain in Spain bbn!·%&//23034930608froemvmRTYGHBJNJ "

#Check if the string has any a, r, n or T characters:

x = re.findall("[arnT]", txt)
x = re.findall("[a-bm-ne-f]", txt)
#between a and b, m and n, e and f
x = re.findall("[^arn]", txt) #no arn
x = re.findall("[0-5][0-3]", txt)
#print(x)
x=re.findall("[a-b][b-o][n]",txt)
import camelcase
c = camelcase.CamelCase()

txt = "hello world"

#print(c.hump(txt))
"""
x = -1

if x < 0:
  raise Exception("Sorry, no numbers below zero")
"""
import cowsay
#print(dir(cowsay))
#cowsay.pig("Good Mooooorning!")
"""
class Person:
  def __init__(self, name):
    self.name = name

  def greet(self):
    return "Hello, " + self.name

  def welcome(self):
    message=self.greet()
    print(message + "! Welcome to our website.")

p1 = Person("Tobias")
p1.welcome()
"""
"""
class Person:
  lastname = ""

  def __init__(self, name):
    self.name = name

p1 = Person("Linus")
p2 = Person("Emil")

Person.lastname = "Refsnes"

print(p1.lastname)
print(p2.lastname)
p1.lastname='xxx'
print(p1.lastname)
print(p2.lastname)
Person.lastname = "ddd"
print(p1.lastname)
print(p2.lastname)
"""
class Vehicle:
  def __init__(self, brand, model):
    self.brand = brand
    self.model = model

  def move(self):
    print("Move!")

class Car(Vehicle):
  pass

class Boat(Vehicle):
  def move(self):
    print("Sail!")

class Plane(Vehicle):
  def move(self):
    print("Fly!")

car1 = Car("Ford", "Mustang") #Create a Car object
boat1 = Boat("Ibiza", "Touring 20") #Create a Boat object
plane1 = Plane("Boeing", "747") #Create a Plane object
"""
for x in (car1, boat1, plane1):
  print(x.brand)
  print(x.model)
  x.move()
"""
x=open("t1.in")
f=x.readline()
#print(f[0])
y=x.read()
#print(y)

x.close()
x=open("t1.out","w")
x.write("sfwv324")
x.close()
