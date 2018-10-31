/*********************************************************************
** Program name: Project 4
** Author: Jon Raleigh
** Date: 5/28/2017
** Description: XXX
*********************************************************************/

#include "HarryPotter.hpp"


HarryPotter::HarryPotter()
{
	attack_dice_number = 2;
	attack_die_faces = 6;
	attack_amount = 0;
	defense_dice_number = 2;
	defense_die_faces = 6;
	armor = 0;
	total_defense = 0;
	damage_done = 0;
	strength_points = 10;
	life_number = 1;
	character_name = "Harry Potter";
	class_name = "Harry Potter";
	attack_message = "his wand";
	defense_message = "failed to evade and was struck";
	strength_point_message = "Harry Potter is still fighting!";
}

HarryPotter::HarryPotter(std::string name)
{
	attack_dice_number = 2;
	attack_die_faces = 6;
	attack_amount = 0;
	defense_dice_number = 2;
	defense_die_faces = 6;
	armor = 0;
	total_defense = 0;
	damage_done = 0;
	strength_points = 10;
	life_number = 1;
	character_name = name;
	class_name = "Harry Potter";
	attack_message = "his wand";
	defense_message = "failed to evade and was struck";
	strength_point_message = "Harry Potter is still fighting!";
}

void HarryPotter::attack()
{
	//attack rolls the dice for the round's attack roll.
	attack_amount = HarryPotterDice.roll_dice(attack_dice_number, attack_die_faces);
}

void HarryPotter::defend(Creature *enemy)
{
	//rolls total defense (defense dice + armor) subtracts that from the enemy's 
	//damage and subtracts the total from strength points
	//handles the resurrection special by resetting strength points. 

	total_defense = HarryPotterDice.roll_dice(defense_dice_number, defense_die_faces) + armor;
	damage_done = enemy->get_attack_amount() - total_defense;

	if (damage_done <= 0)
	{
		damage_done = 0;
		defense_message = "Harry Potter dodges";
	}
	else
	{
		strength_points -= damage_done;
		defense_message = "fails to dodge";

		if (strength_points <= 0 && life_number == 1)
		{
			defense_message = "Harry Potter fails to dodge, but the power of Hogwarts brings him back, stronger than before!";
			strength_points = 20;
			life_number = 2;
		}	
	}

}

void HarryPotter::heal()
{
	if (life_number == 2)
	{
		strength_points = strength_points + damage_done / 2;
	}
	else
	{
		//nothing happens. The emo wizard already got an extra life. 
	}
}

int HarryPotter::get_attack_dice_number()
{
	return attack_dice_number;
}

int HarryPotter::get_attack_die_faces()
{
	return attack_die_faces;
}

int HarryPotter::get_armor()
{
	return armor;
}

std::string HarryPotter::get_attack_message()
{
	return attack_message;
}

std::string HarryPotter::get_defense_message()
{
	return defense_message;
}

int HarryPotter::get_defense_dice_number()
{
	return defense_dice_number;
}

int HarryPotter::get_defense_die_faces()
{
	return defense_die_faces;
}

int HarryPotter::get_strength_points()
{
	return strength_points;
}

int HarryPotter::get_attack_amount()
{
	return attack_amount;
}

int HarryPotter::get_damage_done()
{
	return damage_done;
}

std::string HarryPotter::get_character_name()
{
	return character_name;
}

std::string HarryPotter::get_class_name()
{
	return class_name;
}

std::string HarryPotter::get_strength_point_message()
{
	return strength_point_message;
}