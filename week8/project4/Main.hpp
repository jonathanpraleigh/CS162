/*********************************************************************
** Program name: Project 4
** Author: Jon Raleigh
** Date: 5/28/2017
** Description: XXX
*********************************************************************/

#ifndef MAIN_HPP
#define MAIN_HPP

#include <vector>
#include "Creature.hpp"

int menu_selection;
int numberOfFighters;
int characterChoice;
int zero_checker;
int winner;
int battleRound; 
int teamAScore;
int teamBScore;
int toRestore;
bool dead;
char loserPile;
std::vector<std::string>main_menu_options = { "Play", "Quit" };
std::string nameToAssign;
std::vector<std::string>character_options = { "Barbarian", "Blue Men", "Harry Potter", "Medusa", "Vampire" };
std::vector<Creature*>cleanUpList;

int battleWinner(Creature*, Creature*);
bool death_check(Creature*);


#endif