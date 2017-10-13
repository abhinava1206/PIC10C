#include <string>
#include <vector>
#include <fstream>
#include "hand.h"
#include "cards.h"

#ifndef PLAYER_H
#define PLAYER_H


using namespace std;

class Player {
public:
    Player(int m);
    void bet(int m);
    bool check() const;
    Hand dealer_hand();
    int get_money() const;

private:
   int money;
};

#endif