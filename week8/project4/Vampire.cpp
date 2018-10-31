/*********************************************************************
** Program name: Project 4
** Author: Jon Raleigh
** Date: 5/28/2017
** Description: XXX
*********************************************************************/

#include "Vampire.hpp"

Vampire::Vampire()
{
	attack_dice_number = 1;
	attack_die_faces = 12;
	attack_amount = 0;
	defense_dice_number = 1;
	defense_die_faces = 6;
	armor = 1;
	total_defense = 0;
	damage_done = 0;
	strength_points = 18;
	character_name = "Vampire";
	class_name = "Vampire";
	attack_message = "his fangs";
	defense_message = "failed to evade and was struck";
	charming = 0;
}

Vampire::Vampire(std::string name)
{
	attack_dice_number = 1;
	attack_die_faces = 12;
	attack_amount = 0;
	defense_dice_number = 1;
	defense_die_faces = 6;
	armor = 1;
	total_defense = 0;
	damage_done = 0;
	strength_points = 18;
	character_name = name;
	class_name = "Vampire";
	attack_message = "his fangs";
	defense_message = "failed to evade and was struck";
	charming = 0;
}

void Vampire::attack()
{
	//attack rolls the dice for the round's attack roll.	
	attack_amount = VampireDice.roll_dice(attack_dice_number, attack_die_faces);
}

void Vampire::defend(Creature *enemy)
{
	//rolls total defense (defense dice + armor) subtracts that from the enemy's 
	//damage and subtracts the total from strength points
	//also checks for 50/50 chance for charm special. 
	//sets battle messages. 

	total_defense = VampireDice.roll_dice(defense_dice_number, defense_die_faces) + armor;
	damage_done = enemy->get_attack_amount() - total_defense;

	if (damage_done <= 0)
	{
		damage_done = 0;
		defense_message = "The Vampire dodges";
	}
	else
	{
		charming = rand() % 2;

		if (charming == 1)
		{
			damage_done = 0;
			defense_message = "The Vampire charms his opponent and dodges";
		}
		else
		{
			defense_message = "The Vampire fails to dodge";
			strength_points -= damage_done;
		}
	}
}

void Vampire::heal()
{
	strength_points = strength_points + damage_done / 2;
}

int Vampire::get_attack_dice_number()
{
	return attack_dice_number;
}

int Vampire::get_attack_die_faces()
{
	return attack_die_faces;
}

int Vampire::get_armor()
{
	return armor;
}

std::string Vampire::get_attack_message()
{
	return attack_message;
}

std::string Vampire::get_defense_message()
{
	return defense_message;
}

int Vampire::get_defense_dice_number()
{
	return defense_dice_number;
}

int Vampire::get_defense_die_faces()
{
	return defense_die_faces;
}

int Vampire::get_strength_points()
{
	return strength_points;
}

int Vampire::get_attack_amount()
{
	return attack_amount;
}

int Vampire::get_damage_done()
{
	return damage_done;
}

std::string Vampire::get_character_name()
{
	return character_name;
}

std::string Vampire::get_class_name()
{
	return class_name;
}

std::string Vampire::get_strength_point_message()
{
	return strength_point_message;
}