#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
#include "hand.h"
#include "player.h"
using namespace std;
int bet;

void player_prompts(Player user, Hand &player_hand) {
    bool condition = true;
    cout << "You have $" << user.get_money() << ". Enter bet ";
    cin >> bet;
    if (bet > user.get_money()) {
        condition = false;
    }
    while (condition == true) {
        Card a;
        cout << "New card:" << endl;
        a.print_card();
        player_hand.add_card(a);
        cout << "Your cards:" << endl;
        player_hand.print_hand();
        if (player_hand.get_value() > 7.5)  {
            cout << "Your total is " << player_hand.get_value();
            condition = false;
        }
        cout << "Your total is " << player_hand.get_value() << ". Do you want another card (y/n)? ";
        char response;
        cin >> response;
        if (response == 'n') {
            condition = false;
        }
    }
}

void dealer_prompts(Hand &dealer_hand) {
        Card a;
        cout << "Dealer's cards: ";
        a.print_card();
        cout << "The dealer's total is " << dealer_hand.get_value() << endl;
        while(dealer_hand.get_value() < 5.5) {
            Card b;
            dealer_hand.add_card(b);
            cout << "Dealer's cards:" << endl;
            dealer_hand.print_hand();
            cout << "The dealer's total is " << dealer_hand.get_value() << endl; 
        }
}

bool get_result (double player_value, double dealer_value) {
    //double player_value = player_hand.get_value();
    //double dealer_value = dealer_hand.get_value();
    if (player_value > 7.5) {
        return false;
    }
    else if (dealer_value > 7.5) {
        return true;
    }
    else if (player_value == dealer_value) {
        return NULL;
    }
    else 
    {
        if (player_value > dealer_value) {
            return true;
        }
        else {
            return false;
        }
    }
}

int main(){
    srand(time(NULL));
    Player user;
    bool q = true;
    while (q) {
        Hand player_hand, dealer_hand;
        player_prompts(user, player_hand);
        dealer_prompts(dealer_hand);
        bool result = get_result(player_hand.get_value(), dealer_hand.get_value());
        if (result == true) {
            user.bet(bet, result);
            cout << "You win " << bet;
        }
        else if (result == false) {
            user.bet(bet, result);
            cout << "Too bad. You lose " << bet << endl;
        }
        else if (!result) {
            cout << "Nobody wins!";
        }
        if (user.check_if_lose()) {
            cout << "You have $0. GAME OVER!" << endl << "Come back when you have more money." << endl << endl <<  "BYE!";
            q = false;

        }
        if (user.check_if_win()) {
            cout << "Congratulations. You beat the casino!" << endl << endl << "BYE!";
            q = false;
        }

    }
    
   return 0;
}