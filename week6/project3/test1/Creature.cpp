/*********************************************************************
** Program name: Creature.cpp (used for project 3)
** Author: Jon Raleigh
** Date: 5/14/2017
** Description: Class file for creature class
*********************************************************************/

#include "Creature.hpp"

Creature::Creature()
{
	attack_dice_number = 0;
	attack_die_faces = 0;
	defense_dice_number = 0;
	defense_die_faces = 0;
	armor = 0;
	strength_points = 0;
	attack_amount = 0;
	total_defense = 0;
	damage_done = 0;
	strength_point_message = "";
	attack_message = "";
	defense_message = "";
	strength_point_message = "";
	class_name = "";
}

int Creature::get_attack_dice_number()
{
	return attack_dice_number;
}

int Creature::get_attack_die_faces()
{
	return attack_die_faces;
}

int Creature::get_armor()
{
	return armor;
}

std::string Creature::get_attack_message()
{
	return attack_message;
}

std::string Creature::get_defense_message()
{
	return defense_message;
}

int Creature::get_defense_dice_number()
{
	return defense_dice_number;
}

int Creature::get_defense_die_faces()
{
	return defense_die_faces;
}

int Creature::get_strength_points()
{
	return strength_points;
}

int Creature::get_attack_amount()
{
	return attack_amount;
}

int Creature::get_damage_done()
{
	return damage_done;
}

std::string Creature::get_class_name()
{
	return class_name;
}

std::string Creature::get_strength_point_message()
{
	return strength_point_message;
}