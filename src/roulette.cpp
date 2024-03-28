// /**
//  * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
//  * @author Badal Biswa [badal.biswa@uleth.ca]
//  * @date 2024-3-27
//  */
 
// #include <iostream>
// #include <vector>
// #include <string>
// #include <ctime>
// #include <cstdlib>
// #include <unordered_map>
// #include <algorithm>

// using namespace std;

// // Define the pockets on the roulette wheel
// vector<string> pockets = {
//     "0", "00",
//     "1", "2", "3", "4", "5", "6", "7", "8", "9",
//     "10", "11", "12", "13", "14", "15", "16", "17", "18", "19",
//     "20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
//     "30", "31", "32", "33", "34", "35", "36"
// };

// // Define the colors of the pockets
// unordered_map<string, string> pocket_colors = {
//     {"0", "green"},
//     {"00", "green"},
//     {"1", "red"},
//     {"2", "black"},
//     {"3", "red"},
//     {"4", "black"},
//     {"5", "red"},
//     {"6", "black"},
//     {"7", "red"},
//     {"8", "black"},
//     {"9", "red"},
//     {"10", "black"},
//     {"11", "black"},
//     {"12", "red"},
//     {"13", "black"},
//     {"14", "red"},
//     {"15", "black"},
//     {"16", "red"},
//     {"17", "black"},
//     {"18", "red"},
//     {"19", "red"},
//     {"20", "black"},
//     {"21", "red"},
//     {"22", "black"},
//     {"23", "red"},
//     {"24", "black"},
//     {"25", "red"},
//     {"26", "black"},
//     {"27", "red"},
//     {"28", "black"},
//     {"29", "black"},
//     {"30", "red"},
//     {"31", "black"},
//     {"32", "red"},
//     {"33", "black"},
//     {"34", "red"},
//     {"35", "black"},
//     {"36", "red"}
// };

// int playerChips = 100; // Initial chips for the player

// string spinWheel() {
//     // Simulate spinning the roulette wheel and return the result
//     return pockets[rand() % pockets.size()];
// }

// void displayResult(string result) {
//     // Display the result of the spin
//     string color = pocket_colors[result];
//     cout << "The ball landed on " << result << ", which is " << color << "!" << endl;
// }

// int getBetAmount() {
//     // Get the bet amount from the player
//     int betAmount;
//     cout << "Enter your bet amount (current chips: " << playerChips << "): ";
//     cin >> betAmount;
//     return betAmount;
// }

// string getBetType() {
//     // Get the type of bet from the player
//     cout << "Choose your bet type:" << endl;
//     cout << "1. Single number (35 to 1)" << endl;
//     cout << "2. Double number (17 to 1)" << endl;
//     cout << "3. Three number (11 to 1)" << endl;
//     cout << "4. Four number (8 to 1)" << endl;
//     cout << "5. Five number (6 to 1)" << endl;
//     cout << "6. Six number (5 to 1)" << endl;
//     cout << "7. Twelve numbers (2 to 1)" << endl;
//     cout << "8. Column bet (2 to 1)" << endl;
//     cout << "9. 18 numbers (1-18 or 19-36, even money)" << endl;
//     cout << "10. Red or Black (even money)" << endl;
//     cout << "11. Odd or Even (even money)" << endl;
//     cout << "Enter your choice (1-11): ";
//     string betType;
//     cin >> betType;
//     return betType;
// }

// string getBetPocket(string betType) {
//     // Get the pocket number, color, or odd/even on which the player wants to bet
//     string betPocket;
//     if (betType == "1") {
//         cout << "Enter the single pocket number you want to bet on: ";
//         cin >> betPocket;
//     } else if (betType == "2") {
//         cout << "Enter the first number of the double you want to bet on: ";
//         cin >> betPocket;
//     } else if (betType == "3") {
//         cout << "Enter the first number of the three numbers you want to bet on: ";
//         cin >> betPocket;
//     } else if (betType == "4") {
//         cout << "Enter the first number of the four numbers you want to bet on: ";
//         cin >> betPocket;
//     } else if (betType == "5") {
//         cout << "Betting on the five-number bet (0-00-1-2-3)." << endl;
//         betPocket = "five";
//     } else if (betType == "6") {
//         cout << "Enter the first number of the six numbers you want to bet on: ";
//         cin >> betPocket;
//     } else if (betType == "7") {
//         cout << "Choose the dozen (1. First 12 / 2. Second 12 / 3. Third 12): ";
//         int dozenChoice;
//         cin >> dozenChoice;
//         if (dozenChoice == 1)
//             betPocket = "first";
//         else if (dozenChoice == 2)
//             betPocket = "second";
//         else if (dozenChoice == 3)
//             betPocket = "third";
//     } else if (betType == "8") {
//         cout << "Choose the column (1. First column / 2. Second column / 3. Third column): ";
//         int columnChoice;
//         cin >> columnChoice;
//         if (columnChoice == 1)
//             betPocket = "first";
//         else if (columnChoice == 2)
//             betPocket = "second";
//         else if (columnChoice == 3)
//             betPocket = "third";
//     } else if (betType == "9") {
//         cout << "Choose the range (1. 1-18 / 2. 19-36): ";
//         int rangeChoice;
//         cin >> rangeChoice;
//         if (rangeChoice == 1)
//             betPocket = "1-18";
//         else if (rangeChoice == 2)
//             betPocket = "19-36";
//     } else if (betType == "10") {
//         cout << "Choose the color (1. Black / 2. Red): ";
//         int colorChoice;
//         cin >> colorChoice;
//         betPocket = (colorChoice == 1) ? "black" : "red";
//     } else if (betType == "11") {
//         cout << "Choose odd or even (1. Odd / 2. Even): ";
//         int oddEvenChoice;
//         cin >> oddEvenChoice;
//         betPocket = (oddEvenChoice == 1) ? "odd" : "even";
//     }
//     return betPocket;
// }

// bool validateBet(string betType, string betPocket) {
//     // Validate the bet
//     if (betType == "1") {
//         if (find(pockets.begin(), pockets.end(), betPocket) != pockets.end()) {
//             return true;
//         } else {
//             cout << "Invalid pocket number. Please enter a valid pocket number." << endl;
//             return false;
//         }
//     } else if (betType == "2") {
//         if (find(pockets.begin(), pockets.end(), betPocket) != pockets.end()) {
//             return true;
//         } else {
//             cout << "Invalid double number. Please enter a valid pocket number." << endl;
//             return false;
//         }
//     } else if (betType == "3") {
//         if (find(pockets.begin(), pockets.end(), betPocket) != pockets.end() &&
//             find(pockets.begin(), pockets.end(), to_string(stoi(betPocket) + 1)) != pockets.end() &&
//             find(pockets.begin(), pockets.end(), to_string(stoi(betPocket) + 2)) != pockets.end()) {
//             return true;
//         } else {
//             cout << "Invalid three-number bet. Please enter a valid starting pocket number." << endl;
//             return false;
//         }
//     } else if (betType == "4") {
//         if (find(pockets.begin(), pockets.end(), betPocket) != pockets.end() &&
//             find(pockets.begin(), pockets.end(), to_string(stoi(betPocket) + 1)) != pockets.end() &&
//             find(pockets.begin(), pockets.end(), to_string(stoi(betPocket) + 3)) != pockets.end()) {
//             return true;
//         } else {
//             cout << "Invalid four-number bet. Please enter a valid starting pocket number." << endl;
//             return false;
//         }
//     } else if (betType == "5") {
//         if (betPocket == "five") {
//             return true;
//         } else {
//             cout << "Invalid five-number bet. Please choose the five-number bet." << endl;
//             return false;
//         }
//     } else if (betType == "6") {
//         if (find(pockets.begin(), pockets.end(), betPocket) != pockets.end() &&
//             find(pockets.begin(), pockets.end(), to_string(stoi(betPocket) + 1)) != pockets.end() &&
//             find(pockets.begin(), pockets.end(), to_string(stoi(betPocket) + 2)) != pockets.end() &&
//             find(pockets.begin(), pockets.end(), to_string(stoi(betPocket) + 3)) != pockets.end() &&
//             find(pockets.begin(), pockets.end(), to_string(stoi(betPocket) + 4)) != pockets.end() &&
//             find(pockets.begin(), pockets.end(), to_string(stoi(betPocket) + 5)) != pockets.end()) {
//             return true;
//         } else {
//             cout << "Invalid six-number bet. Please enter a valid starting pocket number." << endl;
//             return false;
//         }
//     }
//     return true;
// }

// bool isEven(string pocket) {
//     // Check if the pocket is even
//     int number = stoi(pocket);
//     return number % 2 == 0;
// }

// void playRouletteGame() {
//     // Seed the random number generator
//     srand(time(0));

//     cout << "Welcome to the Roulette Wheel Game!" << endl;
//     while (true) {
//         // Allow player to place multiple bets before spinning the wheel
//         vector<pair<int, string>> bets;
//         while (true) {
//             int betAmount = getBetAmount();
//             string betType = getBetType();
//             string betPocket = getBetPocket(betType);
//             if (validateBet(betType, betPocket)) {
//                 bets.push_back({betAmount, betType});
//             }
//             cout << "Do you want to place another bet? (yes/no): ";
//             string continueBetting;
//             cin >> continueBetting;
//             if (continueBetting != "yes") {
//                 break;
//             }
//         }

//         // Spin the wheel and display the result
//         string result = spinWheel();
//         displayResult(result);

//         // Calculate and display payouts for each bet
//         for (const auto& bet : bets) {
//             int betAmount = bet.first;
//             string betType = bet.second;
//             string betPocket = getBetPocket(betType); // Declare betPocket here
//             if (validateBet(betType, betPocket)) {
//                 if (betType == "1" && result == betPocket) {
//                     playerChips += betAmount * 35;
//                     cout << "Your bet of " << betAmount << " chips on type " << betType << " at pocket " << betPocket << " won " << betAmount * 35 << " chips." << endl;
//                 } else if (betType == "2" && (result == betPocket || result == to_string(stoi(betPocket) + 1))) {
//                     playerChips += betAmount * 17;
//                     cout << "Your bet of " << betAmount << " chips on type " << betType << " at pocket " << betPocket << " won " << betAmount * 17 << " chips." << endl;
//                 } else if (betType == "3" && (result == betPocket || result == to_string(stoi(betPocket) + 1) || result == to_string(stoi(betPocket) + 2))) {
//                     playerChips += betAmount * 11;
//                     cout << "Your bet of " << betAmount << " chips on type " << betType << " at pocket " << betPocket << " won " << betAmount * 11 << " chips." << endl;
//                 } else if (betType == "4" && (result == betPocket || result == to_string(stoi(betPocket) + 1) || result == to_string(stoi(betPocket) + 3) || result == to_string(stoi(betPocket) + 4))) {
//                     playerChips += betAmount * 8;
//                     cout << "Your bet of " << betAmount << " chips on type " << betType << " at pocket " << betPocket << " won " << betAmount * 8 << " chips." << endl;
//                 } else if (betType == "5" && (result == "0" || result == "00" || result == "1" || result == "2" || result == "3")) {
//                     playerChips += betAmount * 6;
//                     cout << "Your bet of " << betAmount << " chips on type " << betType << " at pocket " << betPocket << " won " << betAmount * 6 << " chips." << endl;
//                 } else if (betType == "6" && (result == betPocket || result == to_string(stoi(betPocket) + 1) || result == to_string(stoi(betPocket) + 2) || result == to_string(stoi(betPocket) + 3) || result == to_string(stoi(betPocket) + 4) || result == to_string(stoi(betPocket) + 5))) {
//                     playerChips += betAmount * 5;
//                     cout << "Your bet of " << betAmount << " chips on type " << betType << " at pocket " << betPocket << " won " << betAmount * 5 << " chips." << endl;
//                 } else if (betType == "7" && ((betPocket == "first" && stoi(result) >= 1 && stoi(result) <= 12) || (betPocket == "second" && stoi(result) >= 13 && stoi(result) <= 24) || (betPocket == "third" && stoi(result) >= 25 && stoi(result) <= 36))) {
//                     playerChips += betAmount * 2;
//                     cout << "Your bet of " << betAmount << " chips on type " << betType << " at dozen " << betPocket << " won " << betAmount * 2 << " chips." << endl;
//                 } else if (betType == "8" && ((betPocket == "first" && stoi(result) % 3 == 1) || (betPocket == "second" && stoi(result) % 3 == 2) || (betPocket == "third" && stoi(result) % 3 == 0))) {
//                     playerChips += betAmount * 2;
//                     cout << "Your bet of " << betAmount << " chips on type " << betType << " at column " << betPocket << " won " << betAmount * 2 << " chips." << endl;
//                 } else if (betType == "9" && ((betPocket == "1-18" && stoi(result) >= 1 && stoi(result) <= 18) || (betPocket == "19-36" && stoi(result) >= 19 && stoi(result) <= 36))) {
//                     playerChips += betAmount * 2;
//                     cout << "Your bet of " << betAmount << " chips on type " << betType << " at range " << betPocket << " won " << betAmount * 2 << " chips." << endl;
//                 } else if (betType == "10" && (pocket_colors[result] == betPocket)) {
//                     playerChips += betAmount * 2;
//                     cout << "Your bet of " << betAmount << " chips on type " << betType << " at color " << betPocket << " won " << betAmount * 2 << " chips." << endl;
//                 } else if (betType == "11" && ((betPocket == "odd" && stoi(result) % 2 != 0) || (betPocket == "even" && stoi(result) % 2 == 0))) {
//                     playerChips += betAmount * 2;
//                     cout << "Your bet of " << betAmount << " chips on type " << betType << " at " << betPocket << " won " << betAmount * 2 << " chips." << endl;
//                 } else {
//                     playerChips -= betAmount;
//                     cout << "Your bet of " << betAmount << " chips on type " << betType << " at " << betPocket << " lost " << betAmount << " chips." << endl;
//                 }
//             }
//         }

//         // Check if the player has run out of chips
//         if (playerChips <= 0) {
//             cout << "You have run out of chips. Game over!" << endl;
//             break;
//         }

//         cout << "You now have " << playerChips << " chips." << endl;

//         // Ask if the player wants to play again
//         cout << "Do you want to play again? (yes/no): ";
//         string playAgain;
//         cin >> playAgain;
//         if (playAgain != "yes") {
//             cout << "Thanks for playing! Goodbye." << endl;
//             break;
//         }
//     }
// }

// int main() {
//     playRouletteGame();
//     return 0;
// }
