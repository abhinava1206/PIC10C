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
    Player()
    {
        money = 100;
    }
    void bet(int m, int result);
    bool check_if_win() const;
    bool check_if_lose() const;
    int get_money() const;

private:
   int money;
};

#endif