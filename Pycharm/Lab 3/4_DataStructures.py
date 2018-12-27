import random
import string

def isPrime(x):
    r = True
    for i in range(2,x):
        if (x%i==0):
            r = False
            break
    return r

def genPrime(min,max):
    while True:
        x=random.randint(min,max)
        if isPrime(x):
            break
    return x

n = 0
accum = []
while (n<10):
    x = genPrime(1,1024)
    y = genPrime(1,1024)
    pair = (x,y)
    if not pair in accum:
        accum.append(pair)
        n +=1

n = 0
accum
while (n<10):
    print accum[n][0]*accum[n][1]
    n+=1

RollingStonesAlbums = [ ["Beggars Banquet", 1968],["Let It Bleed", 1969],["Sticky Fingers", 1971]]

for x in RollingStonesAlbums:
    print "The Rolling Stones released "+x[0]+" in "+str(x[1])
RollingStonesAlbums.append(["It's Only Rock'n'Roll", 1971])
print RollingStonesAlbums

RollingStonesAlbums_lot=[ ("Beggars Banquet", 1968),
                       ("Let It Bleed", 1969),
                       ("Sticky Fingers", 1971),
                       ("Exile on Main Street", 1972) ]
Albums=["Beggars Banquet", "Let It Bleed", "Sticky Fingers", "Exile on Main Street"]
Released=[1968,1969,1971,1972]
RollingStonesAlbums_zip =zip(Albums, Released)

print RollingStonesAlbums_lot
print RollingStonesAlbums_zip

for x in RollingStonesAlbums_zip:
    print "The Rolling Stones released "+x[0]+" in "+str(x[1])

def randomword(length):
    return ''.join(random.choice(string.lowercase) for i in range(length))

xCoord = range(1,10)
yCoord = []

for i in xCoord:
    yCoord.append(random.randint(-100,-1))

label=[]
for i in xCoord:
    label.append(randomword(10))

aggr=zip(xCoord,yCoord,label)
print aggr

def process(x):
    print "sensor "+str(x[0])+" "+x[2]+" respond measurement "+str(x[1])
    return True
map(process,aggr)
print sorted(aggr)
print sorted(aggr, key=lambda x:x[1], reverse=True)