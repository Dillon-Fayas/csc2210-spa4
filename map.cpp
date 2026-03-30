//
// Created by spiro on 3/29/2026.
//

#include <iostream>
#include <string>
#include "map.h"
#include "room.h"
#include "player.h"


map::map(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            rooms[r][c] = nullptr;
        }
    }
}

map::~map() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            delete rooms[r][c];
        }
    }
}

void map::buildRooms() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            rooms[r][c] = new room("A dark dungeon room");
        }
    }
}

void map::connectRooms() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            room* north = (r > 0) ? rooms[r - 1][c] : nullptr;
            room* south = (r < rows - 1) ? rooms[r + 1][c] : nullptr;
            room* east = (c < cols - 1) ? rooms[r][c + 1] : nullptr;
            room* west = (c > 0) ? rooms[r][c - 1] : nullptr;

            rooms[r][c]-> setNeighbors(north, south, east, west);
        }
    }
}

void map::placeHazards() {
    std::cout << "Place hazards stub." << std::endl;
}

void map::placeWeapons() {
    std::cout << "Place weapons stub." << std::endl;
}


room* map::getStartRoom() const {
    return rooms[0][0];
}

void map::displayDebug(player *player) const {
    std::cout << "Display debug stub." << std::endl;
}


