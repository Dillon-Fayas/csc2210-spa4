//
// Created by spiro on 3/29/2026.
//

#ifndef CSC1120_SPA4_PLAYER_H
#define CSC1120_SPA4_PLAYER_H

class room;
class weapon;

class player {
private:
    room* currentRoom;
    weapon* inventory[3];
    int weaponCount;
    bool alive;

public:
    player();
    ~player();

    void move(char direction);
    void pickUpWeapon();
    void useWeapon(int index, char direction);

    room* getCurrentRoom() const;
    void setCurrentRoom(room* room);

    bool isAlive() const;
    void setAlive(bool alive);


};


#endif //CSC1120_SPA4_PLAYER_H