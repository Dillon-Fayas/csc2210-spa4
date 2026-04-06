//
// Created by spiro on 3/29/2026.
//

#ifndef CSC1120_SPA4_ROOM_H
#define CSC1120_SPA4_ROOM_H

#include <string>

class Hazard;
class Weapon;

class Room {
private:
    std::string description;
    Room* north;
    Room* south;
    Room* east;
    Room* west;
    Hazard* hazard;
    Weapon* weapon;
    bool hasTreasure;

public:
    Room(std::string description = "");
    ~Room();

    void setNeighbors(Room* north, Room* south, Room* east, Room* west);
    Room* getNeighbor(char direction) const;

    std::string getClues() const;
    bool hasHazard() const;
    bool hasWeapon() const;

    Hazard* getHazard() const;
    Weapon* getWeapon() const;

    void setHazard(Hazard* hazard);
    void setWeapon(Weapon* weapon);

};


#endif //CSC1120_SPA4_ROOM_H