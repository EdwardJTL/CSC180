def add(x,y):
    return x+y
while True:
    try:
        endTerm = int(raw_input("End the number of terms:"))
        break
    except ValueError or TypeError:
        print "try again"
switches = [0]
for i in range(0,endTerm+1,1):
    if endTerm-reduce(add,switches) >= i and len(switches)>=1:
        switches.append(i)
    else:
        lastTerm = endTerm - reduce(add, switches)
        if lastTerm > 0 and lastTerm <= i:
            switches.append(lastTerm)
            break
switches = switches[2:len(switches)]

sum = 0
term = 1
termL = []
for i in range(0,len(switches),1):
    if i%2 == 1:
        for num in range(0,switches[i],1):
            termL.append(term)
            term +=1
    if i%2 == 0:
        for num in range(0,switches[i],1):
            termL.append(-1*term)
            term +=1
sum = reduce(add,termL)
print sum