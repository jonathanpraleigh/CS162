/*********************************************************************
** Program name: Medusa.cpp (used for project 3)
** Author: Jon Raleigh
** Date: 5/14/2017
** Description: Class file for Medusa class
*********************************************************************/

#include "Medusa.hpp"

Medusa::Medusa()
{
	attack_dice_number = 2;
	attack_die_faces = 6;
	attack_amount = 0;
	defense_dice_number = 1;
	defense_die_faces = 6;
	armor = 3;
	total_defense = 0;
	damage_done = 0;
	strength_points = 8;
	class_name = "Medusa";
	attack_message = "her biting snakes";
	defense_message = "failed to evade and was struck";
}

void Medusa::attack()
{
	//attack rolls the dice for the round's attack roll.
	//upon a 12 roll, sets damage to 33, which kills any opponent
	//unless the vampire uses charm. 

	attack_amount = MedusaDice.roll_dice(attack_dice_number, attack_die_faces);

	if (attack_amount == 12)
	{
		attack_amount = 33;
		attack_message = "her stone glare";
	}
	if (attack_amount < 12 )
	{
		attack_message = "her biting snakes";
	}

}


void Medusa::defend(Creature *enemy)
{
	//rolls total defense (defense dice + armor) subtracts that from the enemy's 
	//damage and subtracts the total from strength points
	//sets battle messages. 

	total_defense = MedusaDice.roll_dice(defense_dice_number, defense_die_faces) + armor;
	damage_done = enemy->get_attack_amount() - total_defense;

	if (damage_done <= 0)
	{
		damage_done = 0;
		defense_message = "Medusa dodges";
	}
	else
	{
		defense_message = "fails to dodge";
		strength_points -= damage_done;
	}
}

int Medusa::get_attack_dice_number()
{
	return attack_dice_number;
}

int Medusa::get_attack_die_faces()
{
	return attack_die_faces;
}

int Medusa::get_armor()
{
	return armor;
}

std::string Medusa::get_attack_message()
{
	return attack_message;
}

std::string Medusa::get_defense_message()
{
	return defense_message;
}

int Medusa::get_defense_dice_number()
{
	return defense_dice_number;
}

int Medusa::get_defense_die_faces()
{
	return defense_die_faces;
}

int Medusa::get_strength_points()
{
	return strength_points;
}

int Medusa::get_attack_amount()
{
	return attack_amount;
}

int Medusa::get_damage_done()
{
	return damage_done;
}

std::string Medusa::get_class_name()
{
	return class_name;
}

std::string Medusa::get_strength_point_message()
{
	return strength_point_message;
}