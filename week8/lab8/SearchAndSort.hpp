/********************************************************************************************
** Program name: SearchAndSort
** Author: Jon Raleigh
** Date: 5/28/17
** Description: Uses XXXX search method, XXXX sort method, and Binary Search to locate
**				values within four text files.
*******************************************************************************************/

#ifndef SEARCHANDSORT_HPP
#define SEARCHANDSORT_HPP

#include <vector>
#include <fstream>


int temp;
int selection;
int searchValue;
int earlyFound;
int middleFound;
int lateFound;
int noneFound;
int binarySearchValue;
int binaryLocation;
int passer;
std::vector<int>earlyV;
std::vector<int>middleV;
std::vector<int>lateV;
std::vector<int>noneV;
std::vector<int>earlyS;
std::vector<int>middleS;
std::vector<int>lateS;
std::vector<int>noneS;
std::vector<int>binaryV;
std::string earlySorted;
std::string middleSorted;
std::string lateSorted;
std::string noneSorted;
std::ifstream earlyFile;
std::ifstream middleFile;
std::ifstream lateFile;
std::ifstream noneFile;
std::ifstream earlySort;
std::ifstream middleSort;
std::ifstream lateSort;
std::ifstream noneSort;
std::ifstream binaryFile;
std::ofstream earlyBS;
std::ofstream middleBS;
std::ofstream lateBS;
std::ofstream noneBS;

std::vector<int> bubbleSort(std::vector<int>, int);
int linearSearch(std::vector<int>, int, int);
int binarySearch(std::vector<int>, int, int);

#endif
