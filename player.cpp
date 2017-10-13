#include "player.h"
#include "hand.h"
#include "cards.h"
#include <iostream>
#include <iomanip>

using namespace std;

Player:: Player(int m) {
    money = m;
}

bool Player:: check() const {
    if (money == 0 | money >= 1000)
    {
        return true;
    }
    else return false;
}

Hand Player:: dealer_hand() {
    Card a;
    Hand dealer(a);
    while(dealer.get_value() <= 5.5) {
        Card b;
        dealer.add_card(b);
        cout << "Dealer's cards:" << endl;
        dealer.print_hand();
        cout << "The dealer's total is " << dealer.get_value() << endl; 
    }
    return dealer;
}

int Player:: get_money() const {
    return money;
}


void Player:: bet(int m, bool result) {
    if (result = true)
    {
        money += m;
    }
    else 
    {
        money -= m;
    }
}



