class counter:

    def __init__(self,initCnt):
        self.cnt = initCnt

    def evolve(self,x):
        self.cnt += x

    def getState(self):
        return self.cnt

#The state of this counter machine is the cnt variable
#cnt(at time n+1)=evolve which addes the values in this case (cnt(at time n),input(at time n))

    
