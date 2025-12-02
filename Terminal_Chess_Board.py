class cell():
    def __init__(self, piece):
        if piece == 'p1pawn':
            self.region = '|[p]'
        elif piece == 'p2pawn':
            self.region = '|(P)'
        elif piece == 'p1knight':
            self.region = '|[h]'
        elif piece == 'p2knight':
            self.region = '|(H)'
        elif piece == 'p1rook':
            self.region = '|[r]'
        elif piece == 'p2rook':
            self.region = '|(R)'
        elif piece == 'p1bishop':
            self.region = '|[b]'
        elif piece == 'p2bishop':
            self.region = '|(B)'
        elif piece == 'p1queen':
            self.region = '|[q]'
        elif piece == 'p2queen':
            self.region = '|(Q)'
        elif piece == 'p1king':
            self.region = '|[k]'
        elif piece == 'p2king':
            self.region = '|(K)'
        else:
            self.region = '| 0 '

def start_conditions():
    global rec_pieces
    print('| a | b | c | d | e | f | g | h |', '\n')
    for y in regions[1]:
        for x in regions[0]:
            p1rook = [x == 'a' or x == 'h', y == 8]
            p2rook = [x == 'a' or x == 'h', y == 1]
            p1knight = [x == 'b' or x == 'g', y == 8]
            p2knight = [x == 'b' or x == 'g', y == 1]
            p1bishop = [x == 'c' or x == 'f', y == 8]
            p2bishop = [x == 'c' or x == 'f', y == 1]
            p1queen = [x == 'd', y == 8]
            p2queen = [x == 'd', y == 1]
            p1king = [x == 'e', y == 8]
            p2king = [x == 'e', y == 1]
            if y == 2:
                piece = 'p2pawn'
            elif y == 7:
                piece = 'p1pawn'
            elif all (p1rook):
                piece = 'p1rook'
            elif all (p2rook):
                piece = 'p2rook'
            elif all (p1knight):
                piece = 'p1knight'
            elif all (p2knight):
                piece = 'p2knight'
            elif all (p1bishop):
                piece = 'p1bishop'
            elif all (p2bishop):
                piece = 'p2bishop'
            elif all (p1queen):
                piece = 'p1queen'
            elif all (p2queen):
                piece = 'p2queen'
            elif all (p1king):
                piece = 'p1king'
            elif all (p2king):
                piece = 'p2king'
            else:
                piece = '0'
            if piece != '0':
                rec_pieces[0].append(x+str(y))
                rec_pieces[1].append(piece)
            cellx = cell(piece)
            print(cellx.region, end='') 
        print('| ', y, '\n')

def move_cell(sel_reg, mov_reg, piece):
    global rec_pieces
    c = 0
    for rec_piece in rec_pieces[0]:
        if rec_piece == sel_reg:
            rec_pieces[0].pop(c)
            rec_pieces[1].pop(c)
        c += 1
    if mov_reg in rec_pieces[0]:
        c = 0
        for rec_piece in rec_pieces[0]:
            if rec_piece == mov_reg:
                rec_pieces[0].pop(c)
                rec_pieces[0].append(mov_reg)
                rec_pieces[1].pop(c)
                rec_pieces[1].append(piece)
            c += 1
    else:
        rec_pieces[0].append(mov_reg)
        rec_pieces[1].append(piece)

def get_cell(x, y):
    coord = x + str(y)
    if not coord in rec_pieces[0]:
        return '0'
    c = 0
    for rec_piece in rec_pieces[0]:
        if rec_piece == coord:
            return rec_pieces[1][c]
        c += 1

def check_cell(pc_sel):
    if not pc_sel in rec_pieces[0]:
        return '0'
    else:
        c = 0
        for rec_piece in rec_pieces[0]:
            if rec_piece == pc_sel:
                return rec_pieces[1][c]
            c += 1

def make_board():
    print('| a | b | c | d | e | f | g | h |', '\n')
    for y in regions[1]:
        for x in regions[0]:
            piece = get_cell(x, y)
            cellx = cell(piece)
            print(cellx.region, end='')
        print('| ', y, '\n')

def player1_move():
    global inp
    valid1 = False
    valid2 = False
    while valid1 == False:
        inp = input('Player 1 what would you like to do?: ')
        if inp == 'move':
            pc_sel = input('Player 1 select a piece: ')
            piece = check_cell(pc_sel)
            if piece == '0':
                print('No piece found, please select a piece.')
            elif not pc_sel[0] in regions[0] or not pc_sel[1] in str(regions[1]):
                print('Please enter a valid coordinate.')
            else:
                valid1 = True
            while valid2 == False:
                mv_sel = input('Where to?: ')
                if not mv_sel[0] in regions[0] or not mv_sel[1] in str(regions[1]):
                    print('Please enter a valid coordinate.')  
                else:
                    valid2 = True
            move_cell(pc_sel, mv_sel, piece)
            make_board()
        elif inp == 'resign':
            return False
        else:
            print('Please enter a valid input.')

def player2_move():
    valid1 = False
    valid2 = False
    while valid1 == False:
        inp = input('Player 2 what would you like to do?: ')
        if inp == 'move':
            pc_sel = input('Player 2 select a piece: ')
            piece = check_cell(pc_sel)
            if piece == '0':
                print('No piece found, please select a piece.')
            elif not pc_sel[0] in regions[0] or not pc_sel[1] in str(regions[1]):
                print('Please enter a valid coordinate.')
            else:
                valid1 = True
            while valid2 == False:
                mv_sel = input('Where to?: ')
                if not mv_sel[0] in regions[0] or not mv_sel[1] in str(regions[1]):
                    print('Please enter a valid coordinate.')  
                else:
                    valid2 = True
            move_cell(pc_sel, mv_sel, piece)
            make_board()
        elif inp == 'resign':
            return False
        else:
            print('Please enter a valid input.')

active = True
rec_pieces = [[],[]]
regions = [['a','b','c','d','e','f','g','h'],[1,2,3,4,5,6,7,8]]
start_conditions()
while active != False:
    active = player1_move()
    if active == False:
        print('Player 2 wins!')
        break
    active = player2_move()
    if active == False:
        print('Player 1 wins!')
        break
    