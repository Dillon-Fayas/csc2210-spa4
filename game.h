//
// Created by spiro on 3/29/2026.
//

#ifndef GAME_H
#define GAME_H
#include "map.h"

class Map;
class Player;

class Game {
private:
    Map *map;
    Player *player;
    bool debugMode;
    bool dragonSlain;

    void showClues() const;
    void checkCurrentRoom();
    void handleWeaponThrow(int weaponType);

public:
    Game();
    ~Game();

    void start();
    void showWelcome();
    void showHelp();
    void processTurn(char command);
    void toggleDebugMode();
    bool checkGameOver();
    void printMapDebug();

    Map* getMap() const;
    Player* getPlayer() const;
    void setDragonSlain(bool val);
};


#endif //GAME_H