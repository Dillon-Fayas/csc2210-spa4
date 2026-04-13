//
// Created by spiro on 3/29/2026.
//

#include <iostream>
#include "game.h"

#include <limits>

#include "hazard.h"
#include "map.h"
#include "player.h"
#include "room.h"
#include "weapon.h"

Game::Game() {
    map = nullptr;
    player = nullptr;
    debugMode = false;
    dragonSlain = false;
}

Game::~Game() {
    delete player;
    delete map;
}

Map* Game::getMap() const { return map; }
Player* Game::getPlayer() const { return player; }
void Game::setDragonSlain(bool val) { dragonSlain = val; }


void Game::start() {

    map = new Map(5,5);
    map->buildRooms();
    map->connectRooms();
    map->placeHazards();
    map->placeWeapons();

    player = new Player();
    player->setCurrentRoom(map->getRandomRoom());

    showWelcome();

    std::cout << "\nPress ENTER to begin..\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (!checkGameOver()) {
        std::cout << "\n------------------------------\n";
        map->displayMap(player);
        showClues();

        if (debugMode) {
            printMapDebug();
        }

        player->printStatus();
        std::cout << "Controls (n/s/e/w/j/f/i/h/q): ";

        char command;
        std::cin >> command;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        processTurn(command);
    }

    if (dragonSlain) {
        std::cout << "\n*** You have defeated the dragon! ***\n";
    } else if (!player->isAlive()) {
        std::cout << "\n*** You have perished in the dungeon. ***\n";
    }
}

void Game::showWelcome() {
    std::cout << "Welcome to The Dragon Game!\n\n";

    std::cout << "Deep beneath the earth lies a dangerous dungeon filled with deadly traps, mysterious magic, "
        << "and one legendary beast, the dragon. You have entered this dungeon with one goal: "
        << "find and slay the dragon before it kills you.\n\n";

    std::cout << "As you explore the dungeon, you will move from room to room using the directions north, south, east, "
        << "and west. But be careful, the dungeon is filled with hazards. If you step into the dragon's chamber, "
        << "you will be killed instantly. Hidden patches of quicksand can pull you under, and lurking gargoyles "
        << "may seize you and carry you to a random room.\n\n";

    std::cout << "To survive, you must rely on the clues around you. If the dragon is nearby, you will feel intense heat. "
        << "If quicksand is close, you will see signs of sand on the ground. If gargoyles are near, you will hear "
        << "loud flapping. Use these warnings carefully to figure out where danger is hiding.\n\n";

    std::cout << "You begin your journey with five javelins, which can be thrown into adjacent rooms. As you explore, "
        << "you may also discover more javelins, fireballs, and ice spikes. Fireballs and ice spikes "
        << "can travel through multiple rooms in one direction. However, be warned: if you miss with any "
        << "weapon, the dragon will flee and move to a random room.\n\n";

    std::cout << "Your mission is simple:\n";

    std::cout << "Explore the dungeon. Avoid its hazards. Use logic to track the dragon. Defeat it before it defeats you.\n\n";

    std::cout << "Good luck, hunter.\n";

    std::cout << "Controls:\n\n";
    std::cout << "n = move north\n";
    std::cout << "s = move south\n";
    std::cout << "e = move east\n";
    std::cout << "w = move west\n";
    std::cout << "j = throw a javelin\n";
    std::cout << "f = cast a fireball\n";
    std::cout << "i = cast an ice spike\n";
    std::cout << "h = show help\n";
    std::cout << "q = quit the game\n";
}


void Game::showHelp() {
    std::cout << "Controls:\n"
              << "  n = move north\n"
              << "  s = move south\n"
              << "  e = move east\n"
              << "  w = move west\n"
              << "  j = throw a javelin (1 adjacent room)\n"
              << "  f = cast a fireball (travels multiple rooms)\n"
              << "  i = cast an ice spike (travels multiple rooms)\n"
              << "  h = show this help menu\n"
              << "  q = quit the game\n";
}

void Game::showClues() const {
    Room*       curr    = player->getCurrentRoom();
    const char  dirs[]  = { 'n', 's', 'e', 'w' };
    bool        anyClue = false;

    std::string seenClues[4];
    int seenCount = 0;

    for (char d : dirs) {
        Room* neighbor = curr->getNeighbor(d);
        if (neighbor == nullptr || !neighbor->hasHazard()) continue;

        std::string clue = neighbor->getHazard()->getClue();
        if (clue.empty()) continue;

        bool duplicate = false;
        for (int i = 0; i < seenCount; i++) {
            if (seenClues[i] == clue) { duplicate = true; break; }
        }
        if (!duplicate) {
            std::cout << clue << "\n";
            seenClues[seenCount++] = clue;
            anyClue = true;
        }
    }

    if (!anyClue) {
        std::cout << "The dungeon is quiet here.\n";
    }
}

void Game::checkCurrentRoom() {
    Room* room = player->getCurrentRoom();
    
    if (room->hasHazard()) {
        room->getHazard()->trigger(player, this);
    }
    
    if (player->isAlive() && room->hasWeapon()) {
        player->pickUpWeapon();
    }
}

void Game::handleWeaponThrow(int weaponType) {
    if (weaponType == 0) {
        if (player->getJavelinCount() <= 0) {
            std::cout << "You don't have any javelins left.\n";
            return;
        }
        std::cout << "Which direction do you throw the Javelin (n/s/e/w)? ";
        char dir;
        std::cin >> dir;
        
        player->decreaseJavelin();
        
        Spear tempSpear;
        bool hit = tempSpear.use(player->getCurrentRoom(), dir, this);
        
        if (hit) {
            dragonSlain = true;
            std::cout << "Your Javelin find its mark! The dragon is dead!\n";
        } else {
            std::cout << "Your javelin disappears into the darkness. A miss.\n";
            map->moveDragonToRandom();
        }
        return;
    }
    
    int slot = weaponType - 1;
    if (!player->hasInventoryWeapon(slot)) {
        std::cout << "You don't have that weapon.\n";
        return;
    }
    
    std::cout << "Cast in which direction (n/s/e/w)? ";
    char dir;
    std::cin >> dir;
    
    Weapon* weapon = player->getInventoryWeapon(slot);
    bool hit = weapon->use(player->getCurrentRoom(), dir, this);
    player->removeInventoryWeapon(slot);
    
    if (hit) {
        dragonSlain = true;
        std::cout << "The dragon is slain by your weapon!\n";
    } else {
        std::cout << "The weapon travels through empty rooms. A miss.\n";
        map->moveDragonToRandom();
    }
}


void Game::processTurn(char command) {
    std::cout << "Processing command: " << command << std::endl;

    switch (command) {
        case 'n':
        case 's':
        case 'e':
        case 'w':
            player->move(command);
            checkCurrentRoom();
            break;

        case 'j':
            handleWeaponThrow(0);
            break;
        case 'f':
            handleWeaponThrow(1);
            break;
        case 'i':
            handleWeaponThrow(2);
            break;
            
            
        case 'h':
            showHelp();
            break;
        case 'm':
            toggleDebugMode();
            break;

        case 'q':
            std::cout << "You flee the dungeon. Farewell, hunter.\n";
            player->setAlive(false);
            break;

        default:
            std::cout << "Invalid command. Type 'h' for help.\n";
            break;
    }
}

void Game::toggleDebugMode() {
    debugMode = !debugMode;
    std::cout << "Debug mode is now " << (debugMode ? "on" : "off") << std::endl;
}


bool Game::checkGameOver() {
    if (dragonSlain) return true;

    if (player != nullptr && !player->isAlive()) return true;

    return false;
}

void Game::printMapDebug() {
    if (map != nullptr && player != nullptr) {
        map->displayDebug(player);
    }
}
