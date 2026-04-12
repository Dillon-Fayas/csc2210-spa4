//
// Created by spiro on 3/29/2026.
//

#ifndef HAZARD_H
#define HAZARD_H

#include <string>

class Player;
class Game;

class Hazard {
protected:
    std::string name;

public:
    Hazard() = default;
    virtual ~Hazard() = default;
    virtual std::string getClue() const = 0;
    virtual void trigger(Player* player, Game* game) = 0;
    std::string getName() const {return name;}
};

class Dragon : public Hazard {
public:
    Dragon();
    ~Dragon() override = default;

    std::string getClue() const override;
    void trigger(Player* player, Game* game) override;
};

class Pit : public Hazard {
public:
    Pit();
    ~Pit() override = default;

    std::string getClue() const override;
    void trigger(Player* player, Game* game) override;
};

class Gargoyle : public Hazard {
public:
    Gargoyle();
    ~Gargoyle() override = default;

    std::string getClue() const override;
    void trigger(Player* player, Game* game) override;
};

#endif //HAZARD_H