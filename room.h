//
// Created by spiro on 3/29/2026.
//

#ifndef CSC1120_SPA4_ROOM_H
#define CSC1120_SPA4_ROOM_H

#include <string>

class hazard;
class weapon;

class room {
private:
    std::string description;
    room* north;
    room* south;
    room* east;
    room* west;
    hazard* hazard;
    weapon* weapon;
    bool hasTreasure;

public:
    room(std::string description = "");
    ~room();

    void setNeighbors(room* north, room* south, room* east, room* west);
    room* getNeighbor(char direction) const;

    std::string getClues() const;
    bool hasHazard() const;
    bool hasWeapon() const;

    hazard* getHazard() const;
    weapon* getWeapon() const;

    void setHazard(hazard* hazard);
    void setWeapon(weapon* weapon);

};


#endif //CSC1120_SPA4_ROOM_H