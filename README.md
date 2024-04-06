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


Group F

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
- Some hidden quest, make sure to explore all rooms, and all the different interaction options. 
- There are some puzzles to be solved. 
- If you find an Unknown Device, go to Slot for better odds.
- To find the Unknown Device the player must beat up the homeless guys and get the chips and after trade it with the Casino Hacker for the Unknown Device. 
- To beat the homeless guy, the player will need the Brass Knuckles.
- To get the Brass Knuckles player will need to trade cigarettes with the Line cook.
- To get the cigarettes, the player must pretend to be the casino manager to the guy in the washroom.
- There are different winning and losing conditions.
- To win the game the player must convert the chips to money and walk out of the casino. 
 - If the player used the Unknown Device to win, the Player must give it to the homeguy when leaving to the casino or else the casino boss will know, and the Player will lose the game.
- Players can lose if they run out of money, and are beaten up by the homeless guy, without the secret item. If a player is caught cheating by the casino boss the player will also lose.

