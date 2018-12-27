printdata=""
datas=[[3,4,5],[1,2,3],[4,5,6]]
itemstoprint=[]
for row in datas:
    item = ""
    for i in range(0,len(row),1):
        if i == 0:
            item = item + str(row[i])
        elif i >= 1:
            item = item + "," + str(row[i])
    itemstoprint.append(item)
print itemstoprint