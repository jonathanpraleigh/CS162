/*********************************************************************
** Program name: Project 4
** Author: Jon Raleigh
** Date: 5/28/2017
** Description: XXX
*********************************************************************/

#include "Main.hpp"
#include "Menu.hpp"
#include "InputValidator.hpp"
#include "Queue.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Creature.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Vampire.hpp"
#include <iostream>
#include <string>


int main()
{
	Menu BattleMenu;
	InputValidator BattleValidator;
	Queue BattleQueue1;
	Queue BattleQueue2;
	Queue LoserQueue;
	Creature *player1 = NULL;
	Creature *player2 = NULL;
	teamAScore = 0;
	teamAScore = 0;

	for (;;)
	{
		menu_selection = BattleMenu.menuDisplay(main_menu_options);

		if (menu_selection == 1)
		{
			std::cout << "\nEnter the number of fighters\n";

			numberOfFighters = BattleValidator.testInteger(1, 20, true, true, false);



			for (int i=0; i <numberOfFighters; i++)
			{
				std::cout << "\n******************************************\n"
						  <<   "* Choose your a character for player one *"
					      << "\n******************************************\n";
				
				characterChoice = BattleMenu.menuDisplay(character_options);

				std::cout << "\nEnter a name for your character\n";

				std::cin >> nameToAssign;

				if (characterChoice == 1)
				{
					player1 = new Barbarian(nameToAssign);
				}
				else if (characterChoice == 2)
				{
					player1 = new BlueMen(nameToAssign);
				}
				else if (characterChoice == 3)
				{
					player1 = new HarryPotter(nameToAssign);
				}
				else if (characterChoice == 4)
				{
					player1 = new Medusa(nameToAssign);
				}
				else if (characterChoice == 5)
				{
					player1 = new Vampire(nameToAssign);
				}
				
				BattleQueue1.addBack(player1);
				cleanUpList.push_back(player1);
				//Assigns pointer to that character to a Node with Queue logic. 	
			}

			for (int i = 0; i <numberOfFighters; i++)
			{
				//player TWO loop
				std::cout << "\n******************************************\n"
					      <<   "* Choose your a character for player two *"
					      << "\n******************************************\n";

				characterChoice = BattleMenu.menuDisplay(character_options);

				std::cout << "\nEnter a name for your character\n";

				std::cin >> nameToAssign;

				if (characterChoice == 1)
				{
					player2 = new Barbarian(nameToAssign);
				}
				else if (characterChoice == 2)
				{
					player2 = new BlueMen(nameToAssign);
				}
				else if (characterChoice == 3)
				{
					player2 = new HarryPotter(nameToAssign);
				}
				else if (characterChoice == 4)
				{
					player2 = new Medusa(nameToAssign);
				}
				else if (characterChoice == 5)
				{
					player2 = new Vampire(nameToAssign);
				}

				BattleQueue2.addBack(player2);
				cleanUpList.push_back(player2);
	
			}

			//BattleQueue1.displayQueue();
			//BattleQueue2.displayQueue();

			battleRound = 1;

			while (BattleQueue1.isEmpty() == false && BattleQueue2.isEmpty() == false)
			{
				player1 = BattleQueue1.getFront();
				player2 = BattleQueue2.getFront();

				winner = battleWinner(player1, player2);

				std::cout << "\nRound " << battleRound << ": Team A " << BattleQueue1.getFront()->get_character_name() << " VS. Team B " << BattleQueue2.getFront()->get_character_name() << ".\n";

				if (winner == 1)
				{
					std::cout << BattleQueue1.getFront()->get_character_name() << " wins!\n";
					teamAScore += 10;
					BattleQueue1.getFront()->heal();
					BattleQueue1.addBack(BattleQueue1.getFront());
					BattleQueue1.removeFront();
					LoserQueue.addFront(BattleQueue2.getFront());
					BattleQueue2.removeFront();
				}
				else if (winner == 2)
				{
					std::cout << BattleQueue2.getFront()->get_character_name() << " wins!\n";
					teamBScore += 10;
					BattleQueue2.getFront()->heal();
					BattleQueue2.addBack(BattleQueue2.getFront());
					BattleQueue2.removeFront();
					LoserQueue.addFront(BattleQueue1.getFront());
					BattleQueue1.removeFront();
				}
				battleRound++;
			}


			std::cout << "\nTeam A Score: " << teamAScore << ". Team B Score: " << teamBScore << ".\n";

			if (teamAScore > teamBScore)
			{
				std::cout << "Team A is the winner!\n";
			}
			else if (teamBScore > teamAScore)
			{
				std::cout << "Team B is the winner!\n";
			}

			std::cout << "Display contents of the loser pile? (y/n)?\n";
			
			std::cin >> loserPile;

			if (loserPile == 'y' || loserPile == 'Y')
			{
				LoserQueue.displayQueue();
				std::cout << "\n";
			}

	/*		if (BattleQueue1.isEmpty() == false)
			{
				Queue::QueueNode *nodePtr = BattleQueue1.front->nextQueueNode;
				
				player1 = BattleQueue1.getFront();
				
				delete player1;
				BattleQueue1.front->creaturePtr = nullptr;

				while (nodePtr != BattleQueue1.front)
				{
					player1 = nodePtr->creaturePtr;
					delete player1;
					nodePtr->creaturePtr = nullptr;
					nodePtr = nodePtr->nextQueueNode;
				}
			}

			if (BattleQueue2.isEmpty() == false)
			{
				Queue::QueueNode *nodePtr = BattleQueue2.front->nextQueueNode;
				
				player2 = BattleQueue2.getFront();

				delete player2;

				while (nodePtr != BattleQueue2.front)
				{
					player2 = nodePtr->creaturePtr;

					delete player2;

					nodePtr->creaturePtr = nullptr;

					nodePtr = nodePtr->nextQueueNode;
				}
			}

			Queue::QueueNode * nodePtr = LoserQueue.front->nextQueueNode;
			
			player1 = LoserQueue.getFront();

			delete player1;
			
			LoserQueue.front->creaturePtr = nullptr;

			while (nodePtr != LoserQueue.front)
			{
				player1 = nodePtr->creaturePtr;
				delete player1;
				nodePtr->creaturePtr = nullptr;
				nodePtr = nodePtr->nextQueueNode;
			}

			
			player1 = NULL;
			player2 = NULL;
			*/

			/*for (int i=0; i < cleanUpList.size(); i++)
			{
				delete cleanUpList[i];
				cleanUpList[i] = nullptr;
			}*/
			
			
		}

		if (menu_selection == 2)
		{
			return 0;
		}
	}

}

int battleWinner(Creature *p1, Creature *p2)
{
	for(;;)
	{
		p1->attack();
		p2->defend(p1);
		dead = death_check(p2);
		if (dead == true)
		{
			return 1;
		}

		p2->attack();
		p1->defend(p2);
		dead = death_check(p1);
		if (dead == true)
		{
			return 2;
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
		return false;
}