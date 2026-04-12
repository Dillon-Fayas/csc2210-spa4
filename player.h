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
    int javelinCount;
    bool alive;

public:
    Player();
    ~Player();

    void move(char direction);
    void pickUpWeapon();
    void useWeapon(int index, char direction);

    int getJavelinCount() const;
    void addJavelin();
    void decreaseJavelin();

    bool hasInventoryWeapon(int slot) const;
    Weapon* getInventoryWeapon(int slot) const;
    void removeInventoryWeapon(int slot);

    Room* getCurrentRoom() const;
    void setCurrentRoom(Room* room);

    bool isAlive() const;
    void setAlive(bool alive);

    void printStatus() const;


};


#endif //PLAYER_H