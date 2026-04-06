//
// Created by spiro on 3/29/2026.
//

#include <iostream>
#include <string>
#include "map.h"
#include "room.h"
#include "player.h"


Map::Map(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            rooms[r][c] = nullptr;
        }
    }
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

void Map::placeHazards() {
    std::cout << "Place hazards stub." << std::endl;
}

void Map::placeWeapons() {
    std::cout << "Place weapons stub." << std::endl;
}


Room* Map::getStartRoom() const {
    return rooms[0][0];
}

void Map::displayDebug(Player *player) const {
    std::cout << "Display debug stub." << std::endl;
}


