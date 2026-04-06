//
// Created by spiro on 3/29/2026.
//

#ifndef MAP_H
#define MAP_H

class Room;
class Player;

class Map {
private:
    Room *rooms[5][5];
    int rows;
    int cols;

public:
    Map(int rows = 5, int cols = 5);
    ~Map();

    void buildRooms();
    void connectRooms();
    void placeHazards();
    void placeWeapons();
    Room* getStartRoom() const;
    void displayDebug(Player *player) const;


};


#endif //MAP_H