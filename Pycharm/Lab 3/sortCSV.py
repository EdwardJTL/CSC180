import sys

FIN=""
FOUT=""
ColNum = 0
Dir = "+"
nargs=len(sys.argv)
skip=False

# <editor-fold desc="taking in args">
for i in range(1,nargs):
    if not skip:
        arg=sys.argv[i]
        print "INFO: processing",arg
        if arg == "--fin":
            if i != nargs-1:
                FIN=sys.argv[i+1]
                skip=True
        elif arg == "--fout":
            if i != nargs-1:
                FOUT=sys.argv[i+1]
                skip=True
        elif arg == "--col":
            if i!=nargs-1:
                ColNum=int(sys.argv[i+1])
                skip = True
        elif arg == "--dir":
            if i!=nargs-1:
                Dir = sys.argv[i+1]
                skip = True
        else:
            print "ERR: unknown arg:",arg
    else:
        skip=False
# </editor-fold>

f = open(FIN,'r')
lines = f.readlines()
f.close()
data=[]
for i in lines:
    r = []
    j = i.split('\n')[0]
    k = j.split(',')
    for x in k:
        r = r + [float(x)]
    data = data + [r]
try:
    if Dir == "+":
        datas = sorted(data,key=lambda x:x[ColNum])
    if Dir == "-":
        datas = sorted(data,key=lambda x:x[ColNum], reverse=True)
    itemstoprint=[]
    for row in datas:
        item = ""
        for i in range(0,len(row),1):
            if i == 0:
                item = item + str(row[i])
            elif i >= 1:
                item = item + "," + str(row[i])
        itemstoprint.append(item)
except:
    print "illegal arguments"

g = open(FOUT,'w')
g.write('\n'.join(itemstoprint))
g.close()