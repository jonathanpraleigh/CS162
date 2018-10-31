/*********************************************************************
** Program name: OSU Information System (Main.cpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: Implementation file. 
*********************************************************************/
#include "Main.hpp"
#include "menu.hpp"
#include "University.hpp"

int main()
{
	University Oregon_State;
	
	Oregon_State.create_sample_students();
	Oregon_State.create_sample_instructors();
	Oregon_State.create_sample_buildings();
	
	for ( ; ; )
	{

		selection = menu(options);

		if (selection == 1)
		{
			Oregon_State.print_buildings();
		}
		else if (selection == 2)
		{
			Oregon_State.print_people();
		}
		else if (selection == 3)
		{
			Oregon_State.choose_a_person();
		}
		else if (selection == 4)
		{
			return 0;
		}
	}	
}
