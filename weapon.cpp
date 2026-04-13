//
// Created by spiro on 3/29/2026.
//

#include "weapon.h"
#include "room.h"
#include "game.h"
#include "hazard.h"

static bool travelAndCheck(Room* startRoom, char direction, int maxSteps = -1) {
    Room* current = startRoom->getNeighbor(direction);
    int steps = 0;

    while (current != nullptr) {
        if (maxSteps >= 0 && steps >= maxSteps) break;

        if (current->hasHazard()) {
            Dragon* d = dynamic_cast<Dragon*>(current->getHazard());
            if (d != nullptr) return true;
        }

        current = current->getNeighbor(direction);
        ++steps;
    }
    return false;
}

// Spear

Spear::Spear() {
    name = "Spear";
}

std::string Spear::getName() const {
    return name;
}

bool Spear::use(Room* startRoom, char direction, Game* game) {
    return travelAndCheck(startRoom, direction, 1);
}


// Fireball

Fireball::Fireball() {
    name = "Fireball";
}

std::string Fireball::getName() const {
    return name;
}

bool Fireball::use(Room* startRoom, char direction, Game* game) {
    return travelAndCheck(startRoom, direction, -1);
}


// IceSpike

IceSpike::IceSpike() {
    name = "IceSpike";
}

std::string IceSpike::getName() const {
    return name;
}

bool IceSpike::use(Room* startRoom, char direction, Game* game) {
    return travelAndCheck(startRoom, direction, -1);
}