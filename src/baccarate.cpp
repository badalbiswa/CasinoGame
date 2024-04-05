/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#include "Card.h"
#include "Game.h"
#include <vector>
#include <iostream>

class Baccarat {
 private:
  Deck deck;
  std::vector<Card> playerHand;
  std::vector<Card> bankerHand;
  int playerChips;
  int totalWinnings;
  bool gameOver;
  int currentBet;
  int betChoice;

 public:
  Baccarat(int initialChips, int initialWinnings);
  void startRound();
  void dealInitialHands();
  void drawPlayerThirdCard();
  void drawBankerThirdCard(const Card &playerThirdCard);
  int sumHand(const std::vector<Card> &hand);
  void evaluateHands();
  void displayHand(const std::vector<Card> &hand) const;
  const std::vector<Card>& getPlayerHand() const;
  int getPlayerChips() const;
  int getTotalWinnings() const;
  bool isGameOver() const;
  void placeBet(int betAmount, int choice);
  int getCurrentBet() const;
};

Baccarat::Baccarat(int initialChips, int initialWinnings)
    :
    playerChips(initialChips),
    totalWinnings(initialWinnings),
    gameOver(false),
    currentBet(0),
    betChoice(0) {
  deck.shuffle();
}

void Baccarat::startRound() {
  if (playerChips <= 0) {
    gameOver = true;
    std::cout << "You have run out of chips! Game over." << std::endl;
    return;
  }
  deck.shuffle();  // Shuffle the deck at the start of each round
  dealInitialHands();  // Deal initial hands after shuffling
}

void Baccarat::dealInitialHands() {
  playerHand.clear();
  bankerHand.clear();
  playerHand.push_back(deck.dealCard());
  bankerHand.push_back(deck.dealCard());
  playerHand.push_back(deck.dealCard());
  bankerHand.push_back(deck.dealCard());
}

void Baccarat::drawPlayerThirdCard() {
  int playerSum = sumHand(playerHand);
  if (playerSum <= 5) {
    playerHand.push_back(deck.dealCard());
  }
}

void Baccarat::drawBankerThirdCard(const Card &playerThirdCard) {
  int bankerSum = sumHand(bankerHand);
  if (bankerSum <= 2) {
    bankerHand.push_back(deck.dealCard());
  } else if (bankerSum == 3 && playerThirdCard.rank != Rank::EIGHT) {
    bankerHand.push_back(deck.dealCard());
  } else if (bankerSum == 4
      && (playerThirdCard.rank == Rank::TWO
          || playerThirdCard.rank == Rank::THREE
          || playerThirdCard.rank == Rank::FOUR
          || playerThirdCard.rank == Rank::FIVE
          || playerThirdCard.rank == Rank::SIX
          || playerThirdCard.rank == Rank::SEVEN)) {
    bankerHand.push_back(deck.dealCard());
  } else if (bankerSum == 5
      && (playerThirdCard.rank == Rank::FOUR
          || playerThirdCard.rank == Rank::FIVE
          || playerThirdCard.rank == Rank::SIX
          || playerThirdCard.rank == Rank::SEVEN)) {
    bankerHand.push_back(deck.dealCard());
  } else if (bankerSum == 6
      && (playerThirdCard.rank == Rank::SIX
          || playerThirdCard.rank == Rank::SEVEN)) {
    bankerHand.push_back(deck.dealCard());
  }
}

int Baccarat::sumHand(const std::vector<Card> &hand) {
  int sum = 0;
  for (const auto &card : hand) {
    int cardValue = 0;
    if (card.rank == Rank::JACK || card.rank == Rank::QUEEN
        || card.rank == Rank::KING) {
      cardValue = 0;
    } else if (card.rank == Rank::ACE) {
      cardValue = 1;
    } else {
      cardValue = static_cast<int>(card.rank);
    }
    sum += cardValue;
  }
  return sum % 10;
}

void Baccarat::displayHand(const std::vector<Card> &hand) const {
  for (const auto &card : hand) {
    std::cout << card.rank << " ";
  }
  std::cout << std::endl;
}

const std::vector<Card>& Baccarat::getPlayerHand() const {
  return playerHand;
}

int Baccarat::getPlayerChips() const {
  return playerChips;
}

int Baccarat::getTotalWinnings() const {
  return totalWinnings;
}

bool Baccarat::isGameOver() const {
  return gameOver;
}

void Baccarat::placeBet(int betAmount, int choice) {
  if (betAmount <= playerChips) {
    currentBet = betAmount;
    playerChips -= betAmount;
    betChoice = choice;
  } else {
    std::cout << "Insufficient chips to place this bet." << std::endl;
  }
}

void Baccarat::evaluateHands() {
  int playerSum = sumHand(playerHand);
  int bankerSum = sumHand(bankerHand);

  std::cout << "Player's Hand: ";
  displayHand(playerHand);
  std::cout << "Player's Points: " << playerSum << std::endl;

  std::cout << "Banker's Hand: ";
  displayHand(bankerHand);
  std::cout << "Banker's Points: " << bankerSum << std::endl;

  if (betChoice == 1) {  // Player bet
    if (playerSum > bankerSum) {
      std::cout << "Player wins!" << std::endl;
      playerChips += 2 * currentBet;
      totalWinnings += currentBet;
    } else if (bankerSum > playerSum) {
      std::cout << "Banker wins!" << std::endl;
      totalWinnings -= currentBet;
    } else {
      std::cout << "It's a tie!" << std::endl;
      playerChips += currentBet;
    }
  } else if (betChoice == 2) {  // Tie bet
    if (playerSum == bankerSum) {
      std::cout << "It's a tie!" << std::endl;
      playerChips += 8 * currentBet;  // 8:1 payout for tie
      totalWinnings += 8 * currentBet;
    } else {
      std::cout << "You lose!" << std::endl;
      totalWinnings -= currentBet;
    }
  } else if (betChoice == 3) {  // Banker bet
    if (bankerSum > playerSum) {
      std::cout << "Banker wins!" << std::endl;
      playerChips += 2 * currentBet;  // 1:1 payout with commission deducted
      totalWinnings += currentBet - (currentBet * 0.05);  // Commission is 5%
    } else if (playerSum > bankerSum) {
      std::cout << "Player wins!" << std::endl;
      totalWinnings += currentBet;
    } else {
      std::cout << "It's a tie!" << std::endl;
    }
  }
}

int Game::baccarate() {
  std::cout
      << "This Baccarat simulation code implements the following gameplay. Players start with a set amount of chips and can wager on the outcome of each round. The player and banker each receive two cards. Cards are valued with face cards and tens as zero, aces as one, and others by their pip value, with only the ones digit counting in the total. The player receives a third card if their hand value is five or less. The banker draws a third card based on their hand total and the player's third card (if drawn), following specific rules. The hand closest to nine without going over wins. Winning bets on the player or banker pay 1:1 (with a commission deducted from banker wins), while winning tie bets pay 8:1. The game continues until the player runs out of chips or chooses to stop."
      << std::endl;

  std::cout << "\n------------------------------------------\n";
  std::cout << "       Welcome to Baccarat!\n";
  std::cout << "------------------------------------------\n";

  int initialWinnings = 0;

  Baccarat game(User.getChips(), initialWinnings);

  int choice;
  do {
    int betAmount;
    int betType;

    game.startRound();  // Start a new round
    if (game.isGameOver())
      break;

    std::cout << "Player's chips remaining: " << game.getPlayerChips()
        << std::endl;

    std::cout << "Place your bet amount: ";
    std::cin >> betAmount;

    std::cout << "Place your bet type:" << std::endl;
    std::cout << "1. Bet on Player" << std::endl;
    std::cout << "2. Bet on Tie" << std::endl;
    std::cout << "3. Bet on Banker" << std::endl;
    std::cin >> betType;

    game.placeBet(betAmount, betType);

    if (game.isGameOver())
      break;

    game.drawPlayerThirdCard();
    const std::vector<Card> &playerHand = game.getPlayerHand();
    // Assuming playerSum is 5, and banker decides whether to draw a third card based on player's third card
    Card playerThirdCard = playerHand.back();
    game.drawBankerThirdCard(playerThirdCard);
    game.evaluateHands();

    std::cout << "Player's chips remaining: " << game.getPlayerChips()
        << std::endl;

    if (game.getPlayerChips() <= 0) {
      std::cout << "You have run out of chips! Game over." << std::endl;
      break;
    }

    std::cout << "Press 1 to play again or 2 to exit: ";
    std::cin >> choice;
  } while (choice == 1);

  std::cout << "Total winnings: " << game.getTotalWinnings() << std::endl;
  std::cout << "You have exited Baccarate...\n";
  User.updateRoom(getCurrentRoom(curRoom.getW()));
  curRoom = User.getRoom();
  return game.getPlayerChips();
}
