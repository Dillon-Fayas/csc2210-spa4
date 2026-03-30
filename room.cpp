//
// Created by spiro on 3/29/2026.
//

#include <iostream>
#include "room.h"
#include "hazard.h"
#include "weapon.h"

room::room(std::string description) {
    this->description = description;
    north = nullptr;
    south = nullptr;
    east = nullptr;
    west = nullptr;
    hazard = nullptr;
    weapon = nullptr;
    hasTreasure = false;

}


room::~room() {
    delete hazard;
    delete weapon;
}

void room::setNeighbors(room* n, room* s, room* e, room* w) {
    north = n;
    south = s;
    east = e;
    west = w;
}

room* room::getNeighbor(char direction) const {
    switch (direction) {
        case 'n': return north;
        case 's': return south;
        case 'e': return east;
        case 'w': return west;
        default: return nullptr;
    }
}

std::string room::getClues() const {
    return "Clue stub";
}

bool room::hasHazard() const {
    return hazard != nullptr;
}

bool room::hasWeapon() const {
    return weapon != nullptr;
}

hazard* room::getHazard() const {
    return hazard;
}

weapon* room::getWeapon() const {
    return weapon;
}

void room::setHazard(hazard* hazard) {
    this->hazard = hazard;
}

void room::setWeapon(weapon* weapon) {
    this->weapon = weapon;
}