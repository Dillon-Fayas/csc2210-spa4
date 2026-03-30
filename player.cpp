//
// Created by spiro on 3/29/2026.
//

#include <iostream>
#include "player.h"
#include "room.h"
#include "weapon.h"

player::player() {
    currentRoom = nullptr;
    weaponCount = 0;
    alive = true;

    for (int i = 0; i < 3; i++) {
        inventory[i] = nullptr;
    }
}

player::~player() {
    for (int i = 0; i < 3; i++) {
        delete inventory[i];
    }
}

void player::move(room* destination) {
    if (currentRoom == nullptr) {
        std::cout << "Player is not in a room." << std::endl;
        return;
    }

    room* nextRoom = currentRoom->getNeighbor(direction);

    if (nextRoom != nullptr) {
        currentRoom = nextRoom;
        std::cout << "Player moved." << std::endl;
    } else {
        std::cout << "Player cannot move in that direction." << std::endl;
    }
}

void player::pickUpWeapon() {
    std::cout << "Pick up weapon stub." << std::endl;
}


void player::useWeapon(int index, char direction) {
    std::cout << "Use weapon stub. Index: " << index << ", direction: " << direction << std::endl;
}

room* player::getCurrentRoom() const {
    return currentRoom;
}

void player::setCurrentRoom(room* room) {
    currentRoom = room;
}

bool player::isAlive() const {
    return alive;
}

void player::setAlive(bool status) {
    alive = status;
}
