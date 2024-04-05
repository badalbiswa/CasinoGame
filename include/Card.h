/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include <vector>

enum class Rank {
  TWO = 2,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING,
  ACE
};

struct Card {
  Rank rank;
  std::string suit;
};

inline std::ostream& operator<<(std::ostream &os, const Rank &rank) {
  switch (rank) {
    case Rank::TWO:
      os << "2";
      break;
    case Rank::THREE:
      os << "3";
      break;
    case Rank::FOUR:
      os << "4";
      break;
    case Rank::FIVE:
      os << "5";
      break;
    case Rank::SIX:
      os << "6";
      break;
    case Rank::SEVEN:
      os << "7";
      break;
    case Rank::EIGHT:
      os << "8";
      break;
    case Rank::NINE:
      os << "9";
      break;
    case Rank::TEN:
      os << "10";
      break;
    case Rank::JACK:
      os << "Jack";
      break;
    case Rank::QUEEN:
      os << "Queen";
      break;
    case Rank::KING:
      os << "King";
      break;
    case Rank::ACE:
      os << "Ace";
      break;
  }
  return os;
}

class Deck {
 private:
  std::vector<Card> cards;

 public:
  Deck();
  void shuffle();
  Card dealCard();
  int cardsLeft() const;
};

#endif // CARD_DECK_H
