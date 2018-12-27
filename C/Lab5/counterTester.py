#Python stores the function definition somewhere such that it can be called later
#You call a function using its name and the appropriate arguments
#Python stores the class definition somewhere such that instances of the object can be created
#you create an object as an instance of the class by object=classname(arguments)
from counterlib import counter

myCnt = counter(100)
for i in range(10,160,15):
    myCnt.evolve(i)
    print myCnt.getState()
