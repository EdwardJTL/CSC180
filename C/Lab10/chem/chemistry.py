class atom:
    def __init__(self, atomicNum):
        self.atomicNumber = atomicNum
        self.bondList = []

    def addBond(self, bs, atm):
        bondNode = [bs, atm]
        self.bondList.append(bondNode)

    def printAtom(self, n):
        blank = ""
        for i in range(0, n):
            blank += "   "
        print '%s-> atomic number=%d: bonded to:' % (blank, self.atomicNumber)
        self.printBonds(n)
        print '%s<- atomic number=%d' % (blank, self.atomicNumber)

    def printBonds(self, n):
        blank = ""
        for i in range(0, n):
            blank += "   "
        size = len(self.bondList)
        if size == 0:
            print '%sno bonds' % blank
        else:
            for i in range(0, size):
                print '%sstrength=%d connected to:' % (blank, self.bondList[i][0])
                self.bondList[i][1].printAtom(n+1)
            print '%sno bonds' % blank

    def printStructure(self):
        self.printAtom(0)

    def genFormula(self):
        formula = ""
        elementList = []
        BLSize = len(self.bondList)
        elementList.append(self.atomicNumber)
        elementList.append(1)
        for i in range(0, BLSize, 1):
            rString = self.bondList[i][1].genFormula()
            rList = []
            while len(rString)!=0:
                id = rString.find('_')
                if id != -1:
                    rList.append(int(rString[:id]))
                    rString = rString[id+1:]
                else:
                    rList.append(int(rString))
                    break
            for k in range(0, len(rList)-1, 2):
                added = False
                for l in range(0, len(elementList)-1, 2):
                    if rList[k] == elementList[l]:
                        elementList[l+1] += rList[k+1]
                        added = True
                if not added:
                    elementList.append(rList[k])
                    elementList.append(rList[k+1])
        n = len(elementList)
        swapping = True
        while swapping == True:
            swapped = False
            for i in range(0,n-2,2):
                if elementList[i]>elementList[i+2]:
                    temp1 = elementList[i]
                    temp2 = elementList[i+1]
                    elementList[i] = elementList[i+2]
                    elementList[i+1] = elementList[i+3]
                    elementList[i+2] = temp1
                    elementList[i+3] = temp2
                    swapped = True
            if not swapped:
                swapping = False
        formula='_'.join(map(str,elementList))
        return formula
