/* *************************************
   Ricardo Salazar, February 26, 2015

   Interface of a simple Card class
   ************************************* */

   #include <string>
   #include <vector>
   #include <fstream>
   #include <iomanip>
   #include <ctime>
   #include <cstdlib>


   #ifndef CARDS_H
   #define CARDS_H
   
   using namespace std;
   
   enum suit_t {OROS, COPAS, ESPADAS, BASTOS};
   
      /*
      The values for this type start at 0 and increase by one 
      afterwards until they get to SIETE. 
      The rank reported by the function Card::get_rank() below is 
      the value listed here plus one.
      E.g: 
      The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
      The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
      */
   enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA=9, CABALLO=10, REY=11};


   
   class Card {
      public: 
         // Constructor assigns random rank & suit to card.
         Card();
         
         // Accessors 
         string get_spanish_suit() const;
         string get_spanish_rank() const; 
   
         /* 
            These are the only functions you'll need to code 
            for this class. See the implementations of the two 
        functions above to get an idea of how to proceed.
         */
         string get_english_suit() const;
         string get_english_rank() const; 
   
         // Converts card rank to number.
         // The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
         int get_rank() const;
         void print_card() const;
         // Compare rank of two cards. E.g: Eight<Jack is true.
         // Assume Ace is always 1. 
         // Useful if you want to sort the cards.
         bool operator < (Card card2) const;

         double get_value() const;
   
   private:
         suit_t suit;
         rank_t rank;
   };

/****************************
 @class Hand
 @brief
 This class is made to store hands in siete y medio as a vector of the card class
******************************/
   class Hand {
public:
   Hand(); // default constructor
   void add_card(Card a); // adds a card to the hand
   bool check_for_bust(); // checks if the hand has busted
   double get_value() const; // accessor 
    void print_hand() const; 


private:
   vector<Card> cards_in_hand; // A vector of Cards
   double value;
};


/**********************
@Class Player
@Brief
This class stores the amount of money the player has and updates it based on the success of his bets against the dealer 
***********************/
class Player {
public:
    Player() // Default constructor
    {
        money = 100;
    }
    void bet(int m, int result); // Mutator: updates the player's wallet based on the success of his bet
    bool check_if_win() const; // Checks if the player has beaten the casino
    bool check_if_lose() const; // Checks if the player is broke
    int get_money() const; // Accessor: returns the remaining money the player has

private:
   int money;
};


   #endif 