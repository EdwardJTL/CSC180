gameboard=[1,2,3,4,5,6,7,8,9]
playerx="1"
playero="2"
turn = "x"
plays = 0
def players():
    asking = True
    while asking:
        global turn
        global playerx
        global playero
        input=raw_input("Player 1, choose x/o:")
        if input == "x":
            playerx = "1"
            playero = "2"
            turn = input
            asking=False
        elif input == "o":
            playero = "1"
            playerx = "2"
            turn = input
            asking = False
        else:
            print "Input not valid."
def displayBoard():
    row1 = str(gameboard[0]) + " | " + str(gameboard[1]) + " | " + str(gameboard[2])
    row2 = str(gameboard[3]) + " | " + str(gameboard[4]) + " | " + str(gameboard[5])
    row3 = str(gameboard[6]) + " | " + str(gameboard[7]) + " | " + str(gameboard[8])
    line_separator="---------"
    for i in [row1, line_separator, row2, line_separator, row3]:
        print i
def askForInput() :
    asking=True
    global plays
    while asking:
        choice=raw_input("Please Choose A Square:")
        if choice in ["1","2","3","4","5","6","7","8","9"] and type(gameboard[int(choice)-1])==int:
            asking = False
            plays += 1
            return int(choice)-1
        else:
            print "Input not valid."
def playerTurn():
    global turn
    if turn == "x":
        gameboard[askForInput()]="x"
        turn = "o"
    elif turn == "o":
        gameboard[askForInput()]="o"
        turn = "x"
def mainGame():
    global gameboard
    global plays
    gameboard = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    players()
    combos=[[0,1,2],[3,4,5],[6,7,8],[0,3,6],[1,4,7],[2,5,8],[0,4,8],[2,4,6]]
    running = True
    plays = 0
    while running:
        displayBoard()
        playerTurn()
        for set in combos:
            if gameboard[set[0]] == gameboard[set[1]] and gameboard[set[1]] == gameboard[set[2]]:
                if gameboard[set[0]]=="x":
                    displayBoard()
                    print "Player " + playerx + " won!"
                elif gameboard[set[0]] == "o":
                    displayBoard()
                    print "Player " + playero + " won!"
                running=False
        if plays >= 9 and running:
            print "It is a draw!"
            running = False
mainGame()