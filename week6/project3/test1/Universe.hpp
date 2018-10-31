/*********************************************************************
** Program name: Universe.hpp (used for project 3)
** Author: Jon Raleigh
** Date: 5/14/2017
** Description: header file for Universe
*********************************************************************/

#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP 

#include "menu.hpp"
#include "Creature.hpp"

int menu_choice;
int character_choice;
int turn;
int zero_checker;
int round_number;
int character_one_attack_dice_number;
int character_one_attack_die_faces;
int character_two_attack_dice_number;
int character_two_attack_die_faces;
int character_one_dice_number;
int character_two_dice_number;
int character_one_dice_faces;
int character_two_dice_faces;
int character_one_strength_points;
int character_two_strength_points;
int character_one_attack_amount;
int character_two_attack_amount;
int character_one_damage_done;
int character_two_damage_done;
bool dead;
Menu gameMenu;
std::string character_one_name;
std::string character_two_name;
std::string character_one_attack_dice;
std::string character_two_attack_dice;
std::string character_one_armor;
std::string character_two_armor;
std::string character_one_attack_message;
std::string character_one_defense_message;
std::string character_two_attack_message;
std::string character_two_defense_message;
std::string character_one_strength_point_message;
std::string character_two_strength_point_message;
std::vector<std::string>menu_options = { "Start Game", "Quit" };
std::vector<std::string>character_options = { "Barbarian", "Blue Men", "Harry Potter", "Medusa", "Vampire" };
void battle(Creature*, Creature*);
void attack_round(Creature*);
void defend_round(Creature*);
bool death_check(Creature*);
void results(int, Creature*, Creature*);

#endif