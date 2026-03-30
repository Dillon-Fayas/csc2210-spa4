//
// Created by spiro on 3/29/2026.
//

#ifndef CSC1120_SPA4_MAP_H
#define CSC1120_SPA4_MAP_H

class room;
class player;

class map {
private:
    room *rooms[5][5];
    int rows;
    int cols;

public:
    map(int rows = 5, int cols = 5);
    ~map();

    void buildRooms();
    void connectRooms();
    void placeHazards();
    void placeWeapons();
    room* getStartRoom() const;
    void displayDebug(player *player) const;


};


#endif //CSC1120_SPA4_MAP_H