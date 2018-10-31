/********************************************************************************************
** Program name: Lab 9
** Author: Jon Raleigh
** Date: 6/04/17
** Description: header for implementation and functions
*******************************************************************************************/

#ifndef LAB9_HPP
#define LAB9_HPP

#include <vector>
#include "Menu.hpp"
#include "InputValidator.hpp"
#include <stack>
#include <queue>


int selection;
int rounds;
int addChance;
int removeChance;
int roll; 
int rollTemp;
int roundCounter;
int currentSize;
int size;
int iterations; 

double avgLength;
double prevAvgLength;

std::string toPalindrome;

std::queue<int>intQueue;
std::queue<int>disposableQueue;

std::stack<char>palindrome;

std::vector<std::string>mainMenuOptions = { "Queue", "Stack", "Exit" };
Menu MainMenu;
InputValidator Inputter;
void queueDemonstration();
void stackDemonstration();
void displayQueue(std::queue<int>);
int roller();

#endif