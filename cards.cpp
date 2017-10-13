#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

/* *************************************************
   Card class
   ************************************************* */

/* 
   Default constructor for the Card class.
   It could give repeated cards. This is OK.
   Most variations of Blackjack are played with 
   several decks of cards at the same time.
*/

Card::Card(){
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break; 
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break; 
      default: break;
   }

   r = 1 + rand() % 10;  
   switch (r) {
      case  1: rank = AS; break; 
      case  2: rank = DOS; break; 
      case  3: rank = TRES; break; 
      case  4: rank = CUATRO; break; 
      case  5: rank = CINCO; break; 
      case  6: rank = SEIS; break; 
      case  7: rank = SIETE; break; 
      case  8: rank = SOTA; break; 
      case  9: rank = CABALLO; break; 
      case 10: rank = REY; break; 
      default: break;
   }
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const { 
   string suitName;
   switch (suit) {
      case OROS: 
         suitName = "oros"; 
	 break;
      case COPAS: 
         suitName = "copas"; 
	 break; 
      case ESPADAS: 
         suitName = "espadas"; 
	 break;
      case BASTOS: 
         suitName = "bastos"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const { 
   string rankName;
   switch (rank) {
      case AS:
         rankName = "As"; 
	 break; 
      case DOS: 
         rankName = "Dos"; 
	 break; 
      case TRES: 
         rankName = "Tres"; 
	 break; 
      case CUATRO: 
         rankName = "Cuatro"; 
	 break; 
      case CINCO: 
         rankName = "Cinco"; 
	 break; 
      case SEIS: 
         rankName = "Seis"; 
	 break; 
      case SIETE: 
         rankName = "Siete"; 
	 break; 
      case SOTA: 
         rankName = "Sota"; 
	 break; 
      case CABALLO: 
         rankName = "Caballo"; 
	 break; 
      case REY: 
         rankName = "Rey"; 
	 break; 
      default: break;
   }
   return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const { 
    string e_suit_name;
    switch (suit) {
         case OROS:
            e_suit_name = "coins";
        break;
         case COPAS:
            e_suit_name = "cups";
        break;
         case ESPADAS:
            e_suit_name = "spades";
        break;
         case BASTOS:
            e_suit_name = "clubs";
        break;
         default: break;
    }
   return e_suit_name;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const { 
    switch (rank) {
        case AS:
            return "Ace";
        case DOS:
            return "Two";
        case TRES:
            return "Three";
        case CUATRO:
            return "Four";
        case CINCO:
            return "Five";
        case SEIS:
            return "Six";
        case SIETE:
            return "Seven";
        case SOTA:
            return "Jack";
        case CABALLO:
            return "Knight";
        case REY:
            return "King";
        default: break;
    }
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
   return rank < card2.rank;
}

// Accessot function
// Returns the value of each card in terms of points
double Card::get_value() const {
    switch (rank) {
        case AS:
        return 1;
    case DOS:
        return 2;
    case TRES:
        return 3;
    case CUATRO:
        return 4;
    case CINCO:
        return 5;
    case SEIS:
        return 6;
    case SIETE:
        return 7;
    case SOTA:
        return 0.5;
    case CABALLO:
        return 0.5;
    case REY:
        return 0.5;
    default: break;
    }
}

// Prints the card in Spanish and (English)
void Card:: print_card() const {
    cout << "       " << this->get_spanish_rank() << " de " << this->get_spanish_suit() << setw(8) << "(" << this->get_english_rank() << " of " << this->get_english_suit() << ")." << endl;
}



/* *************************************************
   Hand class
   ************************************************* */

/*
Default constructor for Hand class
Sets value to 0
*/
Hand:: Hand() {
    value = 0;
}

/*
Checks if the hand has busted or not
Returns true if busted, false if not
*/
bool Hand:: check_for_bust() {
    if (value > 7.5) {
        return true;
    }
    else return false;
}

/*
Accessor function
Returns the value of the Hand in terms of points
*/
double Hand:: get_value() const {
    return value;
}

/*
Mutator: Adds a card to the Hand
*/
void Hand:: add_card(Card a) {
    cards_in_hand.push_back(a); // Adds the card to the vector of cards
    value = value + a.get_value(); // Increments the value variable 
}

/*
Prints all the cards in the hand in Spanish and (English)
*/
void Hand:: print_hand() const {
    for (int i = 0; i < cards_in_hand.size(); i++)
    {
        cout << "       " << cards_in_hand[i].get_spanish_rank() << " de " << cards_in_hand[i].get_spanish_suit() << setw(8) << " (" << cards_in_hand[i].get_english_rank() << " of " << cards_in_hand[i].get_english_suit() << ")." << endl;
    }
    return;
}


/* *************************************************
   Player class
   ************************************************* */

/*
Checks if the player has beaten the casino
Returns true if income > 1000, false otherwise
*/
bool Player:: check_if_win() const {
        if (money >= 1000)
        {
            return true;
        }
        else return false;
}
 
/*
Checks if the player is broke
Returns true if he is, false otherwise
*/
bool Player:: check_if_lose() const {
        if (money == 0)
        {
            return true;
        }
        else return false;
}
 
/*
Accessor: Gets the player's current balance
Return money
*/
int Player:: get_money() const {
        return money;
}
    
/*
Mutator: Modifies the player's balance based on the success of his bet
*/    
void Player:: bet (int m, int result) {
    if (result == 2) // if he wins
    {
        money += m;
    }
    else if (result == 0) // if he loses
    {
        money -= m;
    
    }
    // if he ties there is no change
}

/*
Overloaded operator <<
Return ostream file with Hand written
*/
ostream& operator << (ostream& a, const Hand& hand)
{
    for (int i = 0; i < hand.cards_in_hand.size(); i++)
    {
        a << "       " << hand.cards_in_hand[i].get_spanish_rank() << " de " << hand.cards_in_hand[i].get_spanish_suit() << setw(8) << " (" << hand.cards_in_hand[i].get_english_rank() << " of " << hand.cards_in_hand[i].get_english_suit() << ")." << endl; // writes the Hand into the ostream file
    }
    return a;
}