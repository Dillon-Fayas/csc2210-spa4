//
// Created by spiro on 3/29/2026.
//

#include <iostream>
#include "hazard.h"
#include "player.h"
#include "game.h"
#include "map.h"
#include "room.h"

// Dragon

Dragon::Dragon() {
    name = "Dragon";
}

std::string Dragon::getClue() const {
    return "You feel intense heat radiating from a nearby chamber.";
}

void Dragon::trigger(Player* player, Game* game) {
    std::cout << "The dragon lunges from the shadows and engulfs you in flames!\n";
    std::cout << "You have been slain by the dragon.\n";
    player->setAlive(false);
}



// Quick sand

QuickSand::QuickSand() {
    name = "Quick Sand";
}

std::string QuickSand::getClue() const {
    return "You notice patches of fine sand drifting across the dungeon floor.";
}

void QuickSand::trigger(Player* player, Game* game) {
    std::cout << "The floor gives way beneath your feet — quicksand!\n";
    std::cout << "You struggle, but the sand pulls you under. You have perished.\n";
    player->setAlive(false);
}


// Gargoyle

Gargoyle::Gargoyle() {
    name = "Gargoyle";
}

std::string Gargoyle::getClue() const {
    return "You hear the heavy flap of stone wings echoing through the corridor.";
}

void Gargoyle::trigger(Player* player, Game* game) {
    std::cout << "A gargoyle drops from the ceiling and seizes you in its claws!\n";
    std::cout << "It carries you through twisting passages and drops you somewhere new.\n";

    Room* newRoom = game->getMap()->getRandomRoom();
    player->setCurrentRoom(newRoom);

    std::cout << "You land hard on cold stone, disoriented. Where are you now?\n";
}