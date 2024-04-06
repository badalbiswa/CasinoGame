/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
#include <ctime>
#include "Blackjack.h"
#include "Text.h"
#include "Board.h"
#include "Game.h"


int Game::blackJack() {
  std::cout << "RULES" << std::endl;
  std::cout
      << "Blackjack (21) is a battle against the dealer to reach "
      << "21 without going over. Cards are worth their face value, "
      << "face cards are 10, and Aces are 1 or 11. You get two face-up "
      << "cards, the dealer gets one face-up and one face-down. Hit for "
      << "more cards, stand to stay. Don't bust (go over 21)! After you "
      << "stand, the dealer reveals their hidden card and hits until they "
      << "reach 17 or more. Whoever is closest to 21 without busting wins. "
      << "Getting an Ace and a 10-value card on the first deal is Blackjack, "
      << "an instant win!"
      << std::endl;

  std::cout << "\n------------------------------------------\n";
  std::cout << "       Welcome to Blackjack!\n";
  std::cout << "------------------------------------------\n";
  // initial set up (this can be changed depending on the need)
  int NumPlayer = 1;  // number of players
  int NumDeck = 5;    // number of deck of cards in the shoe
  unsigned int Seed = 100;      // Seed for fixed seed case
  int initialAccountValue = 1000;  //account value for each player
  bool useTextSymbol = false;
  // whether to use Unicode symbol or text for suits

  // initialize text graphics and accounting
  Text myText(NumPlayer, initialAccountValue, useTextSymbol);
  myText.printWelcomeMessage();  // print welcome message
  myText.accountSetup(User.getChips());  //setup account
  myText.printAccount();

  // set seed
  Seed = static_cast<unsigned int>(time(nullptr));

  // initialize board setup and play related
  Board myBoard(NumPlayer, NumDeck, Seed);
  myBoard.createBoard();

  std::vector < Outcome > result;
  // result vector for each play
  while (myText.playerBetInput()) {
    myBoard.initializeBoard(myText);
    // at each play initialize player and board
    myBoard.runGame(myText, result);  // run game
    result.clear();  // clear result for next play
    myText.printAccount();  // print account status
  }
  User.updateRoom(getCurrentRoom(curRoom.getN()));
  curRoom = User.getRoom();
  return myText.returnChips();
}
