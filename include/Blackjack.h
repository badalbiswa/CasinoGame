/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#ifndef Blackjack_h
#define Blackjack_h

#include <iostream>
#include <vector>
#include <stack>
#include <random>
#include <algorithm>

class BJPlayer {
  int Id;
  bool isSplit;
  std::string SplitId;
  std::vector<int> Card;
  int playerBet;
  friend class Text;
  friend class Board;
 public:
  BJPlayer() {
  }
  BJPlayer(int id, bool split, std::string spid)
      :
      Id(id),
      isSplit(split),
      SplitId(spid) {
  }
  void initialize(int id, bool split, std::string spid) {
    Id = id;
    isSplit = split;
    SplitId = spid;
  }
};

class Account {
  double PlayerChips;  // chips can be fractional
  friend class Text;
 public:
  int initialBet;  //bet cannot be fractional
  void initialize(double c, int b) {
    PlayerChips = c;
  }
  double returnChips() {
    return PlayerChips;
  }
};

enum Outcome {
  PUSH,
  DEALER_WIN,
  PLAYER_WIN,
  NONE,
  DEALER_BUST,
  PLAYER_BUST,
  PLAYER_BJ,
  DEALER_BJ
};

enum PlayerAction {
  HIT,
  STAND,
  DOUBLE,
  SPLIT,
  NO
};

const int NUM_CARD_DECK = 52;
const int NUM_CARD_SUIT = 13;
const std::string SUITS[] = { "\u2663", "\u2666", "\u2665", "\u2660" };
const std::string SUITS_text[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
const std::string RANK[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J",
    "Q", "K", "A" };
const int BJ = 21;
const int TwentyOne = 21;
const int VALUE[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11 };

class Shoe {
  int NumDeck;
  std::stack<int> ShoeCard;
  unsigned int Seed;
 public:
  Shoe(int n, unsigned int s)
      :
      NumDeck(n),
      Seed(s) {
  }
  void CreateShoe();  // put shuffled card in the shoe
  int pullCard();  // return a card from the shoe
};

void Shoe::CreateShoe() {
  std::vector<int> tempShoe;
  for (int i = 0; i < NUM_CARD_DECK * NumDeck; i++)
    tempShoe.push_back(i);
  std::shuffle(tempShoe.begin(), tempShoe.end(),
               std::default_random_engine(Seed));
  for (int i = 0; i < NUM_CARD_DECK * NumDeck; i++)
    ShoeCard.push(tempShoe[i]);
}

int Shoe::pullCard() {
  int CardId = -1;
  if (!ShoeCard.empty())
    CardId = ShoeCard.top();
  ShoeCard.pop();
  return CardId;
}

#endif
