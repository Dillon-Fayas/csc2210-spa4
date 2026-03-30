#include <iostream>

int main() {
    std::cout << "Welcome to The Dragon Game!\n\n";

    std::cout << "Deep beneath the earth lies a dangerous dungeon filled with deadly traps, mysterious magic, "
        << "and one legendary beast, the dragon. You have entered this dungeon with one goal: "
        << "find and slay the dragon before it kills you.\n\n";

    std::cout << "As you explore the dungeon, you will move from room to room using the directions north, south, east, "
        << "and west. But be careful, the dungeon is filled with hazards. If you step into the dragon's chamber, "
        << "you will be killed instantly. Hidden patches of quicksand can pull you under, and lurking gargoyles "
        << "may seize you and carry you to a random room.\n\n";

    std::cout << "To survive, you must rely on the clues around you. If the dragon is nearby, you will feel intense heat. "
        << "If quicksand is close, you will see signs of sand on the ground. If gargoyles are near, you will hear "
        << "loud flapping. Use these warnings carefully to figure out where danger is hiding.\n\n";

    std::cout << "You begin your journey with five javelins, which can be thrown into adjacent rooms. As you explore, "
        << "you may also discover more javelins, fireball scrolls, and ice spike scrolls. Fireball and ice spike "
        << "scrolls can travel through multiple rooms in one direction. However, be warned: if you miss with any "
        << "weapon, the dragon will flee and move to a random room.\n\n";

    std::cout << "Your mission is simple:\n";

    std::cout << "Explore the dungeon. Avoid its hazards. Use logic to track the dragon. Defeat it before it defeats you.\n\n";

    std::cout << "Good luck, hunter.\n";

    std::cout << "Controls:\n\n";
    std::cout << "n = move north\n";
    std::cout << "s = move south\n";
    std::cout << "e = move east\n";
    std::cout << "w = move west\n";
    std::cout << "j = throw a javelin\n";
    std::cout << "f = cast a fireball scroll\n";
    std::cout << "i = cast an ice spike scroll\n";
    std::cout << "h = show help\n";
    std::cout << "m = toggle debug mode\n";
    std::cout << "q = quit the game\n";

    return 0;
}