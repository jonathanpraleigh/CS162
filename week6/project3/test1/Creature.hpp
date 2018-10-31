/*********************************************************************
** Program name: Creature.cpp (used for project 3)
** Author: Jon Raleigh
** Date: 5/14/2017
** Description: Class file for creature class
*********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include "Dice.hpp"
#include <string>

class Creature
{
protected:
	int attack_dice_number, 
	attack_die_faces, 
		attack_amount,
	defense_dice_number, 
	defense_die_faces, 
	armor, 
	total_defense,
	damage_done,
	strength_points;
	std::string class_name;
	std::string attack_message;
	std::string defense_message;
	std::string strength_point_message;
	Dice CreatureDice;
public:
	Creature();
	virtual void attack() = 0;
	virtual std::string get_attack_message();
	virtual std::string get_defense_message();
	virtual void defend(Creature*) = 0;
	virtual int get_attack_dice_number();
	virtual int get_attack_die_faces();
	virtual int get_defense_dice_number();
	virtual int get_defense_die_faces();
	virtual int get_strength_points();
	virtual int get_attack_amount();
	virtual int get_damage_done();
	virtual int get_armor();
	virtual std::string get_class_name();
	virtual std::string get_strength_point_message();

};

#endif