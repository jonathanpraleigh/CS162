/*********************************************************************
** Program name: Vampire.hpp (used for project 3)
** Author: Jon Raleigh
** Date: 5/14/2017
** Description: header file for Vampire class
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"
#include "Dice.hpp"

class Vampire : public Creature
{
private:
	int attack_dice_number,
		attack_die_faces,
		attack_amount,
		defense_dice_number,
		defense_die_faces,
		armor,
		total_defense,
		damage_done,
		strength_points,
		charming;
	std::string class_name = "Vampire";
	std::string attack_message;
	std::string defense_message;
	Dice VampireDice;
public:
	Vampire();
	void attack() override;
	std::string get_attack_message() override;
	std::string get_defense_message() override;
	void defend(Creature*) override;
	int get_attack_dice_number() override;
	int get_attack_die_faces() override;
	int get_defense_dice_number() override;
	int get_defense_die_faces() override;
	int get_strength_points() override;
	int get_attack_amount() override;
	int get_damage_done() override;
	int get_armor() override;
	std::string get_class_name() override;
	std::string get_strength_point_message() override;
};

#endif
