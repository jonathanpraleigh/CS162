/********************************************************************************************
** Program name: Final Project
** Author: Jon Raleigh
** Date: 6/13/17
** Description: Vermin game implementation file
*******************************************************************************************/

#include "Vermin.hpp"
#include "DiningRoom.hpp"
#include "MasterBedroom.hpp"
#include "MasterBathroom.hpp"
#include "UpstairsBathroom.hpp"
#include "FamilyRoom.hpp"
#include "Room.hpp"
#include "DownstairsBathroom.hpp"
#include "DownstairsHallway.hpp"
#include "Kitchen.hpp"
#include "Study.hpp"
#include "Vestibule.hpp"
#include "Downstairs.hpp"
#include "Ledge.hpp"
#include "NorthBedroom.hpp"
#include "SouthBedroom.hpp"
#include "Upstairs.hpp"
#include "UpstairsHallway.hpp"
#include <iostream>

int main()
{
	DiningRoom DR;
	Downstairs DS;
	DownstairsBathroom DSB;
	DownstairsHallway DSH;
	FamilyRoom FR;
	Kitchen K;
	Ledge L;
	MasterBathroom MBa;
	MasterBedroom MBe;
	NorthBedroom NB;
	SouthBedroom SB;
	Study S;
	Upstairs U;
	UpstairsBathroom UB;
	UpstairsHallway UH;
	Vestibule V;

	DiningRoom * ptrDR = &DR;
	Downstairs * ptrDS = &DS;
	DownstairsBathroom * ptrDSB = &DSB;
	DownstairsHallway * ptrDSH = &DSH;
	FamilyRoom * ptrFR = &FR;
	Kitchen * ptrK = &K;
	Ledge * ptrL = &L;
	MasterBathroom * ptrMBa = &MBa;
	MasterBedroom * ptrMBe = &MBe;
	NorthBedroom * ptrNB = &NB;
	SouthBedroom * ptrSB = &SB;
	Study * ptrS = &S;
	Upstairs * ptrU = &U;
	UpstairsBathroom * ptrUB = &UB;
	UpstairsHallway * ptrUH = &UH;
	Vestibule * ptrV = &V;
	
	Room* currentRoom = &MBe;

	DR.setDirections(nullptr, nullptr, ptrK, ptrDS, nullptr, nullptr);
	DS.setDirections(nullptr, ptrDR, ptrV, ptrFR, ptrU, nullptr);
	DSB.setDirections(ptrDSH, nullptr, nullptr, nullptr, nullptr, nullptr);
	DSH.setDirections(nullptr, ptrV, ptrDSB, ptrS, nullptr, nullptr);
	FR.setDirections(nullptr, ptrDS, ptrS, nullptr, nullptr, nullptr);
	K.setDirections(ptrDR, nullptr, nullptr, ptrV, nullptr, nullptr);
	L.setDirections(ptrNB, nullptr, ptrSB, nullptr, nullptr, nullptr);
	MBa.setDirections(ptrMBe, nullptr, nullptr, nullptr, nullptr, nullptr);
	MBe.setDirections(nullptr, ptrU, ptrMBa, nullptr, nullptr, nullptr);
	NB.setDirections(nullptr, ptrL, nullptr, ptrU, nullptr, nullptr);
	SB.setDirections(nullptr, ptrL, nullptr, ptrUH, nullptr, nullptr);
	S.setDirections(ptrFR, ptrDSH, nullptr, nullptr, nullptr, nullptr);
	U.setDirections(nullptr, ptrNB, ptrUH, ptrMBe, nullptr, ptrDS);
	UB.setDirections(ptrUH, nullptr, nullptr, nullptr, nullptr, nullptr);
	UH.setDirections(ptrU, ptrSB, ptrUB, nullptr, nullptr, nullptr);
	V.setDirections(ptrDS, ptrK, nullptr, ptrDSH, nullptr, nullptr);

	openingGraphics();
	std::cout << "To play, GO explore rooms, EXAMINE rooms to find objects, and USE items to solve puzzles.\n";

	finished = false;

	while (finished != true)
	{
		choice = GameMenu.menuDisplay(openingMenuOptions);
		if (choice == 1)
		{	
			timer = 35;
			while (finished != true)
			{
				timer--;
				currentRoom->displayRoom();
				currentRoom->roomDescription();
				choice = PlayMenu.menuDisplay(playMenuOptions);
				if (choice == 1)
				{
					currentRoom = currentRoom->go();
				}
				if (choice == 2)
				{
					currentRoom->examine(ptrInventory);
				}
				if (choice == 3)
				{
					currentRoom->use(ptrInventory);
				}
				if (choice == 4)
				{
					finished = true;
				}
				if (timer <= 0)
				{
					std::cout << "A horrible rumble sounds from outside. You peer through the nearest window.\n"
						<< "Swarms of ants are closing in on the house.\n"
						<< "You look desperately for some place to hide, but it's of no use.\n"
						<< "Ants tear through the door and rush at you.\n"
						<< "Unfortunately, you are awake, as they carry you back to their colony.\n"
						<< "GAME OVER.";
					finished = true;
				}
			}
		}
		return 0;
	} 
	return 0;
}

void openingGraphics()
{
	std::cout << "\n"
		<< " __   __  _______  ______    __   __  ___   __    _ \n"
		<< "|  | |  ||       ||    _ |  |  |_|  ||   | |  |  | |\n"
		<< "|  | |  ||    ___||   | ||  |       ||   | |   |_| |\n"
		<< "|  |_|  ||   |___ |   |_||_ |       ||   | |       |\n"
		<< "|       ||    ___||    __  ||       ||   | |  _    |\n"
		<< " |     | |   |___ |   |  | || ||_|| ||   | | | |   |\n"
		<< "  |___|  |_______||___|  |_||_|   |_||___| |_|  |__|\n"
		<< "\n";
}