# finalAdventureProject
Usage Instructions:
Installation instructions:
	The best way to run the game is to clone the git repository into the desired flip folder and follow the instructions below:
	

git clone https://github.com/originalname51/adventure_game.git (or unzip the folder turned in)

“cmake build .”

“make”

run the executable created (you may have to enter “chmod 111 filename” depending on your terminal settings and permissions)

In-game command instructions:

The command structure of the game will allow for the following actions and combinations. Please keep in mind that green key 

and goose token need to be typed into the command line as “greenkey” and “goosetoken.” 


Single word actions:

LOOK: This command will print a long form description of the current player room.

EXAMINE: Similar to look, this command will print a long-form description, but will also be used later to examine particular 
objects and puzzle items.


REST: This action is hidden, but will allow the player to remove the sickness they might pickup through the coarse of the game.

HELP: This action will print a list of commands along with example usages.

EMPTY: This “action” will cause the game to ask for input once again from the player

Action on/at Item:

While these examples won’t cover every possible combination, they are meant to demonstrate valid command structure and 
possible actions.

GO NORTH: Go, when followed by any cardinal direction (or the LADDER) item, will attempt to move the player in the desired 
direction.

PICKUP GREENKEY: This action will pickup the greenkey item and place it into the player’s inventory.

PICK GREENKEY: Pick is an alias for pickup, and both will result in the same action.

DROP GOOSETOKEN: This will drop the goosetoken from the player’s inventory, and leave it in the room where it was dropped.

USE TORCH: Use will generally use an item in a “default” way. The player may have to experiment with this to find what item 
performs which actions if not evident.

OPEN Box: This will open a box or door if the state of the item is shut.

EXAMINE Box: This action will look at an item in greater detail to see if there is anything significant about it.

USE/DROP/THROW with item on feature/item:

These actions will all involve the following structure: USE ITEM1 on ITEM2

USE ROPE on PILLAR: This will use the default action of the rope on the pillar if applicable.

USE DISCUS on LIGHT, USE CRYSTAL on DOOR, USE PITCHER on BOWL

DROP STATUE on TABLET

THROW DISCUS at LIGHT

Detailed Game Walkthrough

The section that follows is a “Cheat Sheet” of how to beat the game in the fewest moves possible. The guide is divided 
loosely into three sections: GREEN WING, BLUE WING, and WHITE WING. Each line under a room will represent a command that 
needs to be entered to pass the room or solve a puzzle. There are of course many other possible actions in each room, but 
this guide omits those for the sake of brevity.



STARTING ROOM

pick greenkey (to enter green wing) (go west)

pick bluekey (to enter blue wing)

pick whitekey (to enter white wing)

GREEN WING

ROOM 1

Examine the fox token, goose token and beantoken

Pick goosetoken

Use boat

Drop goosetoken

Use boat

Pick foxtoken

Use boat

drop/throw foxtoken

PICK goosetoken

Use boat

Drop goosetoken

Pick beantoken

Use boat

Drop beantoken

Use boat

Pick goosetoken

Use boat

Drop goosetoken

Door opens; go west.

ROOM 2

Examine chair

Examine bucket

Pick bucket

Go North, examine kid, then go south and go south again.

ROOM 3

Examine basin

Use bucket on basin

Go north, then go north again to get to final room

ROOM 4

Examine kid

Use bucket on kid

Go anywhere, you beat the room wing!

BLUE WING

ROOM 1

pick torch

open door

go stairs || go north || go north stairs

ROOM 2

look ceiling

pick fish || pick babelfish

look glyphs

go north

ROOM 3

pick ball

use ball on pipe

go north

ROOM 4

use rope on whitepillar

use rope on blackpillar

go north

ROOM 5

(room will remain dark if player has no torch)

pick statue

drop statue on tablet

open box

go south (until player is in the main room again)

WHITE WING

ROOM 1

pick discus

use discus on light

go ladder

ROOM 2

pick crystal

look eastwall

look westwall

look northwall

go north

ROOM 3

use discus on lightpillar

use discus on rope

ROOM 4

examine light

(assuming you have torch in backpack)

drop torch || throw torch

ROOM 5

pick pitcher

user pitcher on bowl

(once last action is complete, you are returned to the 3 key room)

RETURN to STARTING ROOM (NEED TO CHECK ON THIS LOGIC)

use discus on wall

use crystal on wall

