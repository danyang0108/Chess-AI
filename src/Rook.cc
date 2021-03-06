#include "Chessboard.h"
#include "Rook.h"
using namespace std;

Rook::Rook(int row, int col, char name): Piece(row, col, name) {}

//Legal locations include horizontal/vertical moves
int Rook::checkValidMove(int targetX, int targetY, Chessboard *component){
    int diffX = abs(x - targetX), diffY = abs(y - targetY);
    //Ensure new move isn't to original location
    if (diffX == 0 && diffY == 0) return 0;
    //If new location not on current (x, y) location's x/y axis, it's invalid
    if (diffX != 0 && diffY != 0) return 0;
    //Next, check if the path to new location isn't blocked off
    if (diffX == 0){ //Move is horizontal
        for (int tempY = min(y, targetY) + 1; tempY < max(y, targetY); ++tempY){ //Example: (2, 3) to (2, 7) has 7-3-1=3 pieces on horizontal axis
            //If not empty, it's occupied, and thus the path is blocked
            if (component->location(x, tempY) != NULL) return 0;
        }
    }
    else{ //Move is vertical
        for (int tempX = min(x, targetX) + 1; tempX < max(x, targetX); ++tempX){ //Example: (3, 3) to (7, 3) has 7-3-1=3 pieces on horizontal axis
            //If not empty, it's occupied, and thus the path is blocked
            if (component->location(tempX, y) != NULL) return 0;
        }
    }
    //Finally, the target piece must either be empty or
    //occupied with enemy piece
    //NOTE: check castling
    Piece *targetPiece = component->location(targetX, targetY);
    if (targetPiece == NULL) return 1;
    if (colour == 'w'){
        //With a white rook, the enemy pieces must be lowercase
        if (islower(targetPiece->name)) return 2;
        //Check castling
        else return 0;
    }
    else{
        //With a black rook, the enemy pieces must be uppercase
        if (isupper(targetPiece->name)) return 2;
        //Check castling
        else return 0;
    }
}
