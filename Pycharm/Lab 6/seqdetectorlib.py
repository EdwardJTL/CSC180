class seqdetector:

    def __init__(self):
        self.match = ["here", "are", "the", "solutions", "to", "the", "next", "exam"]
        self.state = 0


    def evolve(self,word):
        if self.match[self.state] == word:
            self.state += 1
            if self.state == 8:
                self.state = 0
                return True
            else:
                return False
        else:
            if self.match[0] == word:
                self.state = 1
            else:
                self.state = 0
            return False