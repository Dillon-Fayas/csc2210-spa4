//
// Created by spiro on 3/29/2026.
//

#include <iostream>
#include <string>
#include "map.h"

#include "hazard.h"
#include "room.h"
#include "player.h"
#include "weapon.h"

Map::Map(int rows, int cols) : rows(rows), cols(cols) {

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            rooms[r][c] = nullptr;
        }
    }
    srand(static_cast<unsigned int>(time(nullptr)));
}

Map::~Map() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            delete rooms[r][c];
        }
    }
}

void Map::buildRooms() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            rooms[r][c] = new Room("A dark dungeon room");
        }
    }
}

void Map::connectRooms() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Room* north = (r > 0) ? rooms[r - 1][c] : nullptr;
            Room* south = (r < rows - 1) ? rooms[r + 1][c] : nullptr;
            Room* east = (c < cols - 1) ? rooms[r][c + 1] : nullptr;
            Room* west = (c > 0) ? rooms[r][c - 1] : nullptr;

            rooms[r][c]-> setNeighbors(north, south, east, west);
        }
    }
}

void Map::randomEmptyCell(int& outR, int& outC) const {
    int r, c;
    int attempts = 0;

    do {
        r = rand() % rows;
        c = rand() % cols;
        attempts++;
        if (attempts > 10000);
    } while ((r == 0 && c ==0) || rooms[r][c]->hasHazard() || rooms[r][c]->hasWeapon());
    outR = r;
    outC = c;
}

void Map::placeHazards() {
    int r, c;
    randomEmptyCell(r, c);
    rooms[r][c]->setHazard(new Dragon());

    for (int i = 0; i < 2; i++) {
        randomEmptyCell(r, c);
        rooms[r][c]->setHazard(new Pit());
    }

    for (int i = 0; i < 2; i++) {
        randomEmptyCell(r, c);
        rooms[r][c]->setHazard(new Gargoyle());
    }
}

void Map::placeWeapons() {
    int r, c;

    // 3 spare javelins scattered around the dungeon
    for (int i = 0; i < 3; i++) {
        randomEmptyCell(r, c);
        rooms[r][c]->setWeapon(new Spear());
    }

    // 2 fireball scrolls
    for (int i = 0; i < 2; i++) {
        randomEmptyCell(r, c);
        rooms[r][c]->setWeapon(new Fireball());
    }

    // 2 ice spike scrolls
    for (int i = 0; i < 2; i++) {
        randomEmptyCell(r, c);
        rooms[r][c]->setWeapon(new IceSpike());
    }
}

void Map::moveDragonToRandom() {
    Room* dragonRoom = nullptr;
    Dragon* dragon = nullptr;

    for (int r = 0; r < rows && dragonRoom == nullptr; r++) {
        for (int c = 0; c < cols && dragonRoom == nullptr; c++) {
            if (rooms[r][c]->hasHazard()) {
                Dragon* d = dynamic_cast<Dragon*>(rooms[r][c]->getHazard());
                if (d != nullptr) {
                    dragonRoom = rooms[r][c];
                    dragon = d;
                }
            }
        }
    }

    if (dragonRoom == nullptr || dragon == nullptr) return;

    dragonRoom->setHazard(nullptr);

    int nr, nc;
    do {
        nr = rand() % rows;
        nc = rand() % cols;
    } while ((nr == 0 && nc == 0) || rooms[nr][nc]->hasHazard());

    rooms[nr][nc]->setHazard(dragon);
    std::cout << "You hear a roar echo through the dungeon as the dragon retreats!\n";
}


Room* Map::getRandomRoom() const {
    int r = rand() % rows;
    int c = rand() % cols;
    return rooms[r][c];
}

void Map::displayMap(Player* player) const {
    Room* playerRoom = player->getCurrentRoom();

    std::cout << "\n=== DUNGEON MAP ===\n";
    std::cout << "  ";
    for (int c = 0; c < cols; c++) std::cout << c << " ";
    std::cout << "\n";

    std::cout << "  ";
    for (int c = 0; c < cols; c++) std::cout << "--";
    std::cout << "\n";

    for (int r = 0; r < rows; r++) {
        std::cout << r << " ";
        for (int c = 0; c < cols; c++) {
            if (rooms[r][c] == playerRoom) {
                std::cout << "+ ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "Legend: + you . unexplored\n\n";

}

void Map::displayDebug(Player *player) const {
    std::cout << "Display debug stub." << std::endl;
    Room* playerRoom = player->getCurrentRoom();

    std::cout << "\n=== Debug Map ===\n";
    std::cout << "  ";
    for (int c = 0; c < cols; c++) std::cout << c << " ";
    std::cout << "\n";


    std::cout << "  ";

    for (int c = 0; c < cols; c++) std::cout << "--";
    std::cout << "\n";

    for (int r = 0; r < rows; r++) {
        std::cout << r << " ";
        for (int c = 0; c < cols; c++ ) {
            Room* room = rooms[r][c];

            if (room == playerRoom) {
                std::cout << "+ ";
            } else if (room->hasHazard()) {
                std::string hName = room->getHazard()->getName();
                if (hName == "Dragon") std::cout << "# ";
                else if (hName == "Pit") std::cout << "@ ";
                else if (hName == "Gargoyle") std::cout << "! ";
                else std::cout << "? ";
            } else if (room->hasWeapon()) {
                std::string wName = room->getWeapon()->getName();
                if (wName == "Spear") std::cout << "> ";
                else if (wName == "FireBall") std::cout << "< ";
                else std::cout << "^ ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "Legend: + you # Dragon @ QuickSand ! Gargoyle > Javelin < Fireball\n\n";
}