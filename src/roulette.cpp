/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-27
 */

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include "Game.h"

// Define the pockets on the roulette wheel
std::vector<std::string> pockets = { "0", "00", "1", "2", "3", "4", "5", "6",
    "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
    "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31",
    "32", "33", "34", "35", "36" };

// Define the colors of the pockets
std::unordered_map<std::string, std::string> pocket_colors = { { "0", "green" },
    { "00", "green" }, { "1", "red" }, { "2", "black" }, { "3", "red" }, { "4",
        "black" }, { "5", "red" }, { "6", "black" }, { "7", "red" }, { "8",
        "black" }, { "9", "red" }, { "10", "black" }, { "11", "black" }, { "12",
        "red" }, { "13", "black" }, { "14", "red" }, { "15", "black" }, { "16",
        "red" }, { "17", "black" }, { "18", "red" }, { "19", "red" }, { "20",
        "black" }, { "21", "red" }, { "22", "black" }, { "23", "red" }, { "24",
        "black" }, { "25", "red" }, { "26", "black" }, { "27", "red" }, { "28",
        "black" }, { "29", "black" }, { "30", "red" }, { "31", "black" }, {
        "32", "red" }, { "33", "black" }, { "34", "red" }, { "35", "black" }, {
        "36", "red" } };

int playerChips;  // Initial chips for the player

std::string spinWheel() {
  // Simulate spinning the roulette wheel and return the result
  return pockets[std::rand() % pockets.size()];
}

void displayResult(std::string result) {
  // Display the result of the spin
  std::string color = pocket_colors[result];
  std::cout << "The ball landed on " << result << ", which is " << color << "!"
            << std::endl;
}

int getBetAmount(int playerChips) {
  // Get the bet amount from the player
  int betAmount;
  std::cout << "Enter your bet amount (current chips: " << playerChips << "): ";
  std::cin >> betAmount;
  return betAmount;
}

std::string getBetType() {
  // Get the type of bet from the player
  std::cout << "Choose your bet type:" << std::endl;
  std::cout << "1. Single number (35 to 1)" << std::endl;
  std::cout << "2. Double number (17 to 1)" << std::endl;
  std::cout << "3. Three number (11 to 1)" << std::endl;
  std::cout << "4. Four number (8 to 1)" << std::endl;
  std::cout << "5. Five number (6 to 1)" << std::endl;
  std::cout << "6. Six number (5 to 1)" << std::endl;
  std::cout << "7. Twelve numbers (2 to 1)" << std::endl;
  std::cout << "8. Column bet (2 to 1)" << std::endl;
  std::cout << "9. 18 numbers (1-18 or 19-36, even money)" << std::endl;
  std::cout << "10. Red or Black (even money)" << std::endl;
  std::cout << "11. Odd or Even (even money)" << std::endl;
  std::cout << "Enter your choice (1-11): ";
  std::string betType;
  std::cin >> betType;
  return betType;
}

std::string getBetPocket(const std::string &betType) {
  // Get the pocket number, color, or odd/even on which the player wants to bet
  std::string betPocket;
  if (betType == "1") {
    std::cout << "Enter the single pocket number you want to bet on: ";
    std::cin >> betPocket;
  } else if (betType == "2") {
    std::cout << "Enter the first number of the double you want to bet on: ";
    std::cin >> betPocket;
  } else if (betType == "3") {
    std::cout
        << "Enter the first number of the three numbers you want to bet on: ";
    std::cin >> betPocket;
  } else if (betType == "4") {
    std::cout
        << "Enter the first number of the four numbers you want to bet on: ";
    std::cin >> betPocket;
  } else if (betType == "5") {
    std::cout << "Betting on the five-number bet (0-00-1-2-3)." << std::endl;
    betPocket = "five";
  } else if (betType == "6") {
    std::cout
        << "Enter the first number of the six numbers you want to bet on: ";
    std::cin >> betPocket;
  } else if (betType == "7") {
    std::cout
        << "Choose the dozen (1. First 12 / 2. Second 12 / 3. Third 12): ";
    int dozenChoice;
    std::cin >> dozenChoice;
    if (dozenChoice == 1)
      betPocket = "first";
    else if (dozenChoice == 2)
      betPocket = "second";
    else if (dozenChoice == 3)
      betPocket = "third";
  } else if (betType == "8") {
    std::cout
        << "Choose the column (1. First column / 2. Second column / 3. Third column): ";
    int columnChoice;
    std::cin >> columnChoice;
    if (columnChoice == 1)
      betPocket = "first";
    else if (columnChoice == 2)
      betPocket = "second";
    else if (columnChoice == 3)
      betPocket = "third";
  } else if (betType == "9") {
    std::cout << "Choose the range (1. 1-18 / 2. 19-36): ";
    int rangeChoice;
    std::cin >> rangeChoice;
    if (rangeChoice == 1)
      betPocket = "1-18";
    else if (rangeChoice == 2)
      betPocket = "19-36";
  } else if (betType == "10") {
    std::cout << "Choose the color (1. Black / 2. Red): ";
    int colorChoice;
    std::cin >> colorChoice;
    betPocket = (colorChoice == 1) ? "black" : "red";
  } else if (betType == "11") {
    std::cout << "Choose odd or even (1. Odd / 2. Even): ";
    int oddEvenChoice;
    std::cin >> oddEvenChoice;
    betPocket = (oddEvenChoice == 1) ? "odd" : "even";
  }
  return betPocket;
}

bool validateBet(const std::string &betType, std::string betPocket) {
  // Validate the bet
  if (betType == "1") {
    if (std::find(pockets.begin(), pockets.end(), betPocket) != pockets.end()) {
      return true;
    } else {
      std::cout << "Invalid pocket number. Please enter a valid pocket number."
                << std::endl;
      return false;
    }
  } else if (betType == "2") {
    if (std::find(pockets.begin(), pockets.end(), betPocket) != pockets.end()) {
      return true;
    } else {
      std::cout << "Invalid double number. Please enter a valid pocket number."
                << std::endl;
      return false;
    }
  } else if (betType == "3") {
    if (std::find(pockets.begin(), pockets.end(), betPocket) != pockets.end()
        && std::find(pockets.begin(), pockets.end(),
                     std::to_string(std::stoi(betPocket) + 1)) != pockets.end()
        && std::find(pockets.begin(), pockets.end(),
                     std::to_string(std::stoi(betPocket) + 2))
            != pockets.end()) {
      return true;
    } else {
      std::cout
          << "Invalid three-number bet. Please enter a valid starting pocket number."
          << std::endl;
      return false;
    }
  } else if (betType == "4") {
    if (std::find(pockets.begin(), pockets.end(), betPocket) != pockets.end()
        && std::find(pockets.begin(), pockets.end(),
                     std::to_string(std::stoi(betPocket) + 1)) != pockets.end()
        && std::find(pockets.begin(), pockets.end(),
                     std::to_string(std::stoi(betPocket) + 3))
            != pockets.end()) {
      return true;
    } else {
      std::cout
          << "Invalid four-number bet. Please enter a valid starting pocket number."
          << std::endl;
      return false;
    }
  } else if (betType == "5") {
    if (betPocket == "five") {
      return true;
    } else {
      std::cout << "Invalid five-number bet. Please choose the five-number bet."
                << std::endl;
      return false;
    }
  } else if (betType == "6") {
    if (std::find(pockets.begin(), pockets.end(), betPocket) != pockets.end()
        && std::find(pockets.begin(), pockets.end(),
                     std::to_string(std::stoi(betPocket) + 1)) != pockets.end()
        && std::find(pockets.begin(), pockets.end(),
                     std::to_string(std::stoi(betPocket) + 2)) != pockets.end()
        && std::find(pockets.begin(), pockets.end(),
                     std::to_string(std::stoi(betPocket) + 3)) != pockets.end()
        && std::find(pockets.begin(), pockets.end(),
                     std::to_string(std::stoi(betPocket) + 4)) != pockets.end()
        && std::find(pockets.begin(), pockets.end(),
                     std::to_string(std::stoi(betPocket) + 5))
            != pockets.end()) {
      return true;
    } else {
      std::cout
          << "Invalid six-number bet. Please enter a valid starting pocket number."
          << std::endl;
      return false;
    }
  } else if (betType == "7" || betType == "8") {
    if (betPocket == "first" || betPocket == "second" || betPocket == "third") {
      return true;
    } else {
      std::cout
          << "Invalid choice. Please choose between first, secon  std::cout << User.getChips();d, or third."
          << std::endl;
      return false;
    }
  } else if (betType == "9") {
    if (betPocket == "1-18" || betPocket == "19-36") {
      return true;
    } else {
      std::cout << "Invalid choice. Please choose between 1-18 or 19-36."
                << std::endl;
      return false;
    }
  } else if (betType == "10") {
    if (betPocket == "black" || betPocket == "red") {
      return true;
    } else {
      std::cout << "Invalid choice. Please choose between black or red."
                << std::endl;
      return false;
    }
  } else if (betType == "11") {
    if (betPocket == "odd" || betPocket == "even") {
      return true;
    } else {
      std::cout << "Invalid choice. Please choose between odd or even."
                << std::endl;
      return false;
    }
  }
  return true;
}

bool getYesNoInput(const std::string &message) {
  // Get yes/no input from the user
  std::string input;
  std::cout << message << " (yes/no): ";
  std::cin >> input;
  return (input == "yes");
}

int Game::roulette() {
  // Seed the random number generator
  playerChips = User.getChips();
  std::srand(std::time(0));

  std::cout << "Welcome to the Roulette Wheel Game!" << std::endl;
  while (true) {
    // Get the bet from the player
    int betAmount = getBetAmount(playerChips);
    std::string betType = getBetType();
    std::string betPocket = getBetPocket(betType);
    while (!validateBet(betType, betPocket)) {
      betPocket = getBetPocket(betType);
    }

    // Update player's chips based on the result
    playerChips -= betAmount;
    std::string result = spinWheel();
    displayResult(result);
    if (betType == "1" && result == betPocket) {
      std::cout << "Congratulations! You won " << betAmount * 35 << " chips!"
                << std::endl;
      playerChips += betAmount * 35;
    } else if (betType == "2"
        && (result == betPocket
            || result == std::to_string(std::stoi(betPocket) + 1))) {
      std::cout << "Congratulations! You won " << betAmount * 17 << " chips!"
                << std::endl;
      playerChips += betAmount * 17;
    } else if (betType == "3"
        && (result == betPocket
            || result == std::to_string(std::stoi(betPocket) + 1)
            || result == std::to_string(std::stoi(betPocket) + 2))) {
      std::cout << "Congratulations! You won " << betAmount * 11 << " chips!"
                << std::endl;
      playerChips += betAmount * 11;
    } else if (betType == "4"
        && (result == betPocket
            || result == std::to_string(std::stoi(betPocket) + 1)
            || result == std::to_string(std::stoi(betPocket) + 3)
            || result == std::to_string(std::stoi(betPocket) + 4))) {
      std::cout << "Congratulations! You won " << betAmount * 8 << " chips!"
                << std::endl;
      playerChips += betAmount * 8;
    } else if (betType == "5"
        && (result == "0" || result == "00" || result == "1" || result == "2"
            || result == "3")) {
      std::cout << "Congratulations! You won " << betAmount * 6 << " chips!"
                << std::endl;
      playerChips += betAmount * 6;
    } else if (betType == "6"
        && (result == betPocket
            || result == std::to_string(std::stoi(betPocket) + 1)
            || result == std::to_string(std::stoi(betPocket) + 2)
            || result == std::to_string(std::stoi(betPocket) + 3)
            || result == std::to_string(std::stoi(betPocket) + 4)
            || result == std::to_string(std::stoi(betPocket) + 5))) {
      std::cout << "Congratulations! You won " << betAmount * 5 << " chips!"
                << std::endl;
      playerChips += betAmount * 5;
    } else if (betType == "7"
        && ((betPocket == "first" && std::stoi(result) >= 1
            && std::stoi(result) <= 12)
            || (betPocket == "second" && std::stoi(result) >= 13
                && std::stoi(result) <= 24)
            || (betPocket == "third" && std::stoi(result) >= 25
                && std::stoi(result) <= 36))) {
      std::cout << "Congratulations! You won " << betAmount * 2 << " chips!"
                << std::endl;
      playerChips += betAmount * 2;
    } else if (betType == "8"
        && ((betPocket == "first" && std::stoi(result) % 3 == 1)
            || (betPocket == "second" && std::stoi(result) % 3 == 2)
            || (betPocket == "third" && std::stoi(result) % 3 == 0))) {
      std::cout << "Congratulations! You won " << betAmount * 2 << " chips!"
                << std::endl;
      playerChips += betAmount * 2;
    } else if (betType == "9"
        && ((betPocket == "1-18" && std::stoi(result) >= 1
            && std::stoi(result) <= 18)
            || (betPocket == "19-36" && std::stoi(result) >= 19
                && std::stoi(result) <= 36))) {
      std::cout << "Congratulations! You won " << betAmount * 2 << " chips!"
                << std::endl;
      playerChips += betAmount * 2;
    } else if (betType == "10" && (pocket_colors[result] == betPocket)) {
      std::cout << "Congratulations! You won " << betAmount * 2 << " chips!"
                << std::endl;
      playerChips += betAmount * 2;
    } else if (betType == "11"
        && ((betPocket == "odd" && std::stoi(result) % 2 != 0)
            || (betPocket == "even" && std::stoi(result) % 2 == 0))) {
      std::cout << "Congratulations! You won " << betAmount * 2 << " chips!"
                << std::endl;
      playerChips += betAmount * 2;
    } else {
      std::cout << "Sorry! You lost your bet." << std::endl;
    }

    // Check if the player has run out of chips
    if (playerChips <= 0) {

      std::cout << "You have run out of chips. Game over!" << std::endl;
      break;
    }

    std::cout << "You now have " << playerChips << " chips." << std::endl;

    // Ask if the player wants to play again
    if (!getYesNoInput("Do you want to play again?")) {
      std::cout << "Thanks for playing! Goodbye." << std::endl;
      break;
    }
  }
    std::cout << "You have exited Roulette...\n";
    User.updateRoom(getCurrentRoom(curRoom.getE()));
    curRoom = User.getRoom();  
  return playerChips;
}
