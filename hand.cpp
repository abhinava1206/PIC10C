#include "hand.h"
#include "cards.h"
#include <iostream>

using namespace std;

Hand:: Hand(Card a) {
    cards_in_hand.push_back(a);
    value = a.get_value();
}

bool Hand:: check_for_bust() {
    if (value > 7.5) {
        return true;
    }
    else return false;
}

double Hand:: get_value() const {
    return value;
}

void Hand:: add_card(Card a) {
    cards_in_hand.push_back(a);
    value = value + a.get_value();
}

