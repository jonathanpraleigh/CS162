/*********************************************************************
** Program name: Universe.cpp (used for project 3)
** Author: Jon Raleigh
** Date: 5/14/2017
** Description: implementation file for game
*********************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include "Universe.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Creature.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "menu.hpp"
#include "Vampire.hpp"
#include "Dice.hpp"

int main()
{
	for (;;)
	{
		Menu gameMenu;
		Creature *player1 = NULL;
		Creature *player2 = NULL;

		//creates pointers to player1 and player2, setting them initially to null. 

		menu_choice = gameMenu.menuDisplay(menu_options);

		if (menu_choice == 1)
		{

			std::cout << "\n******************************************\n"
				<< "* Choose your a character for player one *"
				<< "\n******************************************\n";

			character_choice = gameMenu.menuDisplay(character_options);

			if (character_choice == 1)
			{
				player1 = new Barbarian;
			}
			else if (character_choice == 2)
			{
				player1 = new BlueMen;
			}
			else if (character_choice == 3)
			{
				player1 = new HarryPotter;
			}
			else if (character_choice == 4)
			{
				player1 = new Medusa;
			}
			else if (character_choice == 5)
			{
				player1 = new Vampire;
			}

			std::cout << "\n******************************************\n"
				<< "* Choose your a character for player two *"
				<< "\n******************************************\n";

			character_choice = gameMenu.menuDisplay(character_options);

			if (character_choice == 1)
			{
				player2 = new Barbarian;
			}
			else if (character_choice == 2)
			{
				player2 = new BlueMen;
			}
			else if (character_choice == 3)
			{
				player2 = new HarryPotter;
			}
			else if (character_choice == 4)
			{
				player2 = new Medusa;
			}
			else if (character_choice == 5)
			{
				player2 = new Vampire;
			}

			battle(player1, player2);

			delete player1;
			delete player2;

		}
		else if (menu_choice == 2)
		{
			return 0;
		}
		

	}
}


void battle(Creature *p1, Creature *p2)
{

	//manages the turns, attack and defend.
	//I opted to create two separate paths depending on who goes first.
	//It added a few lines of code, but kept it pretty simply and organized. 

	Dice dice;
	turn = dice.roll_dice(1, 2);

	dead = false;

	round_number = 0;

	if (turn == 1)
	{
		while (dead == false)
		{
			turn = 1;
			p1->attack();
			p2->defend(p1);
			dead = death_check(p2);
			round_number++;
			results(1, p1, p2);

			if (dead == true)
			{
				return;
			}

			turn = 2;
			p2->attack();
			p1->defend(p2);
			dead = death_check(p1);
			round_number++;
			results(2, p1, p2);

			if (dead == true)
			{
				return;
			}

		}
	}
	else if (turn == 2)
	{
		while (dead == false)
		{
			p2->attack();
			p1->defend(p2);
			dead = death_check(p1);
			round_number++;
			results(2, p1, p2);

			if (dead == true)
			{
				return;
			}

			p1->attack();
			p2->defend(p1);
			dead = death_check(p2);
			round_number++;
			results(1, p1, p2);

			if (dead == true)
			{
				return;
			}
		}

	}

}


bool death_check(Creature * dead_or_not)
{
	//simple death checker. 

	zero_checker = dead_or_not->get_strength_points();

	if (zero_checker <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void results(int t, Creature *p1, Creature *p2)
{
	// display round results. It's probably not the most efficient way,
	// but it pulls also displayed values up front and then displays them
	// below. This helped during debugging, as I could turn things off and 
	// change function names pretty easily by keeping everything up top. 

	std::cout << "\n******************************************\n"
		<< " Round "
		<< round_number
		<< " Results"
		<< "\n******************************************\n";
	character_one_name = p1->get_class_name();
	character_one_attack_dice_number = p1->get_attack_dice_number();
	character_one_attack_die_faces = p1->get_attack_die_faces();
	character_one_dice_number = p1->get_defense_dice_number();
	character_one_dice_faces = p1->get_defense_die_faces();
	character_one_armor = p1->get_armor();
	character_one_strength_points = p1->get_strength_points();
	character_one_attack_amount = p1->get_attack_amount();
	character_one_damage_done = p1->get_damage_done();
	character_one_attack_message = p1->get_attack_message();
	character_one_defense_message = p1->get_defense_message();
	character_one_strength_point_message = p1->get_strength_point_message();

	character_two_name = p2->get_class_name();
	character_two_attack_dice_number = p2->get_attack_dice_number();
	character_two_attack_die_faces = p2->get_attack_die_faces();
	character_two_dice_number = p2->get_defense_dice_number();
	character_two_dice_faces = p2->get_defense_die_faces();
	character_two_armor = p2->get_armor(); 
	character_two_strength_points = p2->get_strength_points();
	character_two_attack_amount = p2->get_attack_amount();
	character_two_damage_done = p2->get_damage_done();
	character_two_attack_message = p2->get_attack_message();
	character_two_defense_message = p2->get_defense_message();
	character_two_strength_point_message = p2->get_strength_point_message();

	std::cout << "\n******************************************\n"
		<< " Player One " << character_one_name
		<< "\n******************************************\n"
		<< "Attack: " << character_one_attack_dice_number << "d" << character_one_attack_die_faces
		<< "\nDefense: " << character_one_dice_number << "d" << character_one_dice_faces
		<< "\nArmor: " << character_one_armor
		<< "\nStrength Points: " << character_one_strength_points
		<< "\n******************************************\n"
		<< "\n"
		<< "\n******************************************\n"
		<< " Player Two " << character_two_name
		<< "\n******************************************\n"
		<< "Attack: " << character_two_attack_dice_number << "d" << character_two_attack_die_faces
		<< "\nDefense: " << character_two_dice_number << "d" << character_two_dice_faces
		<< "\nArmor: " << character_two_armor
		<< "\nStrength Points: " << character_two_strength_points
		<< "\n******************************************\n";

	//t for turn. Formatting for what's going on in each round. 
	
	if (t == 1)
	{
		std::cout << character_one_name
			<< " attacked "
			<< character_two_name
			<< " with "
			<< character_one_attack_message
			<< " for "
			<< character_one_attack_amount
			<< ".\n"
			<< character_two_name
			<< " "
			<< character_two_defense_message
			<< " for "
			<< character_two_damage_done
			<< " points of damage.\n"
			<< character_two_strength_point_message
			<< ".\n";

		if (p2->get_strength_points() <= 0)
		{
			std::cout << character_one_name
				<< " has been defeated!\n";
			return;
		}

	}
	if (t == 2)
	{
		std::cout << character_two_name
			<< " attacked "
			<< character_one_name
			<< " with "
			<< character_two_attack_message
			<< " for "
			<< character_two_attack_amount
			<< ".\n"
			<< character_one_name
			<< " "
			<< character_one_defense_message
			<< " for "
			<< character_one_damage_done
			<< " points of damage.\n"
			<< character_one_strength_point_message
			<< ".\n";
		
		if (p1->get_strength_points() <= 0)
		{
			std::cout << character_one_name
				<< " has been defeated!\n";
		}
	}


}








