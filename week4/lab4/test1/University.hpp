/*********************************************************************
** Program name: OSU Information System (University.hpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: Header file for University class.
*********************************************************************/#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <vector>
#include "Instructor.hpp"
#include "Student.hpp"
#include "Buildings.hpp"


class University
{
private:
	std::string university_name;
	std::vector<Instructor>instructor_list;
	std::vector<Student>student_list;
	std::vector<Buildings>building_list;
	std::vector<std::string>choose_person_to_work = {"Choose a Student", "Choose an Instructor"};
	std::vector<std::string>student_list_to_pass;
	std::vector<std::string>instructor_list_to_pass;
	int total_students;
	int total_instructors;
	int total_buildings;
	int selection;
	int hours_worked;
public:
	University();
	void print_buildings();
	void print_people();
	void create_sample_students();
	void create_sample_instructors();
	void create_sample_buildings();
	void choose_a_person();
	void choose_a_student();
	void choose_an_instructor();
};

#endif
