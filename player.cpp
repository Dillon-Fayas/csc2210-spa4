//
// Created by spiro on 3/29/2026.
//

#include <iostream>
#include "player.h"
#include "room.h"
#include "weapon.h"

Player::Player() {
    currentRoom = nullptr;
    weaponCount = 0;
    alive = true;

    for (int i = 0; i < 3; i++) {
        inventory[i] = nullptr;
    }
}

Player::~Player() {
    for (int i = 0; i < 3; i++) {
        delete inventory[i];
    }
}

void Player::move(char direction) {
    if (currentRoom == nullptr) {
        std::cout << "Player is not in a room." << std::endl;
        return;
    }

    Room* nextRoom = currentRoom->getNeighbor(direction);

    if (nextRoom != nullptr) {
        currentRoom = nextRoom;
        std::cout << "Player moved." << std::endl;
    } else {
        std::cout << "Player cannot move in that direction." << std::endl;
    }
}

void Player::pickUpWeapon() {
    std::cout << "Pick up weapon stub." << std::endl;
}


void Player::useWeapon(int index, char direction) {
    std::cout << "Use weapon stub. Index: " << index << ", direction: " << direction << std::endl;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

bool Player::isAlive() const {
    return alive;
}

void Player::setAlive(bool status) {
    alive = status;
}
