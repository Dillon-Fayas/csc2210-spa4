//
// Created by spiro on 3/29/2026.
//

#ifndef PLAYER_H
#define PLAYER_H

class Room;
class Weapon;

class Player {
private:
    Room* currentRoom;
    Weapon* inventory[3];
    int weaponCount;
    bool alive;

public:
    Player();
    ~Player();

    void move(char direction);
    void pickUpWeapon();
    void useWeapon(int index, char direction);

    Room* getCurrentRoom() const;
    void setCurrentRoom(Room* room);

    bool isAlive() const;
    void setAlive(bool alive);


};


#endif //PLAYER_H