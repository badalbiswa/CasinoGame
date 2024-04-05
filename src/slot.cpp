/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-27
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Game.h"
#include "Room.h"
#include "Player.h"

int chips; // Starting number of chips
bool hasDevice = 0;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

// Function to display slot machine symbols
void displaySymbols(int symbol)
{
    switch (symbol)
    {
    case 0:
        std::cout << "🍒 ";
        break;
    case 1:
        std::cout << "🍊 ";
        break;
    case 2:
        std::cout << "🍋 ";
        break;
    case 3:
        std::cout << "🍇 ";
        break;
    case 4:
        std::cout << "🍉 ";
        break;
    case 5:
        std::cout << "🔔 ";
        break;
    case 6:
        std::cout << "💎 ";
        break;
    }
}

// Function to play the slot machine
void playSlotMachine(int bet)
{
    if (chips == 0)
    {
        std::cout << "You are out of chips. Game over!\n";
        return;
    }

    if (bet > chips)
    {
        std::cout << "Not enough chips to place the bet. Please bet again." << std::endl;
        return;
    }

    srand(time(0)); // Seed the random number generator

    int reels[3];

    // Spin the reels
    for (int i = 0; i < 3; ++i)
    {
        reels[i] = getRandomNumber(0, 6); // Get a random number representing a symbol
    }

    // Display the result
    std::cout << "Reels: ";
    for (int i = 0; i < 3; ++i)
    {
        displaySymbols(reels[i]); // Display the symbol
    }

    // Check for win
    if ((reels[0] == reels[1] && reels[1] == reels[2]))
    {
        std::cout << "\nCongratulations! You win!\n";
        chips += (bet * 10); // Win 10 times the bet
    }
    else
    {
        std::cout << "\nSorry, you lose.\n";
        chips -= bet; // Lose the bet amount
    }

    std::cout << "Remaining chips: " << chips << std::endl; // Display remaining chips
}

void playBustedSlots(int bet)
{
    if (chips == 0)
    {
        std::cout << "You are out of chips. Game over!\n";
        return;
    }

    if (bet > chips)
    {
        std::cout << "Not enough chips to place the bet. Please bet again." << std::endl;
        return;
    }

    srand(time(0)); // Seed the random number generator

    int reels[4];

    // Spin the reels
    for (int i = 0; i < 4; ++i)
    {
        reels[i] = getRandomNumber(0, 2); // Get a random number representing a symbol
    }

    // Display the result
    std::cout << "Reels: ";
    for (int i = 0; i < 4; ++i)
    {
        displaySymbols(reels[i]); // Display the symbol
    }

    // Check for win
    if ((reels[0] == reels[1] && reels[1] == reels[2]) || ((reels[1] == reels[2] && reels[2] == reels[3])))
    {
        std::cout << "\nCongratulations! You win!\n";
        chips += (bet * 10); // Win 10 times the bet
    }
    else
    {
        std::cout << "\nSorry, you lose.\n";
        chips -= bet; // Lose the bet amount
    }

    std::cout << "Remaining chips: " << chips << std::endl; // Display remaining chips
}

int Game::slotMachine()
{
    std::cout << "RULES" << std::endl;
    std::cout << "Slot machines is a game where you can wager varying amounts (10, 20, 50, 100, 500, or 1000 chips) on each spin. The game uses numbers to simulate spinning reels with 7 symbols (cherry, oranges, lemons, grapes, watermelon, bell, and diamond). To hit the jackpot, all three reels need to land on the same symbol. A winning spin multiplies your bet by 10." << std::endl;

    chips = User.getChips();
    if (User.hasItem("Unknown Device...")) {
        hasDevice = 1;
        std::cout << "*You swipe the device into the chip intake...*\n";
    }
    int choice;
    std::cout << "\n------------------------------------------\n";
    std::cout << "       Welcome to the Slot Machine!\n";
    std::cout << "------------------------------------------\n";

    std::cout << "Current chips: " << chips << std::endl;

    do
    {
        std::cout << "Choose your bet amount:\n";
        std::cout << "1. 10 chips\n";
        std::cout << "2. 20 chips\n";
        std::cout << "3. 50 chips\n";
        std::cout << "4. 100 chips\n";
        std::cout << "5. 500 chips\n";
        std::cout << "6. 1000 chips\n";
        std::cout << "Enter your choice: ";

        // Keep asking for input until a valid choice is entered
        while (!(std::cin >> choice) || choice < 1 || choice > 6)
        {
            std::cout << "Invalid choice: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        int bet;
        switch (choice)
        {
        case 1:
            bet = 10;
            break;
        case 2:
            bet = 20;
            break;
        case 3:
            bet = 50;
            break;
        case 4:
            bet = 100;
            break;
        case 5:
            bet = 500;
            break;
        case 6:
            bet = 1000;
            break;
        }

        if (!hasDevice){
        playSlotMachine(bet);
        } else if (hasDevice){
            playBustedSlots(bet);
        }

        if (chips > 0)
        {
            std::cout << "\nDo you want to continue?\n";
            std::cout << "1. Keep Playing\n";
            std::cout << "2. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (choice != 1 && choice != 2)
            {
                std::cout << "Invalid choice. Exiting...\n";
                choice = 2;
            }
        }
        else
        {
            std::cout << "You are out of chips. Game over!\n";
            choice = 2;
        }
    } while (choice == 1);

    std::cout << "You have exited the Slots...\n";
    User.updateRoom(getCurrentRoom(curRoom.getS()));
    curRoom = User.getRoom();
    return chips;
}
