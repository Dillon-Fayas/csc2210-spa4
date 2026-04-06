//
// Created by spiro on 3/29/2026.
//

#include "weapon.h"
#include "room.h"
#include "game.h"

// Spear

Spear::Spear() {
    name = "Spear";
}

std::string Spear::getName() const {
    return name;
}

bool Spear::use(Room* startRoom, char direction, Game* game) {
    return false;
}


// Fireball

Fireball::Fireball() {
    name = "Fireball";
}

std::string Fireball::getName() const {
    return name;
}

bool Fireball::use(Room* startRoom, char direction, Game* game) {
    return false;
}