/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#include "deck.h"
#include <algorithm> // for std::random_shuffle

Deck::Deck() {
  // Initialize the deck with cards
  for (int rank = static_cast<int>(Rank::TWO);
      rank <= static_cast<int>(Rank::ACE); ++rank) {
    for (const std::string &suit : { "♥", "♦", "♣", "♠" }) {
      cards.push_back(Card { static_cast<Rank>(rank), suit });
    }
  }
}

void Deck::shuffle() {
  std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::dealCard() {
  if (cards.empty()) {
    return Card { Rank::TWO, "Spades" };  // Placeholder for no cards left
  }
  Card dealtCard = cards.back();
  cards.pop_back();
  return dealtCard;
}

int Deck::cardsLeft() const {
  return cards.size();
}
