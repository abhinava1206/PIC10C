#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
#include <iomanip>


using namespace std;

int bet; // defines the global variable bet

/*
Prompts and generates a hand for the user
*/
void player_prompts(Player user, Hand &player_hand) {
    bool condition = true;
    cout << "You have $" << user.get_money() << ". Enter bet: "; // Prompts the user to make a bet
    cin >> bet; // Accepts input from the user
    if (bet > user.get_money() || bet < 0) { // If the user cannot afford the bet
        cout << "You don't have enough money.";
        exit(1);
    }
    Card b; // Generates and initializes a random card 'b'
    cout << "Your cards:" << endl;
    player_hand.add_card(b);
    player_hand.print_hand(); // Prints the hand
    cout << "Your total is " << player_hand.get_value() << ". Do you want another card (y/n)? "; // Asks the user if he wants another card
    char response;
    cin >> response;
    if (response == 'n') { // if no
        condition = false; // does not enter the loop
    }
    while (condition == true) {
        Card a;
        cout << "New card:" << endl; // generates a new card for the user's hand
        a.print_card();
        player_hand.add_card(a);
        cout << "Your cards:" << endl;
        player_hand.print_hand();
        if (player_hand.get_value() > 7.5)  { // if the player busts
            cout << "Your total is " << player_hand.get_value() << endl;
            condition = false; break; // exit the loop
        }
        cout << "Your total is " << player_hand.get_value() << ". Do you want another card (y/n)? ";
        char response1;
        cin >> response1;
        if (response1 == 'n') {
            condition = false; // sentinel value for the loop
        }
    }
}

/*
Generates a hand for the dealer
*/
void dealer_prompts(Hand &dealer_hand) {
        Card a; // Generates a random card
        cout << "Dealer's cards: " << endl;
        a.print_card(); // Displays the dealer's card
        dealer_hand.add_card(a); // Adds it to the hand
        cout << "The dealer's total is " << dealer_hand.get_value() << endl;
        while(dealer_hand.get_value() < 5.5) { // Dealer keeps drawing as long as total value < 5.5
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
    if (player_value > 7.5) { // If the player busts, includes House Advantage
        return 0; // 0 = loss
    }
    else if (dealer_value > 7.5) { // Dealer busts, player doesn't bust
        return 2; // 2 = win
    }
    else if (player_value == dealer_value) { // In case of a tie
        return 1; // 1 = tie
    }
    else 
    {
        if (player_value > dealer_value) { // Player is closer to 7.5
            return 2; // win
        }
        else {
            return 0; // loss
        }
    }
}

int main() {
    ofstream OutputFile("gamelog.txt");
    srand(time(NULL)); // changes seed of the pseudorandom numbers
    Player user; // initializes player
    bool q = true;
    int game_count = 1;
    while (q) { // Loops through until the player either wins or loses the game
        Hand player_hand, dealer_hand;
        player_prompts(user, player_hand);
        dealer_prompts(dealer_hand);
        OutputFile << "------------------------------------------------" << endl << endl;
        OutputFile << "Game number: " << game_count << "        Money left: " << user.get_money() << endl; // writes to gamelog file
        OutputFile << "Bet: " << bet << endl << endl;
        OutputFile << "Your cards:" << endl;
        OutputFile << player_hand << endl;
        OutputFile << "Your total: " << player_hand.get_value() << endl << endl;
        OutputFile << "Dealer's cards: " << endl;
        OutputFile << dealer_hand << endl;
        OutputFile << "Dealer's total is " << dealer_hand.get_value() << endl << endl;
        game_count++;
        int result = get_result(player_hand.get_value(), dealer_hand.get_value()); // to determine the result of the round
        if (result == 2) { // win
            user.bet(bet, result);
            cout << "You win " << bet << "." << endl;


        }
        else if (result == 0) { // loss
            user.bet(bet, result);
            cout << "Too bad. You lose " << bet << "." << endl;
        }
        else if (result == 1) { // tie
            cout << "Nobody wins!";
        }
        if (user.check_if_lose()) { // checks if the user has lost
            cout << "You have $0. GAME OVER!" << endl << "Come back when you have more money." << endl << endl <<  "BYE!" << endl;;
            q = false;

        }
        if (user.check_if_win()) { // checks if the user has won
            cout << "Congratulations. You beat the casino!" << endl << endl << "BYE!" << endl;;
            q = false;
        }

    }
   return 0;
}