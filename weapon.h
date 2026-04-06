//
// Created by spiro on 3/29/2026.
//

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Room;
class Game;

class Weapon {
protected:
    std::string name;

public:
    Weapon() = default;
    virtual ~Weapon() = default;
    virtual bool use(Room* startRoom, char direction, Game* game) = 0;
    virtual std::string getName() const = 0;
};

class Spear : public Weapon {
public:
    Spear();
    ~Spear() override = default;

    bool use(Room* startRoom, char direction, Game* game) override;
    std::string getName() const override;
};

class Fireball : public Weapon {
public:
    Fireball();
    ~Fireball() override = default;

    bool use(Room* startRoom, char direction, Game* game) override;
    std::string getName() const override;
};

#endif //WEAPON_H