#include <stdlib.h>
#include <time.h>
#include "Game.h"
using namespace std;

int main() {
    srand(time(NULL)); //Random seed for each game
    Game *g = new Game(); //Create Game object
    g->interact();
    //When the game is finished, output the score
    g->score();
    delete g;
    return 0;
}
