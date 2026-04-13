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
    javelinCount = 5;
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
        std::cout << "You are not in a room." << std::endl;
        return;
    }

    Room* nextRoom = currentRoom->getNeighbor(direction);

    if (nextRoom != nullptr) {
        currentRoom = nextRoom;
        std::cout << "You moved." << std::endl;
        switch (direction) {
            case 'n': std::cout << "North" << std::endl; break;
            case 's': std::cout << "South" << std::endl; break;
            case 'e': std::cout << "East" << std::endl; break;
            case 'w': std::cout << "West" << std::endl; break;
        }
    } else {
        std::cout << "You cannot move in that direction." << std::endl;
    }
}

void Player::pickUpWeapon() {
    std::cout << "Pick up weapon stub." << std::endl;
    if (currentRoom == nullptr || !currentRoom->hasWeapon()) {
        return;
    }

    Weapon* w = currentRoom->getWeapon();

    if (w->getName() == "Spear") {
        javelinCount++;
        std::cout << "You pick up a javelin. Javelins: " << javelinCount << "\n";
        currentRoom->setWeapon(nullptr);
        delete w;
        return;
    }


    if (weaponCount < 3) {
        inventory[weaponCount] = w;
        weaponCount++;
        std::cout << "You pick up a " << w->getName() << ".\n";
        currentRoom->setWeapon(nullptr);
    }else {
        std::cout << "Your inventory is full. You leave the " << w->getName() << ".\n";
    }
}


void Player::useWeapon(int index, char direction) {
    std::cout << "Use weapon stub. Index: " << index << ", direction: " << direction << std::endl;
    if (index == 0) {
        if (javelinCount <= 0) {
            std::cout << "You don't have any javelins left.\n";
            return;
        }
        javelinCount--;
    } else {
        int slot = index - 1;
        if (slot < 0 || slot >= 3 || inventory[slot] == nullptr) {
            std::cout << "You don't have that weapon.\n";
            return;
        }
    }
}

int Player::getJavelinCount() const {
    return javelinCount;
}

void Player::addJavelin() {
    javelinCount++;
}

void Player::decreaseJavelin() {
    if (javelinCount > 0) javelinCount--;
}

bool Player::hasInventoryWeapon(int slot) const {
    if (slot < 0 || slot >= 3) return false;
    return inventory[slot] != nullptr;
}

Weapon *Player::getInventoryWeapon(int slot) const {
    if (slot < 0 || slot >= 3) return nullptr;
    return inventory[slot];
}

void Player::removeInventoryWeapon(int slot) {
    if (slot < 0 || slot >= 3) return;
    delete inventory[slot];
    inventory[slot] = nullptr;
    weaponCount--;
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

void Player::printStatus() const {
    std::cout << "Javelins: " << javelinCount;
    for (int i = 0; i < 3; i++) {
        if (inventory[i] != nullptr) {
            std::cout << "  |  " << inventory[i]->getName();
        }
    }
    std::cout << "\n";
}
