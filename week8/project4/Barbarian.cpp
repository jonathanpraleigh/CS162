/*********************************************************************
** Program name: Project 4
** Author: Jon Raleigh
** Date: 5/28/2017
** Description: XXX
*********************************************************************/

#include "Barbarian.hpp"
#include "Dice.hpp"

Barbarian::Barbarian()
{
	attack_dice_number = 2;
	attack_die_faces = 6;
	attack_amount = 0;
	defense_dice_number = 2;
	defense_die_faces = 6;
	total_defense = 0;
	damage_done = 0;
	armor = 0;
	strength_points = 12;
	character_name = "Barbarian";
	class_name = "Barbarian";
	attack_message = "his giant sword";
	defense_message = "failed to evade and was struck";
	strength_point_message = "is still fighting!";
}

Barbarian::Barbarian(std::string name)
{
	attack_dice_number = 2;
	attack_die_faces = 6;
	attack_amount = 0;
	defense_dice_number = 2;
	defense_die_faces = 6;
	total_defense = 0;
	damage_done = 0;
	armor = 0;
	strength_points = 12;
	character_name = name;
	class_name = "Barbarian";
	attack_message = "his giant sword";
	defense_message = "failed to evade and was struck";
	strength_point_message = "is still fighting!";
}

void Barbarian::attack()
{
	//attack rolls the dice for the round's attack roll. 
	attack_amount = BarbarianDice.roll_dice(attack_dice_number, attack_die_faces);
}

void Barbarian::defend(Creature * enemy)
{
	//rolls total defense (defense dice + armor) subtracts that from the enemy's 
	//damage and subtracts the total from strength points
	//also sets defense messages. 
	total_defense = BarbarianDice.roll_dice(defense_dice_number, defense_die_faces) + armor;
	damage_done = enemy->get_attack_amount() - total_defense;

	if (damage_done <= 0)
	{
		damage_done = 0;
		defense_message = "The Barbarian dodges";
	}
	else 
	{
		defense_message = "fails to dodge";
		strength_points -= damage_done;
		if (strength_points <= 0)
		{
			strength_point_message = "The Barbarian falls";
		}
	}
}

void Barbarian::heal()
{
	strength_points = strength_points + damage_done / 2;
}

int Barbarian::get_attack_dice_number()
{
	return attack_dice_number;
}

int Barbarian::get_attack_die_faces()
{
	return attack_die_faces;
}

int Barbarian::get_armor()
{
	return armor;
}

std::string Barbarian::get_attack_message()
{
	return attack_message;
}

std::string Barbarian::get_defense_message()
{
	return defense_message;
}

int Barbarian::get_defense_dice_number()
{
	return defense_dice_number;
}

int Barbarian::get_defense_die_faces()
{
	return defense_die_faces;
}

int Barbarian::get_strength_points()
{
	return strength_points;
}

int Barbarian::get_attack_amount()
{
	return attack_amount;
}

int Barbarian::get_damage_done()
{
	return damage_done;
}

std::string Barbarian::get_character_name()
{
	return character_name;
}

std::string Barbarian::get_class_name()
{
	return class_name;
}

std::string Barbarian::get_strength_point_message()
{
	return strength_point_message;
}