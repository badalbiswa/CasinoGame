/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <string>

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck();
    void shuffle();
    Card dealCard();
    int cardsLeft() const;
};

#endif // DECK_H
