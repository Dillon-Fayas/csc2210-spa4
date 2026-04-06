//
// Created by spiro on 3/29/2026.
//

#include <iostream>
#include "room.h"
#include "hazard.h"
#include "weapon.h"

Room::Room(std::string description) {
    this->description = description;
    north = nullptr;
    south = nullptr;
    east = nullptr;
    west = nullptr;
    hazard = nullptr;
    weapon = nullptr;
    hasTreasure = false;

}


Room::~Room() {
    delete hazard;
    delete weapon;
}

void Room::setNeighbors(Room* n, Room* s, Room* e, Room* w) {
    north = n;
    south = s;
    east = e;
    west = w;
}

Room* Room::getNeighbor(char direction) const {
    switch (direction) {
        case 'n': return north;
        case 's': return south;
        case 'e': return east;
        case 'w': return west;
        default: return nullptr;
    }
}

std::string Room::getClues() const {
    return "Clue stub";
}

bool Room::hasHazard() const {
    return hazard != nullptr;
}

bool Room::hasWeapon() const {
    return weapon != nullptr;
}

Hazard* Room::getHazard() const {
    return hazard;
}

Weapon* Room::getWeapon() const {
    return weapon;
}

void Room::setHazard(Hazard* hazard) {
    this->hazard = hazard;
}

void Room::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}