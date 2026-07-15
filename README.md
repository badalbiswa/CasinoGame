# Template for CPSC2720 Major Project: Text-based Adventure Game


Last Updated: 2022-12-15 by Renzo Cattoni [renzo.cattoni@uleth.ca] & Badal Biswa [badal.biswa@uleth.ca]

Notes:

* The Makefile and .gitlab-ci.yml files are set up to run on Ubuntu.
* The .gitlab-ci.yml file uses the targets in the Makefile.
* These are the tools/commands/apps used:
  * Compiler: g++
  * Style Check: cpplint
  * Static Check: cppcheck
  * Coverage Check: gcov/lcov
  * Memory Check: valgrind
  * Unit Test: gtest 
  * Documentation: doxygen
* See the version report on the pipeline.

Certain assumptions have been made:
* One repo contains the files for one project.
* All unit testing files are found in <code>test/</code> including <code>main.cpp</code>.
* All header files for the project are found in <code>include/</code> and named <code>*.h</code>, every class must have a header file.
* All project source files for the project are named <code>*.cpp</code>.
  * Any needed source files that correspond to header files are found in <code>src/</code>.
  * There is a <code>main.cpp</code> found in <code>src/project/</code>.


Renzo Cattoni, Badal Biswa

Badal:
- Was responsible for the implementation of card.h, Blackjack.cpp, deck.cpp, baccarate.cpp, roulette.cpp, slot.cpp, Blackjack.h, Board.h, Text.h
- Worked on the story and goal
- Worked style check
- Worked on the character dialogue  

Renzo:
- Was responsible for the implementation of Game.h, Item.h, NPC.h, PlaceBoClass, Player.h, Room.h, Game.cpp, NPC.cpp, PlaceboClass.cpp, Player.cpp, Room.cpp
- Worked on the story and goal
- Worked style check, memcheck, and coverage.  
- Worked on the character dialogue  


Final Notes:  

Read This Before Playing The Game:

- Some hidden quests, make sure to explore all rooms, and all the different interaction options. 
- There are some puzzles to be solved.
- There are different winning and losing conditions. Please explore all of it. 
- If a player loses all the chips, there is a secret way to gain more chips, if they explore all the rooms properly.
- To win the game the player must convert the chips to money and walk out of the casino. 


TO Have The Best Experience In The Game Don’t Read This. Please Play The Game First:

- If you find an Unknown Device, go to Slot for better odds.
- To find the Unknown Device the player must beat up the homeless guys and get the chips and after trade it with the Casino Hacker for the Unknown Device.
- There is a 1 in 5 chance that the casino hacker will appear. 
- To beat the homeless guy, the player will need the Brass Knuckles.
- To get the Brass Knuckles player will need to trade cigarettes with the Line cook.
- To get the cigarettes, the player must pretend to be the casino manager to the guy in the washroom.
 - If the player used the Unknown Device to win, the Player must give it to the homeguy when leaving to the casino or else the casino boss will know you cheated, and the Player will lose the game.
- If the player tries to go home without returning the chips to the casino hacker, you will lose.
- Players can lose if they run out of money at any time, but they will still have a second chance to win if they decide to beat up the homeless guy and take the chip.
