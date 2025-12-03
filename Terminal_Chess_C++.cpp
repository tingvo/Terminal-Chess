#include <iostream>
#include <string>
using namespace std;

void start_conditions();
string get_cell(string pc_sel);
string def_cell(string piece);
bool player1_move();
bool player2_move();

bool active = true;
string rec_pieces[32][32];
const string regions[8][8] = {{"a","b","c","d","e","f","g","h"},{"1","2","3","4","5","6","7","8"}};

int main(){
    start_conditions();
    while (active == true){
        active = player1_move();
        if (active == false){
            cout << "Player 2 wins!";
            break;
        }
        active = player2_move();
        if (active == false){
            cout << "Player 1 wins!";
            break;
        }
    }
}

string make_cell(string piece){
    string output;
    if (piece == "p1pawn"){
        output = "|[p]";
    } else if (piece == "p2pawn"){
        output = "|(P)";
    } else if (piece == "p1knight"){
        output = "|[h]";
    } else if (piece == "p2knight"){
        output = "|(H)";
    } else if (piece == "p1rook"){
        output = "|[r]";
    } else if (piece == "p2rook"){
        output = "|(R)";
    } else if (piece == "p1bishop"){
        output = "|[b]";
    } else if (piece == "p2bishop"){
        output = "|(B)";
    } else if (piece == "p1queen"){
        output = "|[q]";
    } else if (piece == "p2queen"){
        output = "|(Q)";
    } else if (piece == "p1king"){
        output = "|[k]";
    } else if (piece == "p2king"){
        output = "|(K)";
    } else {
        output = "| 0 ";
    }
    return output;
}

void start_conditions(){
    cout << "| a | b | c | d | e | f | g | h |" << endl;
    int i = 0;
    string piece;
    for (string y : regions[1]){
        for (string x : regions[0]){
            if (y == "2"){
                piece = "p2pawn";
            } else if (y == "7"){
                piece = "p1pawn";
            } else if ((x == "a" || x == "h") && y == "8"){
                piece = "p1rook";
            } else if ((x == "a" || x == "h") && y == "1"){
                piece = "p2rook";
            } else if ((x == "b" || x == "g") && y == "8"){
                piece = "p1knight";
            } else if ((x == "b" || x == "g") && y == "1"){
                piece = "p2knight";
            } else if ((x == "c" || x == "f") && y == "8"){
                piece = "p1bishop";
            } else if ((x == "c" || x == "f") && y == "1"){
                piece = "p2bishop";
            } else if (x == "d" && y == "8"){
                piece = "p1queen";
            } else if (x == "d" && y == "1"){
                piece = "p2queen";
            } else if (x == "e" && y == "8"){
                piece = "p1king";
            } else if (x == "e" && y == "1"){
                piece = "p2king";
            } else {
                piece = "0";
            }
            if (piece != "0"){
                rec_pieces[0][i] = x + y;
                rec_pieces[1][i] = piece;
                i++;
            }
            string cell = make_cell(piece);
            cout << cell;
        }
        cout << "| " + y << endl;
    }
}

void move_cell(string sel_reg, string mov_reg, string piece){
    int c = 0;
    for (string rec_piece : rec_pieces[0]){
        if (rec_piece == sel_reg){
            rec_pieces[0][c] = mov_reg;
        }
        if (mov_reg == rec_piece){
            rec_pieces[0][c] = "taken";
            rec_pieces[1][c] = "taken";
        }
        c++;
    }
}

string get_cell(string pc_sel){
    int c = 0;
    bool present;
    for (string rec_piece : rec_pieces[0]){
        if (rec_piece == pc_sel){
            present = true;
            return rec_pieces[1][c];
            break;
        } else {
            present = false;
        }
        c++;
    }
    if (present == false){
        return "0";
    }
}

void make_board(){
    cout << "| a | b | c | d | e | f | g | h |" << endl;
    for (string y : regions[1]){
        for (string x : regions[0]){
            string z = x + y;
            string piece = get_cell(z);
            string cell = make_cell(piece);
            cout << cell;
        }
        cout << "| " + y << endl;
    }
}

bool player1_move(){
    bool valid1 = false;
    bool valid2 = false;
    string inp;
    string pc_sel;
    string mv_sel;
    while (valid1 == false){
        cout << "Player 1 what would you like to do?: ";
        cin >> inp;
        if (inp == "move"){
            cout << "Player 1 please select a piece: ";
            cin >> pc_sel;
            string piece = get_cell(pc_sel);
            if (piece == "0"){
                cout << "No piece found, please select a piece.";
            } else if (find(begin(regions[0]), end(regions[0]), pc_sel[0]) == end(regions[0]) || 
                    find(begin(regions[1]), end(regions[1]), pc_sel[1]) == end(regions[1])){
                cout << "Please enter a valid coordinate." << endl;
            } else {
                valid1 = true;
            }
            while (valid2 == false){
                cout << "Where to?: ";
                cin >> mv_sel;
                if (find(begin(regions[0]), end(regions[0]), mv_sel[0]) == end(regions[0]) || 
                    find(begin(regions[1]), end(regions[1]), mv_sel[1]) == end(regions[1])){
                cout << "Please enter a valid coordinate." << endl;
                } else {
                    valid2 = true;
                }
            move_cell(pc_sel, mv_sel, piece);
            make_board();
            return true;
            }
        } else if (inp == "resign"){
            return false;
        } 
    }
}

bool player2_move(){
    bool valid1 = false;
    bool valid2 = false;
    string inp;
    string pc_sel;
    string mv_sel;
    while (valid1 == false){
        cout << "Player 2 what would you like to do?: ";
        cin >> inp;
        if (inp == "move"){
            cout << "Player 2 please select a piece: ";
            cin >> pc_sel;
            string piece = get_cell(pc_sel);
            if (piece == "0"){
                cout << "No piece found, please select a piece.";
            } else if (find(begin(regions[0]), end(regions[0]), pc_sel[0]) == end(regions[0]) || 
                    find(begin(regions[1]), end(regions[1]), pc_sel[1]) == end(regions[1])){
                cout << "Please enter a valid coordinate." << endl;
            } else {
                valid1 = true;
            }
            while (valid2 == false){
                cout << "Where to?: ";
                cin >> mv_sel;
                if (find(begin(regions[0]), end(regions[0]), mv_sel[0]) == end(regions[0]) || 
                    find(begin(regions[1]), end(regions[1]), mv_sel[1]) == end(regions[1])){
                cout << "Please enter a valid coordinate." << endl;
                } else {
                    valid2 = true;
                }
            move_cell(pc_sel, mv_sel, piece);
            make_board();
            return true;
            }
        } else if (inp == "resign"){
            return false;
        } 
    }
}
