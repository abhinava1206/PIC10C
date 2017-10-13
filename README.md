# Siete Y Medio - Spanish Blackjack

## The program simulates a game of Siete y Medio against a dealer/casino. The user starts off with 100 $ and makes bets. He wins if he makes 900$ and loses if he runs out of money.

### Documentation
The program uses 3 main classes: Cards, Player and Hand. Upon initialization, Card generates a random card from the Spanish deck. The class has accessor functions to query the suit and rank in both Spanish and English. The print function displays the card in both languages, and the overloaded operator < returns whether or not a card is greater than another (in terms of rank).
    The Hand class creates a vector of Cards. Its functionality includes adding cards to the deck and computing the value of the hands (in terms of points). The function check_if_bust() checks if the handed has busted or not (gone over 7.5) and the print_hand() function iterates over the cards in the hand and prints them.
The Player class keeps tabs of how much money the user has left. The function bet() updates his wallet as a result of the round with the dealer, and the check_if functions determine whether the player has won or lost the game.


### Test Cases
* Tried bet = 150. Expected result: Program exits. Actual result: Program exits with code (!)
* Tried negative bet. Expected result: Input not accepted. Actual result: Worked (needs to be fixed)