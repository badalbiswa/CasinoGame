/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#include <vector>
#include <limits>
#include <iostream> // Need to include for cout, cin, etc.

#ifndef Blackjack_Text_h
#define Blackjack_Text_h

#include "Blackjack.h"

class Text {
    int NumPlayer;
    int InitialAccountValue;
    bool useTextSymbol;
public:
    std::vector<bool> playerStatus;
    std::vector<Account> myA;

    Text(int n, int m, bool useTS)
        :
        NumPlayer(n),
        InitialAccountValue(m),
        useTextSymbol(useTS) {
    }

    void printWelcomeMessage();  // print welcome message
    void accountSetup(int chips);  // set player status and initial account value; run once
    void printAccount();  // print account information for each player
    PlayerAction playerInput(BJPlayer&, bool, bool);  // takes input from each player
    void printResult(Outcome result);  // print result of the play
    void printCard(int);  // print a single card in human readable format
    void printDealerCard(const std::vector<int> &DealerCard, const bool cardHide);  //print card of a dealer, with/without hide
    void printPlayerCard(BJPlayer &myP);  //print all cards of a single player
    bool playerBetInput();  // get input bets from players. also check for play/exit
    void updateAccounting(int, int, Outcome);  // update account information for each player based on Outcome
    void addBlankLine(int n);  // add blank line
    void printLine(std::string s, bool newline);
    int returnChips();
};

void Text::printWelcomeMessage() {
    std::cout
        << "\nYou sat down at a Blackjack table with 5 other players.\nMinimum bet at the table is 50."
        << std::endl;
}

void Text::accountSetup(int chips) {
    playerStatus.resize(NumPlayer, true);
    myA.resize(NumPlayer);
    for (int i = 0; i < NumPlayer; i++)
        myA[i].initialize(chips, 0);

}

int Text::returnChips() {
    for (int i = 0; i < NumPlayer; i++)
        return myA[i].returnChips();
    return 0;
}

void Text::printAccount() {
    std::cout << "_____________________________________________________________"
        << std::endl;
    for (int i = 0; i < NumPlayer; i++)
        std::cout << "Your Chips: " << myA[i].PlayerChips << "\t";
    std::cout << std::endl;
}

PlayerAction Text::playerInput(BJPlayer &myP, bool isFirstTurn,
                                bool isSplitPossible) {
    bool isS, isH, isD, isSp;
    isS = isH = isD = isSp = false;
    bool isDoublePossible = isFirstTurn
        && (myA[myP.Id].PlayerChips >= myP.playerBet);
    isSplitPossible = isSplitPossible
        && (myA[myP.Id].PlayerChips >= myP.playerBet);

    if (!playerStatus[myP.Id]) {
        std::cout << "You have no more Chips." << std::endl;
        return NO;
    }

    char choice = 'A';
    std::cout << " Your choices are:" << std::endl;
    std::cout << " H : Hit" << std::endl;
    std::cout << " S : Stand" << std::endl;
    if (isDoublePossible)
        std::cout << " D : Double Down" << std::endl;
    if (isSplitPossible)
        std::cout << " T : Split into two bet" << std::endl;

    while (!isS && !isH && !isD && !isSp) {
        std::cout << "Your choice : ";
        std::cin >> choice;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        isS = (choice == 'S' || choice == 's');
        isH = (choice == 'H' || choice == 'h');
        isD = (choice == 'D' || choice == 'd') && (isDoublePossible);
        isSp = (choice == 'T' || choice == 't') && (isSplitPossible);

    }

    if (isD) {
        myA[myP.Id].PlayerChips -= myP.playerBet;  //update player chips
        myP.playerBet *= 2;  // update player bet
        std::cout << "Your updated bet(total) : " << myP.playerBet << std::endl;

    }
    if (isSp) {
        myA[myP.Id].PlayerChips -= myP.playerBet;  //update player chips
        // we will not update playerBet, it will be updated individually
        std::cout << "Your additional bet : " << myP.playerBet << std::endl;
    }

    if (isS)
        return STAND;
    else if (isH)
        return HIT;
    else if (isD)
        return DOUBLE;
    else
        return SPLIT;
}

void Text::printResult(Outcome result) {
    switch (result) {
    case PUSH:
        std::cout << "Results : Push!!" << std::endl;
        break;
    case DEALER_WIN:
        std::cout << "Results : Dealer Won!!" << std::endl;
        break;
    case PLAYER_BUST:
        std::cout << "Results : Dealer Won!! (You Bust)" << std::endl;
    case PLAYER_WIN:
        std::cout << "Results : You Won!!" << std::endl;
        break;
    case DEALER_BUST:
        std::cout << "Results : You Won!! (Dealer Bust)" << std::endl;
        break;
    case PLAYER_BJ:
        std::cout << "Results : Player Blackjack!! " << std::endl;
        break;
    case DEALER_BJ:
        std::cout << "Results : Dealer Blackjack!!" << std::endl;
        break;
    default:
        break;
    }
}

void Text::printCard(int cardId) {
    int cardInDeck = cardId % NUM_CARD_DECK;
    int rank = cardInDeck % NUM_CARD_SUIT;
    int suit = cardInDeck / NUM_CARD_SUIT;
    if (useTextSymbol)
        std::cout << RANK[rank] << " " << SUITS_text[suit];
    else
        std::cout << RANK[rank] << SUITS[suit];
}

void Text::printDealerCard(const std::vector<int> &DealerCard, const bool cardHide) {
    // print dealer cards
    if (cardHide) {
        if (DealerCard.size() != 2)
            std::cout << "error";
        else {
            std::cout << "Dealer Cards : ";
            printCard(DealerCard[0]);
            std::cout << ", ";
            std::cout << "***" << std::endl;
        }
    } else {
        std::cout << std::endl << std::endl << "Dealer Cards : ";
        for (int i = 0; i < DealerCard.size(); i++) {
            printCard(DealerCard[i]);
            std::cout << ", ";
        }
        std::cout << std::endl;
    }
}

void Text::printPlayerCard(BJPlayer &myP) {
    if (!myP.isSplit)
        std::cout << "Your Cards : " << std::flush;
    else
        std::cout << "Your Split# " << myP.SplitId << " Card : " << std::flush;

    // print player cards
    for (int j = 0; j < myP.Card.size(); j++) {
        printCard(myP.Card[j]);
        std::cout << ", ";
    }
    std::cout << std::endl;
}

bool Text::playerBetInput() {
    int choice = 0;
    std::cout << "\t 1. Play" << std::endl;
    std::cout << "\t 2. Leave Table" << std::endl;
    while (choice != 1 && choice != 2) {
        std::cout << "Your input : " << std::flush;
        std::cin >> choice;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << std::endl;
    if (choice == 2)  //exit
    {
        printAccount();
        std::cout << "You have left the Blackjack table..." << std::endl;
        return false;
    } else  //play
    {
        std::cout << "Collecting bets from all players..." << std::endl;
        for (int i = 0; i < NumPlayer; i++) {
            if (myA[i].PlayerChips == 0) {
                std::cout << "You have 0 chips." << std::endl;
                std::cout << "You cannot play anymore..." << std::endl;
                playerStatus[i] = false;
            } else {
                int tempBet = 0;
                while (tempBet > myA[i].PlayerChips || tempBet < 50) {
                    std::cout << "Your Bet (min 50) : ";
                    std::cin >> tempBet;
                    if (!std::cin) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
                myA[i].initialBet = tempBet;
                myA[i].PlayerChips -= tempBet;  // update players chips
            }
        }
    }
    std::cout << std::endl;
    return true;
}

void Text::updateAccounting(int Id, int playerBet, Outcome r) {
    switch (r) {
    case PUSH:
        myA[Id].PlayerChips += playerBet;  // return bet
        break;
    case DEALER_WIN:
    case PLAYER_BUST:
    case DEALER_BJ:
        // player lose 1:1
        // do nothing
        break;
    case PLAYER_WIN:
    case DEALER_BUST:
        // player win 1:1
        myA[Id].PlayerChips += 2 * playerBet;
        break;
    case PLAYER_BJ:
        // player win 3:2
        myA[Id].PlayerChips += 2.5 * playerBet;
        break;
    default:
        break;            // do nothing

    }
}

void Text::addBlankLine(int n)  // add blank line
{
    for (int i = 0; i < n; i++)
        std::cout << std::endl;
}

void Text::printLine(std::string s, bool newline) {
    std::cout << s;
    if (newline)
        std::cout << std::endl;
}

#endif
