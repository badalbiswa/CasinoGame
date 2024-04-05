#include "card.h"
#include "deck.h"
#include "Game.h"
#include <iostream>
#include <algorithm>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for srand()

class Blackjack {
public:
    Blackjack(int initialBalance) : playerScore(0), dealerScore(0), balance(initialBalance), deck() {}

    void dealInitialHands() {
        // Generate new random cards for player and dealer
        playerHand.push_back(generateRandomCard());
        dealerHand.push_back(generateRandomCard());
        playerHand.push_back(generateRandomCard());
        dealerHand.push_back(generateRandomCard());

        // Calculate player's score after dealing initial hands
        playerScore = calculateScore(playerHand);
    }

    void playerHit() {
        playerHand.push_back(generateRandomCard());
        playerScore = calculateScore(playerHand);
    }

    void dealerHit() {
        dealerHand.push_back(deck.dealCard());
        dealerScore = calculateScore(dealerHand);
    }

    void evaluateHands() {
        playerScore = calculateScore(playerHand);
        dealerScore = calculateScore(dealerHand);
    }

    void displayHands() const {
        // Display player's hand
        std::cout << "Player's Hand: ";
        for (const auto& card : playerHand) {
            std::cout << "(" << getRankSymbol(card.rank) << getSuitSymbol(card.suit) << ") ";
        }
        std::cout << "\nPlayer's Score: " << playerScore;
        if (playerScore > 21) {
            std::cout << " (BUSTED)";
        }
        std::cout << "\n\n";

        // Display dealer's hand with the first card hidden
        std::cout << "Dealer's Hand: ";
        std::cout << "(" << getRankSymbol(dealerHand[0].rank) << getSuitSymbol(dealerHand[0].suit) << ") ";
        std::cout << "(Hidden)\n\n";
    }

    const std::vector<Card>& getPlayerHand() const {
        return playerHand;
    }

    const std::vector<Card>& getDealerHand() const {
        return dealerHand;
    }

    int getPlayerScore() const {
        return playerScore;
    }

    int getDealerScore() const {
        return dealerScore;
    }

    int getBalance() const {
        return balance;
    }

    void placeBet(int amount) {
        betAmount = amount;
        balance -= betAmount;
    }

    void win() {
        balance += betAmount * 2;
    }

    void blackjackWin() {
        balance += betAmount * 3;
    }

    void tie() {
        balance += betAmount;
    }

    void clearPlayerHand() {
        playerHand.clear();
    }

    void clearDealerHand() {
        dealerHand.clear();
    }

    std::string getRankSymbol(Rank rank) const {
        switch (rank) {
            case Rank::TWO: return "2";
            case Rank::THREE: return "3";
            case Rank::FOUR: return "4";
            case Rank::FIVE: return "5";
            case Rank::SIX: return "6";
            case Rank::SEVEN: return "7";
            case Rank::EIGHT: return "8";
            case Rank::NINE: return "9";
            case Rank::TEN: return "10";
            case Rank::JACK: return "J";
            case Rank::QUEEN: return "Q";
            case Rank::KING: return "K";
            case Rank::ACE: return "A";
        }
        return "";
    }

    std::string getSuitSymbol(const std::string& suit) const {
        if (suit == "Hearts") return "♥";
        else if (suit == "Diamonds") return "♦";
        else if (suit == "Clubs") return "♣";
        else if (suit == "Spades") return "♠";
        return "";
    }

private:
    int calculateScore(const std::vector<Card>& hand) const {
        int score = 0;
        int numAces = 0;

        for (const auto& card : hand) {
            switch (card.rank) {
                case Rank::TWO:
                case Rank::THREE:
                case Rank::FOUR:
                case Rank::FIVE:
                case Rank::SIX:
                case Rank::SEVEN:
                case Rank::EIGHT:
                case Rank::NINE:
                    score += static_cast<int>(card.rank);
                    break;
                case Rank::TEN:
                case Rank::JACK:
                case Rank::QUEEN:
                case Rank::KING:
                    score += 10;
                    break;
                case Rank::ACE:
                    score += 11; // Assume Ace counts as 11 initially
                    numAces++;
                    break;
            }
        }

        // Adjust score if there are Aces and the score is over 21
        while (numAces > 0 && score > 21) {
            score -= 10; // Change one Ace's value from 11 to 1
            numAces--;
        }

        return score;
    }

    std::vector<Card> playerHand;
    std::vector<Card> dealerHand;
    int playerScore;
    int dealerScore;
    int balance;
    int betAmount;
    Deck deck; // Instance of the Deck class

    Card generateRandomCard() {
        Rank randomRank = static_cast<Rank>(rand() % static_cast<int>(Rank::ACE) + 1);
        std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
        std::string randomSuit = suits[rand() % suits.size()];
        return Card{randomRank, randomSuit};
    }
};

int Game::blackJack() {
    srand(time(nullptr)); // Seed the random number generator

    char playAgain;
    do {
        Blackjack game(200); // Initialize the game with 200 chips

        // Place bet
        int betAmount;
        std::cout << "Your balance: " << game.getBalance() << std::endl;
        std::cout << "Place your bet: ";
        std::cin >> betAmount;
        game.placeBet(betAmount);

        // Reset hands
        game.clearPlayerHand();
        game.clearDealerHand();

        // Deal initial hands and display hands and scores
        game.dealInitialHands();
        game.displayHands();

        // Check for Blackjack (automatic win)
        if (game.getPlayerScore() == 21) {
            std::cout << "Blackjack! You Win!\n";
            game.blackjackWin();
        } else {
            char choice;

            // Player's turn
            do {
                std::cout << "Hit (h) or Stand (s)? ";
                std::cin >> choice;

                if (choice == 'h') {
                    game.playerHit();
                    game.displayHands(); // Display hands after player's hit
                    // Check for bust
                    if (game.getPlayerScore() > 21) {
                        break;
                    }
                } else if (choice == 's') {
                    break;
                }
            } while (game.getPlayerScore() < 21);

            // Determine outcome and adjust balance
            if (game.getPlayerScore() > 21) {
                std::cout << "You Busted! Dealer Wins!\n";
            } else {
                // Dealer's turn (automatic)
                while (game.getDealerScore() < 17) {
                    game.dealerHit();
                }

                // Display dealer's hand
                std::cout << "Dealer's Hand: ";
                for (const auto& card : game.getDealerHand()) {
                    std::cout << game.getRankSymbol(card.rank) << game.getSuitSymbol(card.suit) << " ";
                }
                std::cout << "\nDealer's Score: " << game.getDealerScore() << "\n\n";

                if (game.getDealerScore() > 21 || game.getPlayerScore() > game.getDealerScore()) {
                    std::cout << "You Win!\n";
                    game.win();
                } else if (game.getDealerScore() == game.getPlayerScore()) {
                    std::cout << "It's a Tie! Your bet is returned.\n";
                    game.tie();
                } else {
                    std::cout << "Dealer Wins!\n";
                }
            }
        }

        std::cout << "Your balance: " << game.getBalance() << std::endl;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y');

    return 0;
}
