board = [["_","_","_"],
         ["_","_","_"],
         ["_","_","_"]]

def emptySpaces():
    l=[]
    print("empty spaces at")
    for i in range(0,3):
        for j in range(0,3):
            if(board[i][j]=="_"):
                l.append([i,j])
    for val in l:
        print(val,end=",")
    return l
   
def TicTacToe():
    print("Board Initially")
    display()
    player = 1
    moves=1
    while(moves<9):
        print("turn of player: ",player)
        cords=takeInput()
        if(player==1):
             board[cords[0]][cords[1]] = "X"
        elif(player==2):
            board[cords[0]][cords[1]] = "O"
        print("Board Now")
        display()
        l=emptySpaces()
        print()
        if(check()==True):
            print("Player ",player,"won!")
            break
        if(player==1):
            player = player+1
        elif(player==2):
            player=player-1
        moves = moves+1
def takeInput():
    print("enter row number(less than 3)")
    m = int(input())
    print("enter column number(less than 3)")
    n = int(input())
    l = [m,n]
    return l
def display():
    for i in range(0,3):
        for j in range(0,3):
            print(board[i][j]," ",end="")
        print()
def check():
    #first row check
    if(board[0][0]==board[0][1] and board[0][1]==board[0][2] and board[0][2]!="_"):
        return True
    #second row check
    elif(board[1][0]==board[1][1] and board[1][1]==board[1][2] and board[1][2]!="_"):
        return True
    #third row check
    elif(board[2][0]==board[2][1] and board[2][1]==board[2][2] and board[2][2]!="_"):
        return True
    #first column
    elif(board[0][0]==board[1][0] and board[1][0]==board[2][0] and board[2][0]!="_"):
        return True
    #second column
    elif(board[0][1]==board[1][1] and board[1][1]==board[2][1] and board[2][1]!="_"):
        return True
    #third column
    elif(board[0][2]==board[1][2] and board[1][2]==board[2][2] and board[2][2]!="_"):
        return True
    #right diagonal
    elif(board[0][0]==board[1][1] and board[1][1]==board[2][2] and board[2][2]!="_"):
        return True
    #left diagonal
    elif(board[0][2]==board[1][1] and board[1][1]==board[2][0] and board[2][0]!="_"):
        return True
    else:
        return False
TicTacToe()