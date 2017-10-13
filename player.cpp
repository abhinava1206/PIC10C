#include "player.h"
#include "hand.h"
#include "cards.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool Player:: check_if_win() const {
    if (money >= 1000)
    {
        return true;
    }
    else return false;
}

bool Player:: check_if_lose() const {
    if (money == 0)
    {
        return true;
    }
    else return false;
}

int Player:: get_money() const {
    return money;
}


void Player:: bet (int m, bool result) {
    if (result == true)
    {
        money += m;
    }
    else 
    {
        money -= m;
    }
}



