/*********************************************************************
** Program name: main.hpp
** Author: Jon Raleigh
** Date: 5/14/17
** Description: header file for main
*********************************************************************/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP


#include<vector>
#include"inputValidator.hpp"
#include"NumberList.hpp"
#include "menu.hpp"

std::vector<std::string>menu_options;
int selection;
int input;
InputValidator linkedListInput;
Menu LinkedListMenu;
NumberList Node;

#endif
