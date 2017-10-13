#include "hand.h"
#include "cards.h"
#include <iostream>
#include <iomanip>

using namespace std;

Hand:: Hand() {
    value = 0;
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

void Hand:: print_hand() const {
    for (int i = 0; i < cards_in_hand.size(); i++)
    {
        cout << setw(8) << cards_in_hand[i].get_spanish_rank() << " de " << cards_in_hand[i].get_spanish_suit() << setw(8) << " (" << cards_in_hand[i].get_english_rank() << " of " << cards_in_hand[i].get_english_suit() << ")" << endl;
    }
    return;
}