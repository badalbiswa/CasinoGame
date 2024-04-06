/**
 * @author Renzo Cattoni [renzo.cattoni@uleth.ca]
 * @author Badal Biswa [badal.biswa@uleth.ca]
 * @date 2024-3-28
 */

#include "Item.h"
#include "Game.h"
#include "Player.h"
#include "Room.h"
#include <iostream>
#include <sstream>

void Game::createItems() {
  Beer = Item("Beer",
              "Consumable alchoholic beverage that satifies your thirst", 6);
  Cigarette =
      Item(
          "Cigarettes",
          "Portable cancer sticks: because who needs a healthy "
          "respiratory system in a game?",
          0);
  BrassKnuckles =
      Item(
          "Brass Knuckles",
          "Enhance your fist-to-face interface with these stylish brass "
          "knuckles: sometimes a punch just needs a lot more power.",
          0);
  UnknownDevice =
      Item(
          "Unknown Device...",
          "Introducing the 'Unknown Device': Your secret weapon against the "
          "odds! Cheat your way to slot success "
          "with this mysterious gadget. "
          "Just don't let the casino catch wind of it... shhh!",
          0);
}

