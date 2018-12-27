class stack:
    def __init__(self):
        self.values = []

    def push(self,x):
        self.values = self.values +[x]

    def disp(self):
        for i in range(0, len(self.values)):
            print self.values[i]

    def pop(self):
        try:
            output = self.values[len(self.values)-1]
            self.values = self.values[0:len(self.values)-1]
            return output;
        except IndexError:
            return False
