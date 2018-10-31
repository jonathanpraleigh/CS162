/*********************************************************************
** Program name: OSU Information System (menu.hpp)
** Author: Jon Raleigh
** Date: 4/30/17
** Description: header file for menu function file.
*********************************************************************/

#ifndef RECURSIVE_HPP
#define RECURSIVE_HPP

#include <vector>
#include <string>
#include <iostream>
#include "recursive.hpp"

int menu_passer;
int program_choice;
int array_size;
int array_input;
int sum;
int rows_to_be_passed;
int total_rows;
int rows;
int * i_cant_wait_to_ditch_arrays_for_vectors;
std::vector<std::string>recursion_menu = { "String Reverser", "Array Sum", "Triangular Number Calculator", "Exit" };
void string_reverser(std::string);
void array_sum(int[], int);
void triangle_calculator(int);
std::string string_to_be_reversed;

#endif
