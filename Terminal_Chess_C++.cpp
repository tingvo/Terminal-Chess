#include <iostream>
#include <string>
using namespace std;

string get_cell()
string check_cell()

void start_conditions(){
    cout << "| a | b | c | d | e | f | g | h |" << endl;
    int i = 0;
    for (string y : regions[1]){
        for (string x : regions[0]){
            if (y == "2"){
                string piece = "p2pawn";
            } else if (y == "7"){
                string piece = "p1pawn";
            } else if ((x == "a" || x == "h") && y == "8"){
                string piece = "p1rook";
            } else if ((x == "a" || x == "h") && y == "1"){
                string piece = "p2rook";
            } else if ((x == "b" || x == "g") && y == "8"){
                string piece = "p1knight";
            } else if ((x == "b" || x == "g") && y == "1"){
                string piece = "p2knight";
            } else if ((x == "c" || x == "f") && y == "8"){
                string piece = "p1bishop";
            } else if ((x == "c" || x == "f") && y == "1"){
                string piece = "p2bishop";
            } else if (x == "d" && y == "8"){
                string piece = "p1queen";
            } else if (x == "d" && y == "1"){
                string piece = "p2queen";
            } else if (x == "e" && y == "8"){
                string piece = "p1king";
            } else if (x == "e" && y == "1"){
                string piece = "p2king";
            } else {
                string piece = "0"
            }
            if (piece != "0"){
                rec_pieces[0][i] = x + y;
                rec_pieces[1][i] = piece;
                i++;
            }
            //cellx = cell(piece);
            //cout << cellx.region;
        }
        cout << "| " + y << endl;
    }
}

void move_cell{

}

string get_cell(){

}

string check_cell(){

}

void make_board(){

}

bool active = true;
string rec_pieces[32][32]
const string regions[8][8] {{"a","b","c","d","e","f","g","h"},{"1","2","3","4","5","6","7","8"}}
int main(){
    

}