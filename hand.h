#include <string>
#include <vector>
#include <fstream>
#include "cards.h"

#ifndef HAND_H
#define HAND_H

using namespace std;

class Hand {
public:
   // A vector of Cards
   Hand(Card a);
   void add_card(Card a);
   bool check_for_bust();
   double get_value() const;

   // You decide what functions you'll need...

private:
   vector<Card> cards_in_hand;
   double value;
};

#endif