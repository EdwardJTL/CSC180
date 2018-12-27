from random import randint


class ttt:
    def __init__(self):
        self.board = [0, 0, 0, 0, 0, 0, 0, 0, 0]

    def checkTList(self):
        try:
            for i in self.board:
                if i not in (0,1,2):
                    return False
            else:
                return True
        except:
            return False

    def printBoard(self):
        gameboard = []
        if self.checkTList() is False:
            return False
        else:
            try:
                for i in range(0, 9, 1):
                    if self.board[i] == 0:
                        gameboard.append(i)
                    elif self.board[i] == 1:
                        gameboard.append("X")
                    elif self.board[i] == 2:
                        gameboard.append("O")
                row1 = " " + str(gameboard[0]) + " | " + str(gameboard[1]) + " | " + str(gameboard[2])
                row2 = " " + str(gameboard[3]) + " | " + str(gameboard[4]) + " | " + str(gameboard[5])
                row3 = " " + str(gameboard[6]) + " | " + str(gameboard[7]) + " | " + str(gameboard[8])
                line_separator = "---|---|---"
                for i in [row1, line_separator, row2, line_separator, row3]:
                    print i
                return True
            except:
                return False

    def get_move(self):
        allowInput = True
        while allowInput:
            userInput = raw_input("Please choose a square: ")
            try:
                choice = int(userInput)
                if choice not in range(0, 9, 1):
                    print "Please enter a number displayed on the board."
                elif self.board[choice] != 0:
                    print "Please enter the number of an available square."
                else:
                    return choice
            except ValueError:
                print "Please enter only the number of your desired square."

    def analyzeBoard(self):
        if self.checkTList() is False:
            return -1
        else:
            try:
                combos = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]]
                for set in combos:
                    if self.board[set[0]] == self.board[set[1]] == self.board[set[2]]:
                        if self.board[set[0]] == 1 or self.board[set[0]] == 2:
                            return self.board[set[0]]
                if 0 not in self.board:
                    return 3
                else:
                    return 0
            except:
                return -1

    def genRandomMove(self, player):
        if self.checkTList() is False:
            return -1
        elif player not in (1,2):
            return -1
        else:
            try:
                potential_positions=[]
                for i in range(0,9,1):
                    if self.board[i] == 0:
                        potential_positions.append(i)
                if len(potential_positions) == 0:
                    return -1
                else:
                    move = potential_positions[randint(0, len(potential_positions)-1)]
                    return move
            except:
                return -1

    def genWinningMove(self, player):
        if self.checkTList() is False:
            return -1
        elif player not in (1,2):
            return -1
        else:
            try:
                combos = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]]
                for set in combos:
                    if self.board[set[0]] == self.board[set[1]] == player and self.board[set[2]] == 0:
                        return set[2]
                    elif self.board[set[0]] == self.board[set[2]] == player and self.board[set[1]] == 0:
                        return set[1]
                    elif self.board[set[1]] == self.board[set[2]] == player and self.board[set[0]] == 0:
                        return set[0]
                return -1
            except:
                return -1

    def genNonLoser(self, player):
        try:
            if player == 1:
                return self.genWinningMove(2)
            elif player == 2:
                return self.genWinningMove(1)
            else:
                return -1
        except:
            return -1

    def Move(self, x, player):
        if self.checkTList() is False:
            return False
        if player not in [1,2]:
            return False
        if x not in range(0,9,1):
            return False
        elif self.analyzeBoard() == 0 and self.board[x] == 0:
            self.board[x] = int(player)
            return True
        else:
            return False