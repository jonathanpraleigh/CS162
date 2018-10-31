/*********************************************************************
** Program name: OSU Information System (University.cpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: University class. Holds Student, Instructor, and Building
** objects. Contains most of the functions for the program.
*********************************************************************/#include "University.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "Buildings.hpp"
#include "menu.hpp"
#include <string>
#include <vector>
#include <iostream>
University::University()
{
	university_name = "Oregon State University";
}

void University::print_buildings()
{
	total_buildings = building_list.size();

	std::cout << "Buildings of " 
			<< university_name 
			<< "\n--------------------\n";

	for (int i = 0; i<total_buildings; i++)
	{
		std::cout
			<< building_list[i].get_building_name()
			<< " // "				
			<< building_list[i].get_building_address()
			<< " // "
			<< building_list[i].get_building_size()
			<< " Sq. Ft.\n";
		}
	
}

void University::print_people()
{
	total_students = student_list.size();
	total_instructors = instructor_list.size();

	std::cout << "Students and Instructors of " 
			<< university_name 
			<< "\n--------------------\nStudents:\n";
			
	for (int i = 0; i<total_students; i++)
	{
		std::cout
			<< student_list[i].get_name()
			<< " // "
			<< student_list[i].get_age()
			<< " years old //  "
			<< student_list[i].get_gpa()
			<< " GPA\n";
	}

	std::cout << "\nInstructors:\n";
	
	for (int i = 0; i<total_instructors; i++)
	{
		std::cout
			<< instructor_list[i].get_name()
			<< " "
			<< instructor_list[i].get_age()
			<< " "
			<< instructor_list[i].get_instructor_rating()
			<< "\n";
	}

}

void University::create_sample_students()
{
	Student Jon("Jon Raleigh", 36);

	student_list.push_back(Jon);
}

void University::create_sample_instructors()
{
	Instructor Chad("Chad Ray", 78);

	instructor_list.push_back(Chad);
}

void University::create_sample_buildings()
{
	
	Buildings Milne("Milne Computer Center", "1800 SW Campus Way", 23441);
	Buildings Adams("Adams Hall", "606 SW 15th St", 11168);

	building_list.push_back(Milne);
	building_list.push_back(Adams);


}

void University::choose_a_person()
{
	selection = menu(choose_person_to_work);

	if (selection == 1)
	{
		this->choose_a_student();
	}
	else if (selection == 2)
	{
		this->choose_an_instructor();
	}
}

void University::choose_a_student()
{
	total_students = student_list.size();

	for(int i = 0; i< total_students; i++)
	{
		std::string passer;
		passer = student_list[i].get_name();
		student_list_to_pass.push_back(passer);
	}

	selection = menu(student_list_to_pass) - 1;

	std::cout << "\nHow many hours has the student already worked?\n";
	std::cin >> hours_worked;

	student_list[selection].do_work(hours_worked);
}

void University::choose_an_instructor()
{
	total_instructors = instructor_list.size();

	for (int i = 0; i< total_instructors; i++)
	{
		std::string passer;
		passer = instructor_list[i].get_name();
		instructor_list_to_pass.push_back(passer);
	}

	selection = menu(instructor_list_to_pass) - 1;

	std::cout << "\nHow many hours has the instructor already worked?\n";
	std::cin >> hours_worked;

	instructor_list[selection].do_work(hours_worked);
}