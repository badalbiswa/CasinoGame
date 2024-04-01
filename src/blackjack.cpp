/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <ctime>   
#include <limits>  
#include "card.h"
#include "deck.h"
#include "Game.h"
#include "Room.h"
#include "Player.h"

// Function declaration
Card generateRandomCard();

class Blackjack {
public:
    Blackjack(int initialBalance) : playerScore(0), dealerScore(0), balance(initialBalance) {}

    void dealInitialHands() {
        deck.shuffle(); // Shuffle the deck
        playerHand.push_back(deck.dealCard());
        dealerHand.push_back(deck.dealCard());
        playerHand.push_back(deck.dealCard());
        dealerHand.push_back(deck.dealCard());
    }

    void playerHit() {
        Card randomCard = generateRandomCard();
        playerHand.push_back(randomCard);
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
        std::cout << "Player's Hand: ";
        int playerTotal = 0;
        for (const auto& card : playerHand) {
            std::cout << "(" << card.rank << ", " << card.suit << ") ";
            if (card.rank != Rank::ACE) {
                playerTotal += static_cast<int>(card.rank);
            }
        }
        for (const auto& card : playerHand) {
            if (card.rank == Rank::ACE && playerTotal + 11 <= 21) {
                playerTotal += 11;
            } else if (card.rank == Rank::ACE) {
                playerTotal += 1;
            }
        }
        std::cout << "\nPlayer's Total: " << playerTotal << "\n\n";

        std::cout << "Dealer's Hand: ";
        int dealerTotal = 0;
        for (const auto& card : dealerHand) {
            std::cout << "(" << card.rank << ", " << card.suit << ") ";
            if (card.rank != Rank::ACE) {
                dealerTotal += static_cast<int>(card.rank);
            }
        }
        for (const auto& card : dealerHand) {
            if (card.rank == Rank::ACE && dealerTotal + 11 <= 21) {
                dealerTotal += 11;
            } else if (card.rank == Rank::ACE) {
                dealerTotal += 1;
            }
        }
        std::cout << "\nDealer's Total: " << dealerTotal << "\n\n";
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

    void tie() {
        balance += betAmount;
    }

    void clearHands() {
        playerHand.clear();
        dealerHand.clear();
    }

    bool hasSufficientFunds() const {
        return balance > 0;
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
                case Rank::TEN:
                    score += static_cast<int>(card.rank);
                    break;
                case Rank::JACK:
                case Rank::QUEEN:
                case Rank::KING:
                    score += 10;
                    break;
                case Rank::ACE:
                    numAces++;
                    score += 11; // Default to 11
                    break;
            }
        }

        // Account for aces
        while (numAces > 0 && score > 21) {
            score -= 10; // Change Ace value from 11 to 1
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
};

Card generateRandomCard() {
    Rank randomRank = static_cast<Rank>(rand() % static_cast<int>(Rank::ACE) + 1);
    std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    std::string randomSuit = suits[rand() % suits.size()];
    return Card{randomRank, randomSuit};
}

int Game::blackJack(Player User) {
    srand(time(nullptr)); // Seed the random number generator

    char playAgain;
    do {
        Blackjack game(200); // Initialize the game with 200 chips
        
        // Check if the player has sufficient funds to continue playing
        if (!game.hasSufficientFunds()) {
            std::cout << "You have run out of chips. Game over!\n";
            break;
        }

        // Clear player and dealer hands for each round
        game.clearHands();

        // Place bet
        int betAmount;
        std::cout << "Your balance: " << game.getBalance() << std::endl;
        do {
            std::cout << "Place your bet: ";
            std::cin >> betAmount;
            if (std::cin.fail()) {
                std::cout << "Invalid input. Please enter a valid integer.\n";
                std::cin.clear(); // Clear error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            } else if (betAmount > game.getBalance()) {
                std::cout << "Bet amount cannot exceed your balance. Your balance is: " << game.getBalance() << std::endl;
            } else {
                game.placeBet(betAmount);
                break;
            }
        } while (true);

        game.dealInitialHands();
        game.displayHands();

        // Check for initial 21
        if (game.getPlayerScore() == 21) {
            std::cout << "Blackjack! You Win!\n";
            game.win();
            std::cout << "Your balance: " << game.getBalance() << std::endl;
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> playAgain;
            playAgain = std::tolower(playAgain);
            if (playAgain != 'y' && playAgain != 'n') {
                std::cout << "Invalid choice. Please enter 'y' to play again or 'n' to quit.\n";
            }
            continue;
        } else if (game.getDealerScore() == 21) {
            std::cout << "Dealer has Blackjack! Dealer Wins!\n";
            std::cout << "Your balance: " << game.getBalance() << std::endl;
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> playAgain;
            playAgain = std::tolower(playAgain);
            if (playAgain != 'y' && playAgain != 'n') {
                std::cout << "Invalid choice. Please enter 'y' to play again or 'n' to quit.\n";
            }
            continue;
        }

        char choice;

        // Player's turn
        do {
            std::cout << "Hit (h) or Stand (s)? ";
            std::cin >> choice;

            if (choice != 'h' && choice != 's') {
                std::cout << "Invalid choice. Please enter 'h' to hit or 's' to stand.\n";
            } else {
                if (choice == 'h') {
                    game.playerHit();
                    game.displayHands();
                    std::cout << "Your current score: " << game.getPlayerScore() << "\n";

                    // Check for bust
                    if (game.getPlayerScore() > 21) {
                        std::cout << "You BUSTED!\n";
                        break;
                    } else if (game.getPlayerScore() == 21) {
                        std::cout << "You got 21! You Win!\n";
                        game.win();
                        std::cout << "Your balance: " << game.getBalance() << std::endl;
                        std::cout << "Do you want to play again? (y/n): ";
                        std::cin >> playAgain;
                        playAgain = std::tolower(playAgain);
                        if (playAgain != 'y' && playAgain != 'n') {
                            std::cout << "Invalid choice. Please enter 'y' to play again or 'n' to quit.\n";
                        }
                        continue;
                    }
                }
            }
        } while (choice == 'h');

        // Determine outcome and adjust balance
        if (game.getPlayerScore() > 21) {
            std::cout << "Dealer Wins!\n";
        } else {
            // Dealer's turn (automatic)
            while (game.getDealerScore() < 17) {
                game.dealerHit();
            }

            game.evaluateHands();
            game.displayHands();

            if (game.getDealerScore() > 21 || game.getPlayerScore() > game.getDealerScore()) {
                std::cout << "You Win!\n";
                game.win();
            } else if (game.getDealerScore() > game.getPlayerScore()) {
                std::cout << "Dealer Wins!\n";
            } else {
                std::cout << "It's a Tie!\n";
                game.tie();
            }
        }

        std::cout << "Your balance: " << game.getBalance() << std::endl;

        // Prompt for playing again
        do {
            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> playAgain;
            // Convert choice to lowercase
            playAgain = std::tolower(playAgain);
            if (playAgain != 'y' && playAgain != 'n') {
                std::cout << "Invalid choice. Please enter 'y' to play again or 'n' to quit.\n";
            }
        } while (playAgain != 'y' && playAgain != 'n');

    } while (playAgain == 'y');

    return 0;
}

