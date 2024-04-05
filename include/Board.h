#ifndef Blackjack_Board_h
#define Blackjack_Board_h

#include "Blackjack.h"
#include "Text.h"
#include <vector>

class Board {
  int NumDeck;
  int NumPlayer;
  Shoe myShoe;
  unsigned int Seed;
public:
  std::vector<BJPlayer> myP;
  std::vector<int> DealerCard;

  Board(int nplayer, int ndeck, unsigned int s)
      : NumPlayer(nplayer), NumDeck(ndeck), Seed(s), myShoe(ndeck, s) {}

  void createBoard();
  void initializeBoard(Text&);
  bool initialCheckDealer(std::vector<Outcome>& result);
  void initialCheckPlayer(std::vector<Outcome>& result);
  int total(const std::vector<int>&);
  int value(const int&);
  Outcome checkResult(const std::vector<int>&, const std::vector<int>&);
  void runGame(Text&, std::vector<Outcome>&);
  Outcome dealersTurn();
  Outcome playersTurn(BJPlayer& myP, Text& myText, bool&);
  void performSplitOperation(std::vector<BJPlayer>& myP,
    std::vector<BJPlayer>::iterator& it);
};

void Board::createBoard() {
  myShoe.CreateShoe();
}

void Board::initializeBoard(Text& myText) {
  myP.resize(NumPlayer);
  for (int i = 0; i < NumPlayer; i++) {
    myP[i].initialize(i, false, "0");
    myP[i].Card.clear();
    myP[i].playerBet = myText.myA[i].initialBet;
  }

  DealerCard.clear();
  for (int i = 0; i < NumPlayer; i++) {
    if (myText.playerStatus[i])
      myP[i].Card.push_back(myShoe.pullCard());
  }
  DealerCard.push_back(myShoe.pullCard());
  for (int i = 0; i < NumPlayer; i++) {
    if (myText.playerStatus[i])
      myP[i].Card.push_back(myShoe.pullCard());
  }
  DealerCard.push_back(myShoe.pullCard());
}

bool Board::initialCheckDealer(std::vector<Outcome>& result) {
  if (total(DealerCard) == BJ) {
    for (int i = 0; i < NumPlayer; i++) {
      if (total(myP[i].Card) == BJ)
        result.push_back(PUSH);
      else
        result.push_back(DEALER_BJ);
    }
    return true;
  }

  return false;
}

void Board::initialCheckPlayer(std::vector<Outcome>& result) {
  for (int i = 0; i < NumPlayer; i++) {
    if (total(myP[i].Card) == BJ)
      result.push_back(PLAYER_BJ);
    else
      result.push_back(NONE);
  }
}

int Board::value(const int& card) {
  return VALUE[card % NUM_CARD_DECK % NUM_CARD_SUIT];
}

int Board::total(const std::vector<int>& card) {
  int total = 0;
  int val;
  int NumAce = 0;
  for (int i = 0; i < card.size(); i++) {
    val = value(card[i]);
    if (val == 11)
      NumAce++;
    else
      total += val;
  }
  if (NumAce > 0) {
    if (NumAce > 1) {
      total += (NumAce - 1);
      NumAce = 1;
    }
    if (NumAce == 1) {
      if (total + 11 > TwentyOne)
        total += 1;
      else
        total += 11;
    }
  }
  return total;
}

void Board::runGame(Text& myText, std::vector<Outcome>& Result) {
  myText.printLine
  ("Dealer finished dealing card...current board status:", true);
  myText.printDealerCard(DealerCard, true);
  for (std::vector<BJPlayer>::iterator it = myP.begin(); it != myP.end(); it++)
    myText.printPlayerCard(*it);

  bool isDealerBJ = initialCheckDealer(Result);
  if (!isDealerBJ)
    initialCheckPlayer(Result);

  bool isDealerTurn = false;
  unsigned int counter = 0;
  std::vector<BJPlayer>::iterator it = myP.begin();

  while (it != myP.end()) {
    myText.addBlankLine(2);
    myText.printPlayerCard(*it);
    if (Result[counter] != PLAYER_BJ) {
      bool isSplit;
      Result[counter] = playersTurn(*it, myText, isSplit);
      if (isSplit) {
        performSplitOperation(myP, it);
        Result.insert(Result.begin() + counter + 1, NONE);
      } else {
        if (Result[counter] == PLAYER_BUST)
          myText.printResult(Result[counter]);
        if (Result[counter] == NONE)
          isDealerTurn = true;
        counter++;
        it++;
      }
    } else {
      counter++;
      it++;
    }
  }

  Outcome dealerResult = NONE;
  if (isDealerTurn) {
    dealerResult = dealersTurn();
  }

  myText.printDealerCard(DealerCard, false);
  for (int i = 0; i < Result.size(); i++) {
    if ((myText.playerStatus[myP[i].Id]) && (Result[i] != PLAYER_BUST)) {
      myText.printPlayerCard(myP[i]);
      if (Result[i] != PLAYER_BJ) {
        if (dealerResult == DEALER_BUST)
          Result[i] = DEALER_BUST;
        else if (Result[i] == NONE)
          Result[i] = checkResult(myP[i].Card, DealerCard);
      }
      myText.printResult(Result[i]);
    }
  }

  for (int i = 0; i < Result.size(); i++) {
    myText.updateAccounting(myP[i].Id, myP[i].playerBet, Result[i]);
  }
}

Outcome Board::dealersTurn() {
  int Total = total(DealerCard);
  while (Total < 17) {
    DealerCard.push_back(myShoe.pullCard());
    Total = total(DealerCard);
  }
  if (Total > TwentyOne)
    return DEALER_BUST;
  else
    return NONE;
}

Outcome Board::playersTurn(BJPlayer& myP, Text& myText, bool& isSplit) {
  Outcome result = NONE;
  bool isSplitPossible = ((myP.Card.size() == 2)
  && (value(myP.Card[0]) == value(myP.Card[1])));
  isSplit = false;
  bool isFirstTurn = true;

  bool isPlayerTurn = true;
  while (isPlayerTurn) {
    PlayerAction playerInput = myText.playerInput
    (myP, isFirstTurn, isSplitPossible);
    isFirstTurn = false;
    isSplitPossible = false;

    switch (playerInput) {
      case HIT:
        myP.Card.push_back(myShoe.pullCard());
        myText.printPlayerCard(myP);
        if (total(myP.Card) > TwentyOne) {
          result = PLAYER_BUST;
          isPlayerTurn = false;
        }
        break;
      case STAND:
        isPlayerTurn = false;
        break;
      case DOUBLE:
        isPlayerTurn = false;
        myP.Card.push_back(myShoe.pullCard());
        myText.printPlayerCard(myP);
        if (total(myP.Card) > TwentyOne)
          result = PLAYER_BUST;
        break;
      case SPLIT:
        isSplit = true;
        isPlayerTurn = false;
        break;
      case NO:
        isPlayerTurn = false;
        break;
    }
  }
  return result;
}

void Board::performSplitOperation(std::vector<BJPlayer>& myP,
  std::vector<BJPlayer>::iterator& it) {
  it = myP.insert(it + 1, BJPlayer(it->Id, true, it->SplitId + "-2"));
  it--;
  (it + 1)->playerBet = it->playerBet;
  (it + 1)->Card.push_back(it->Card[1]);

  it->SplitId = it->SplitId + "-1";
  it->isSplit = true;
  it->Card[1] = myShoe.pullCard();
  (it + 1)->Card.push_back(myShoe.pullCard());
}

Outcome Board::checkResult(const std::vector<int>& PCard,
  const std::vector<int>& DCard) {
  if (total(PCard) > total(DCard))
    return PLAYER_WIN;
  else if (total(PCard) == total(DCard))
    return PUSH;
  else
    return DEALER_WIN;
}

#endif
