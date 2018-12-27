def sumSequence(n):
    count = 1
    sum = 0
    for i in range (1,n+1,1):
        if (i==(count*count)+1):
            for m in range(i,i+count,1):
                sum = sum - m
                count = count +1
        else:
             sum = sum +i
    return sum


for i in range(1,10,1):
    print sumSequence(i)