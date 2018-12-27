from random import randint
def genBoard():
    board=[0,0,0,0,0,0,0,0,0]
    return board


def checkTList(T):
    try:
        if len(T) != 9:
            return False
        if type(T) != list:
            return False
        for i in T:
            if i not in (0,1,2):
                return False
        else:
            return True
    except:
        return False


def printBoard(t):
    gameboard = []
    if checkTList(t) == False:
        return False
    else:
        try:
            for i in range(0,9,1):
                if t[i] == 0:
                    gameboard.append(i)
                elif t[i] == 1:
                    gameboard.append("X")
                elif t[i] == 2:
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


def get_move(T):
    allowInput = True
    while allowInput:
        userInput = raw_input("Please choose a square: ")
        try:
            choice = int(userInput)
            if choice not in range(0, 9, 1):
                print "Please enter a number displayed on the board."
            elif T[choice] != 0:
                print "Please enter the number of an available square."
            else:
                return choice
        except ValueError:
            print "Please enter only the number of your desired square."


def analyzeBoard(T):
    if checkTList(T) == False:
        return -1
    else:
        try:
            combos = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]]
            for set in combos:
                if T[set[0]] == T[set[1]] and T[set[1]]== T[set[2]]:
                    if T[set[0]] == 1 or T[set[0]] == 2:
                        return T[set[0]]
            if 0 not in T:
                return 3
            else:
                return 0
        except:
            return -1

def genRandomMove(T,player):
    if checkTList(T) == False:
        return -1
    elif player not in (1,2):
        return -1
    else:
        try:
            potential_positions=[]
            for i in range(0,9,1):
                if T[i] == 0:
                    potential_positions.append(i)
            if len(potential_positions) == 0:
                return -1
            else:
                move = potential_positions[randint(0,len(potential_positions)-1)]
                return move
        except:
            return -1


def genWinningMove(T,player):
    if checkTList(T) == False:
        return -1
    elif player not in (1,2):
        return -1
    else:
        try:
            combos = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]]
            for set in combos:
                if T[set[0]] == T[set[1]] == T[set[0]] == player and T[set[2]] == 0:
                    return set[2]
                elif T[set[0]] == T[set[2]] == T[set[0]] == player and T[set[1]] == 0:
                    return set[1]
                elif T[set[1]] == T[set[2]] == T[set[1]] == player and T[set[0]] == 0:
                    return set[0]
            return -1
        except:
            return -1


def genNonLoser(T,player):
    try:
        if player == 1:
            return genWinningMove(T,2)
        elif player == 2:
            return genWinningMove(T,1)
        else:
            return -1
    except:
        return -1
printBoard(genBoard())
print analyzeBoard([0,0,0,1,1,1,0,0,0])