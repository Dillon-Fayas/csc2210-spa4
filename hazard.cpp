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


// Gargoyle

Gargoyle::Gargoyle() {
    name = "Gargoyle";
}

std::string Gargoyle::getClue() const {
    return "";
}

void Gargoyle::trigger(Player* player, Game* game) {

}