//
// Created by spiro on 3/29/2026.
//

#ifndef CSC1120_SPA4_GAME_H
#define CSC1120_SPA4_GAME_H
#include "map.h"

class map;
class player;

class game {
private:
    map *map;
    player *player;
    bool debugMode;

public:
    game();
    ~game();

    void start();
    void showWelcome();
    void showHelp();
    void processTurn(char command);
    void toggleDebugMode();
    bool checkGameOver();
    void printMapDebug();
};


#endif //CSC1120_SPA4_GAME_H