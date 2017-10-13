#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
#include "hand.h"
#include "player.h"
#include <iomanip>
using namespace std;
int bet;

void player_prompts(Player user, Hand &player_hand) {
    bool condition = true;
    cout << "You have $" << user.get_money() << ". Enter bet: ";
    cin >> bet;
    if (bet > user.get_money()) {
        cout << "You don't have enough money.";
        exit(1);
    }
    Card b;
    cout << "Your cards:" << endl;
    player_hand.add_card(b);
    player_hand.print_hand();
    cout << "Your total is " << player_hand.get_value() << ". Do you want another card (y/n)? ";
    char response;
    cin >> response;
    if (response == 'n') {
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
            cout << "Your total is " << player_hand.get_value() << endl;
            condition = false; break;
        }
        cout << "Your total is " << player_hand.get_value() << ". Do you want another card (y/n)? ";
        char response1;
        cin >> response1;
        if (response1 == 'n') {
            condition = false;
        }
    }
}

void dealer_prompts(Hand &dealer_hand) {
        Card a;
        cout << "Dealer's cards: " << endl;
        a.print_card();
        dealer_hand.add_card(a);
        cout << "The dealer's total is " << dealer_hand.get_value() << endl;
        while(dealer_hand.get_value() < 5.5) {
            Card b;
            cout << "New card:" << endl;
            b.print_card(); cout << endl;
            dealer_hand.add_card(b);
            cout << "Dealer's cards:" << endl;
            dealer_hand.print_hand();
            cout << "The dealer's total is " << dealer_hand.get_value() << endl << endl; 
        }
}

int get_result (double player_value, double dealer_value) {
    //double player_value = player_hand.get_value();
    //double dealer_value = dealer_hand.get_value();
    if (player_value > 7.5) {
        return 0;
    }
    else if (dealer_value > 7.5) {
        return 2;
    }
    else if (player_value == dealer_value) {
        return 1;
    }
    else 
    {
        if (player_value > dealer_value) {
            return 2;
        }
        else {
            return 0;
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
        int result = get_result(player_hand.get_value(), dealer_hand.get_value());
        if (result == 2) {
            user.bet(bet, result);
            cout << "You win " << bet << "." << endl;
        }
        else if (result == 0) {
            user.bet(bet, result);
            cout << "Too bad. You lose " << bet << "." << endl;
        }
        else if (result == 1) {
            cout << "Nobody wins!";
        }
        if (user.check_if_lose()) {
            cout << "You have $0. GAME OVER!" << endl << "Come back when you have more money." << endl << endl <<  "BYE!" << endl;;
            q = false;

        }
        if (user.check_if_win()) {
            cout << "Congratulations. You beat the casino!" << endl << endl << "BYE!" << endl;;
            q = false;
        }

    }
   return 0;
}