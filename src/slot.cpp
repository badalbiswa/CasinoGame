/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-27
 */
 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> 

using namespace std;

int chips = 200;  // Starting number of chips

int getRandomNumber(int min, int max) {
  static const double fraction = 1.0 / (RAND_MAX + 1.0);
  return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

// Function to display slot machine symbols
void displaySymbols(int symbol) {
  switch (symbol) {
    case 0:
      cout << "🍒 ";
      break;
    case 1:
      cout << "🍊 ";
      break;
    case 2:
      cout << "🍋 ";
      break;
    case 3:
      cout << "🍇 ";
      break;
    case 4:
      cout << "🍉 ";
      break;
    case 5:
      cout << "🔔 ";
      break;
    case 6:
      cout << "💎 ";
      break;
  }
}

// Function to play the slot machine
void playSlotMachine(int bet) {
  if (chips == 0) {
    cout << "You are out of chips. Game over!\n";
    return;
  }

  if (bet > chips) {
    cout << "Not enough chips to place the bet. Please bet again." << endl;
    return;
  }

  cout << "Press 1 to spin the reels.";
  int spin;
  cin >> spin;
  if (spin != 1) {
    cout << "Invalid choice. Please enter 1 to spin the reels." << endl;
    playSlotMachine(bet);  // Ask for input again
    return;
  }

  srand(time(0));  // Seed the random number generator

  int reels[3];

  // Spin the reels
  for (int i = 0; i < 3; ++i) {
    reels[i] = getRandomNumber(0, 6);  // Get a random number representing a symbol
  }

  // Display the result
  cout << "Reels: ";
  for (int i = 0; i < 3; ++i) {
    displaySymbols(reels[i]);  // Display the symbol
  }

  // Check for win
  if (reels[0] == reels[1] && reels[1] == reels[2]) {
    cout << "\nCongratulations! You win!\n";
    chips += (bet * 10);  // Win 10 times the bet
  } else {
    cout << "\nSorry, you lose.\n";
    chips -= bet;  // Lose the bet amount
  }

  cout << "Remaining chips: " << chips << endl;  // Display remaining chips
}

int main() {
  int choice;

  cout << "\n------------------------------------------\n";
  cout << "       Welcome to the Slot Machine!\n";
  cout << "------------------------------------------\n";

  cout << "Current chips: " << chips << endl;

  do {
    cout << "Choose your bet amount:\n";
    cout << "1. 10 chips\n";
    cout << "2. 20 chips\n";
    cout << "3. 50 chips\n";
    cout << "4. 100 chips\n";
    cout << "5. 500 chips\n";
    cout << "6. 1000 chips\n";
    cout << "Enter your choice: ";

    // Keep asking for input until a valid choice is entered
    while (!(cin >> choice) || choice < 1 || choice > 6) {
      cout << "Invalid choice: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int bet;
    switch (choice) {
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

    playSlotMachine(bet);

    if (chips > 0) {
      cout << "\nDo you want to continue?\n";
      cout << "1. Keep Playing\n";
      cout << "2. Exit\n";
      cout << "Enter your choice: ";
      cin >> choice;
      if (choice != 1 && choice != 2) {
        cout << "Invalid choice. Exiting...\n";
        choice = 2;
      }
    } else {
      cout << "You are out of chips. Game over!\n";
      choice = 2;
    }
  } while (choice == 1);

  cout << "Thanks for playing!\n";

  return 0;
}
