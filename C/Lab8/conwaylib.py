from random import randint
class conway:
    def __init__(self, num_lists, num_elements, values):
        self.storage = []
        for i in range(0, num_lists, 1):
            self.storage.append([])
        if values == 'zeros':
            for i in range(0, num_lists, 1):
                for k in range(0, num_elements, 1):
                    self.storage[i].append(0)
        if values == 'random':
            for i in range(0, num_lists, 1):
                for k in range(0, num_elements, 1):
                    new_value = randint(0,1)
                    self.storage[i].append(new_value)

    def getDisp(self):
        long_list = []
        for i in range(0, len(self.storage),1):
            row = ''
            for k in range(0, len(self.storage[i]), 1):
                if self.storage[i][k] == 0:
                    row += ' '
                elif self.storage[i][k] == 1:
                    row += '*'
            long_list.append(row)
        return_string = '\n'.join(long_list)
        return_string += '\n'
        return return_string

    def printDisp(self):
        print self.getDisp()
        return True

    def setPos(self, row, col, val):
        if val not in [0, 1]:
            return False
        else:
            self.storage[row][col] = val
            return True

    def getNeighbours(self, row, col):
        endrow = len(self.storage)-1
        endcol = len(self.storage[0])-1
        if row > endrow or col > endcol:
            return False
        if col == 0:
            cols = [endcol, col, col+1, endcol, col+1, endcol, col, col+1]
        if col == endcol:
            cols = [col-1, col, 0, col-1, 0, col-1, col, 0]
        if col not in [0,endcol]:
            cols = [col-1, col, col+1, col-1, col+1, col-1, col, col+1]
        if row == 0:
            rows = [endrow, endrow, endrow, row, row, row+1, row+1, row+1]
        if row == endrow:
            rows = [row-1, row-1, row-1, row, row, 0, 0, 0]
        if row not in [0,endrow]:
            rows = [row-1, row-1, row-1, row, row, row+1, row+1, row+1]
        return_list = []
        for i in range(0,8,1):
            element = self.storage[rows[i]][cols[i]]
            return_list.append(element)
        return return_list
