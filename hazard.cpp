//
// Created by spiro on 3/29/2026.
//

#include "hazard.h"
#include "player.h"
#include "game.h"

// Dragon

Dragon::Dragon() {
    name = "Dragon";
}

std::string Dragon::getClue() const {
    return "";
}

void Dragon::trigger(Player* player, Game* game) {

}

// Pit

Pit::Pit() {
    name = "Pit";
}

std::string Pit::getClue() const {
    return "";
}

void Pit::trigger(Player* player, Game* game) {

}


// Bat

Bat::Bat() {
    name = "Bat";
}

std::string Bat::getClue() const {
    return "";
}

void Bat::trigger(Player* player, Game* game) {

}