/*********************************************************************
** Program name: BlueMen.cpp (used for project 3)
** Author: Jon Raleigh
** Date: 5/14/2017
** Description: Class file for BlueMen class
*********************************************************************/

#include "BlueMen.hpp"

BlueMen::BlueMen()
{
	attack_dice_number = 2;
	attack_die_faces = 10;
	attack_amount = 0;
	defense_dice_number = 3;
	defense_die_faces = 6;
	total_defense = 0;
	damage_done = 0;
	armor = 3;
	strength_points = 12;
	class_name = "Blue Men";
	attack_message = "many pointed sticks";
	defense_message = "failed to evade and was struck";
	strength_point_message = "Blue Men are still fighting!";
}

void BlueMen::attack()
{
	//attack rolls the dice for the round's attack roll.
		attack_amount = BlueMenDice.roll_dice(attack_dice_number, attack_die_faces);	
}

void BlueMen::defend(Creature *enemy)
{
	//rolls total defense (defense dice + armor) subtracts that from the enemy's 
	//damage and subtracts the total from strength points. Upon taking enough damage, 
	//reduces the defense die number by 1. 
	//also sets battle messages. 

	total_defense = BlueMenDice.roll_dice(defense_dice_number, defense_die_faces) + armor;
	damage_done = enemy->get_attack_amount() - total_defense;

	if (damage_done <= 0)
	{
		damage_done = 0;
		defense_message = "The Blue Men dodge";
	}
	else
	{
		strength_points -= damage_done;

		if (strength_points == 8 || strength_points == 4 || strength_points <= 0)
		{
			defense_message = "fail to dodge and six little men fall";
			defense_dice_number -= 1;
			if (strength_points <= 0)
			{
				strength_point_message = "The last Blue Man falls!";
			}

		}
		else
		{
			defense_message = "fail to dodge";
			strength_point_message = "are still rowdy and fighting.";
		}
	}
}

int BlueMen::get_attack_dice_number()
{
	return attack_dice_number;
}

int BlueMen::get_attack_die_faces()
{
	return attack_die_faces;
}

int BlueMen::get_armor()
{
	return armor;
}

std::string BlueMen::get_attack_message()
{
	return attack_message;
}

std::string BlueMen::get_defense_message()
{
	return defense_message;
}

int BlueMen::get_defense_dice_number()
{
	return defense_dice_number;
}

int BlueMen::get_defense_die_faces()
{
	return defense_die_faces;
}

int BlueMen::get_strength_points()
{
	return strength_points;
}

int BlueMen::get_attack_amount()
{
	return attack_amount;
}

int BlueMen::get_damage_done()
{
	return damage_done;
}

std::string BlueMen::get_class_name()
{
	return class_name;
}

std::string BlueMen::get_strength_point_message()
{
	return strength_point_message;
}