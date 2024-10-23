// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../player.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../game_object.hpp"
#include "../item.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../wizard.hpp"
#include "magomachy.hpp"

#include <type_traits>

namespace cpp_client
{

namespace magomachy
{


Player_::Player_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"aether", Any{std::decay<decltype(aether)>::type{}}},
        {"attack", Any{std::decay<decltype(attack)>::type{}}},
        {"clientType", Any{std::decay<decltype(client_type)>::type{}}},
        {"defense", Any{std::decay<decltype(defense)>::type{}}},
        {"health", Any{std::decay<decltype(health)>::type{}}},
        {"lost", Any{std::decay<decltype(lost)>::type{}}},
        {"name", Any{std::decay<decltype(name)>::type{}}},
        {"opponent", Any{std::decay<decltype(opponent)>::type{}}},
        {"reasonLost", Any{std::decay<decltype(reason_lost)>::type{}}},
        {"reasonWon", Any{std::decay<decltype(reason_won)>::type{}}},
        {"speed", Any{std::decay<decltype(speed)>::type{}}},
        {"timeRemaining", Any{std::decay<decltype(time_remaining)>::type{}}},
        {"wizard", Any{std::decay<decltype(wizard)>::type{}}},
        {"won", Any{std::decay<decltype(won)>::type{}}},
    },
    aether(variables_["aether"].as<std::decay<decltype(aether)>::type>()),
    attack(variables_["attack"].as<std::decay<decltype(attack)>::type>()),
    client_type(variables_["clientType"].as<std::decay<decltype(client_type)>::type>()),
    defense(variables_["defense"].as<std::decay<decltype(defense)>::type>()),
    health(variables_["health"].as<std::decay<decltype(health)>::type>()),
    lost(variables_["lost"].as<std::decay<decltype(lost)>::type>()),
    name(variables_["name"].as<std::decay<decltype(name)>::type>()),
    opponent(variables_["opponent"].as<std::decay<decltype(opponent)>::type>()),
    reason_lost(variables_["reasonLost"].as<std::decay<decltype(reason_lost)>::type>()),
    reason_won(variables_["reasonWon"].as<std::decay<decltype(reason_won)>::type>()),
    speed(variables_["speed"].as<std::decay<decltype(speed)>::type>()),
    time_remaining(variables_["timeRemaining"].as<std::decay<decltype(time_remaining)>::type>()),
    wizard(variables_["wizard"].as<std::decay<decltype(wizard)>::type>()),
    won(variables_["won"].as<std::decay<decltype(won)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Player_::~Player_() = default;

void Player_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Player treated as a vector, but it is not a vector.");
}

void Player_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Player treated as a vector, but it is not a vector.");
}

void Player_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Player treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Player_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Player treated as a map, but it is not a map.");
}

bool Player_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Player_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "opponent")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
   if(member == "wizard")
   { 
      to_change->as<Wizard>() = std::static_pointer_cast<Wizard_>(ref);
      return;
   }
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Player treated as a reference, but it is not a reference.");
}


} // magomachy

} // cpp_client