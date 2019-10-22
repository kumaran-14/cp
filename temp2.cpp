#include "player_code/player_code.h"

  namespace player_code {
  
  using namespace player_state;
  
  State PlayerCode::update(State state) {
  
    logr << "Number of bots: " << state.bots.size() << endl;

    /*
array<array<TerrainType, MAP_SIZE>, MAP_SIZE> map
vector<Bot> bots
vector<Bot> enemy_bots
int64_t num_bots
int64_t num_enemy_bots
int64_t score
vector<Tower> towers
vector<Tower> enemy_towers
int64_t num_towers
int64_t num_enemy_towers
vector<Vec2D> flag_positions
state.bots[0].transform(flag_offsets[0]);
state.villagers[1].transform(flag_offsets[1]);
int64_t score

classBot
int64_t id
DoubleVec2D position
SoldierState state
IDLE, BLAST, TRANSFORM, ATTACK AND DEAD.
move(DoubleVec2D destination)
blast()
state.bots[0].blast()
blast(DoubleVec2D blast_position)
transform()

The current tile bot is in has no other units in it.
transform(DoubleVec2D transform_position)
Transform the bot at transform_position. The bot moves to blast_position and then blasts. A bot can move and transform only if,


NOTE: The bot does not move and transform in the same turn. If it reaches the transform_position in one turn, it transforms only in the next turn.
Tower
classTower
int64_t id
DoubleVec2D position
int64_t hp

TowerState state
The current state of the tower. This member tells you what the tower is doing right now, and has values IDLE, BLAST, DEAD.
blast()
Blast the tower. The tower cannot blast until it has attained a specific age TOWER_MIN_BLAST_AGE
Logging Variables

Bot(id: 2) {
        position: (5.0, 5.0)
        hp: 80
        state: IDLE
}

Helpers

findNearestFlagPosition(const State &state, DoubleVec2D position)
findNearestFreePosition(const State &state, DoubleVec2D position)
bot.transform(nearest_free_position)
This is useful to fortify an area after gaining control over it
getBotById(State &state, int64_t bot_id)
Returns a Bot by reference when provided an actor id
This comes in handy when assigning different bots different tasks and keeping track of their progress

It can be used in the following way
auto &bot_blast = getBotById(state, 1); // Returns a reference to bot with actor id 1
bot_blast.blast(DoubleVec2D(10, 10)); // Making this bot blast

auto &bot_transform = getBotById(state, 2); // Reference to bot with id 2
bot_transform.transform(DoubleVec2D(3, 7)); // Making this bot move to position (3, 7) and transform three

auto &bot_move = getBotById(state, 3); // Bot with actor id 3
bot_move.move(DoubleVec2D(5, 5)); // Making this bot move into a specific position like a flag
NOTE : Returns Bot::null if no bot exists with the given actor id. Bot::null is basically a bot constructed with an id of -1

getTowerById(State &state, int64_t tower_id)
auto &tower_blast = getTowerById(state, 12); // Returns reference to tower with actor id 12
tower_blast.blast();
NOTE : Returns Tower::null if no tower exists with the given tower id . Tower::null is a tower constructed with an id of -1

Bonus
findNearestOffset(const State &state, Vec2D position, std::function<bool(TerrainType type, uint64_t position_count)>)
A general purpose function with which you can find the nearest target position from the source position which satisfies a condition defined by you.

NOTE : Each offset in the map will be checked against this function which is passed the terrain type of that offset and the total number of bots or towers in that offset

It may look a bit scary but can be utilized using this function using C++ Lambda functions.

Let us look at an example where we find the nearest position where there are no bots or towers

auto nearest_desolate_position = [](TerrainType terrain, uint64_t actor_count){
        // Returns any position with actor count of 0 irrespective of terrain
        return (actor_count == 0);
}
*/

    /*Defense*/


  
    return state;
  }
  
  } // namespace player_code
  


 /*   
Map Constants
You’ll probably be using this constant frequently while writing code.

long MAP_SIZE = 30
Number of tiles along the side of the map.

Bot Constants
long MAX_BOT_HP = 200
Maximum HP for a bot.

long MAX_NUM_BOTS = 250
Maximum number of bots per player.

long NUM_BOTS_START = 20
Number of bots the player begins the game with.

long BOT_SPEED = 6
Units of distance the bot covers per turn.

long BOT_BLAST_IMPACT_RADIUS = 2
The maximum distance in tiles around the bot when on blasting the bot inflicts damage

long BOT_BLAST_DAMAGE_POINTS = 50
The maximum damage a bot can inflict on an enemy unit on blasting

long BOT_SPAWN_FREQUENCY = 1
Number of bots spawned per turn.

Tower Constants
long MAX_TOWER_HP = 600
Maximum HP for a tower.

long MAX_NUM_TOWERS = 150
Maximum number of towers per player.

long TOWER_BLAST_IMPACT_RADIUS = 6
The maximum distance in tiles around the tower when on blasting the tower inflicts damage

long TOWER_BLAST_DAMAGE_POINTS = 500
The maximum damage a tower can inflict on an enemy unit on blasting

long TOWER_MIN_BLAST_AGE = 3
The minimum number of turns a towe
  */