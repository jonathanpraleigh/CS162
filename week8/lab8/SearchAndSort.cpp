/********************************************************************************************
** Program name: SearchAndSort
** Author: Jon Raleigh
** Date: 5/28/17
** Description: Uses XXXX search method, XXXX sort method, and Binary Search to locate
**				values within four text files. 
*******************************************************************************************/

#include "SearchAndSort.hpp"
#include "Menu.hpp"
#include "InputValidator.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	Menu SAndSMenu;
	InputValidator SAndSInputValidator;
	std::vector<std::string>menuOptions = { "Use Linear Search", "Use Bubble Sort", "Use Binary Search", "Exit" };

	for (;;)
	{
		selection = SAndSMenu.menuDisplay(menuOptions);

		if (selection == 1) // Linear search
		{
			std::cout << "\nPlease enter a search value\n";
			searchValue = SAndSInputValidator.testInteger(0, 9, true, true, false);
			
			std::cout << "\nSearching early.txt\n";
			
			std::ifstream earlyFile ("early.txt", std::ifstream::in);
			
			if (earlyFile)
			{
				double passer;
				while ( earlyFile >> passer)
				{
					earlyV.push_back(passer);
				}
			}			

			earlyFound = linearSearch(earlyV, earlyV.size(), searchValue);

			earlyFile.close();

			if (earlyFound == 1)
			{
				std::cout << "\nValue found.\n";
			}
			else
			{
				std::cout << "\nValue not found.\n";
			}

			std::cout << "\nSearching middle.txt\n";

			std::ifstream middleFile ("middle.txt", std::ifstream::in);

			if (middleFile)
			{
				double passer;
				while ( middleFile >> passer)
				{
					middleV.push_back(passer);
				}
			}
						
			middleFound = linearSearch(middleV, middleV.size(), searchValue);

			middleFile.close();

			if (middleFound == 1)
			{
				std::cout << "\nValue found.\n";
			}
			else
			{
				std::cout << "\nValue not found.\n";
			}

			std::cout << "\nSearching late.txt\n";

			
			std::ifstream lateFile ("late.txt", std::ifstream::in);

			if (lateFile)
			{
				double passer;
				while (lateFile >> passer)
				{
					lateV.push_back(passer);
				}
			}
				
			lateFound = linearSearch(lateV, lateV.size(), searchValue);

			lateFile.close();

			if (lateFound == 1)
			{
				std::cout << "\nValue found.\n";
			}
			else
			{
				std::cout << "\nValue not found.\n";
			}

			std::cout << "\nSearching none.txt\n";

			std::ifstream noneFile ("none.txt", std::ifstream::in);

			if (noneFile)
			{
				double passer;	
				while (noneFile >> passer)
				{
					noneV.push_back(passer);
				}
			}	


			noneFound = linearSearch(noneV, noneV.size(), searchValue);

			noneFile.close();

			if (noneFound == 1)
			{
				std::cout << "\nValue found.\n";
			}
			else
			{
				std::cout << "\nValue not found.\n";
			}

		}

		if (selection == 2) // Bubble Sort
		{
			std::cout << "\nSorting the files.\n";
			
			std::ifstream earlyFile("early.txt", std::ifstream::in);

			if (earlyFile)
			{
				double passer;
				while (earlyFile >> passer)
				{
					earlyS.push_back(passer);
				}
			}

			earlyFile.close();

			earlyS = bubbleSort(earlyS, earlyS.size());

			std::cout << "\nearly.txt sorted. Enter the output name.\n";
			
			std::cin.ignore();
			getline(std::cin, earlySorted);

			earlyBS.open(earlySorted);

			for (int i=0; i < earlyS.size(); i++)
			{
				earlyBS << earlyS[i];
			}

			earlyBS.close();

			std::cout << "\nFinished.\n";


			std::ifstream middleFile("middle.txt", std::ifstream::in);

			if (middleFile)
			{
				double passer;
				while (middleFile >> passer)
				{
					middleS.push_back(passer);
				}
			}

			middleFile.close();

			middleS = bubbleSort(middleS, middleS.size());

			std::cout << "\nmiddle.txt sorted. Enter the output name.\n";

			getline(std::cin, middleSorted);

			middleBS.open(middleSorted);

			for (int i = 0; i < middleS.size(); i++)
			{
				middleBS << middleS[i];
			}

			middleBS.close();

			std::cout << "\nFinished.\n";

			std::ifstream lateFile("middle.txt", std::ifstream::in);

			if (lateFile)
			{
				double passer;
				while (lateFile >> passer)
				{
					lateS.push_back(passer);
				}
			}

			lateFile.close();

			lateS = bubbleSort(lateS, lateS.size());

			std::cout << "\nlate.txt sorted. Enter the output name.\n";

			getline(std::cin, lateSorted);

			lateBS.open(lateSorted);

			for (int i = 0; i < lateS.size(); i++)
			{
				lateBS << lateS[i];
			}

			lateBS.close();

			std::cout << "\nFinished.\n";

			std::ifstream noneFile("none.txt", std::ifstream::in);

			if (noneFile)
			{
				double passer;
				while (noneFile >> passer)
				{
					noneS.push_back(passer);
				}
			}
			noneFile.close();

			noneS = bubbleSort(noneS, noneS.size());

			std::cout << "\nnone.txt sorted. Enter the output name.\n";

			getline(std::cin, noneSorted);

			noneBS.open(noneSorted);

			for (int i = 0; i < noneS.size(); i++)
			{
				noneBS << noneS[i];
			}

			noneBS.close();

			std::cout << "\nFinished.\n";

		}

		if (selection == 3) //Binary Search
		{
			std::cout << "\nPlease enter a value to locate in binary.txt.\n";
			
			binarySearchValue = SAndSInputValidator.testInteger(0,9,true,true,false);

			std::cout << "\nSearching binary.txt.\n";

			std::ifstream binaryFile("binary.txt", std::ifstream::in);

			if (binaryFile)
			{
				double passer;
				while (binaryFile >> passer)
				{
					binaryV.push_back(passer);
				}
			}

			binaryLocation = binarySearch(binaryV, binaryV.size(), binarySearchValue);

			binaryFile.close();

			{
				std::cout << "\nNumber found in location " << binaryLocation << ".\n";
			}
		}

		if (selection == 4)
		{
			return 0;
		}
	}
}


//1 Search for Target Value
/*File 1 target value “0” not found;
File 2 target value “0” found;
File 3 target value “0” found;
Cite which one you used (page # or slide #). */


// Citation: Searching Slide 6.
int linearSearch(std::vector<int>a, int size, int v)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] == v) 
		{
			return 1;
		}
	} 
	return -1;
}



//2 Sort a set of values
/*The book or the lecture has several examples of the code for sorting algorithms. 
 *Implement one of them in a program. Cite which one you used (page # or slide #). 
 *After you read the input file and sort it, ask the user for output file name, 
 *and then output the sorted values into the output file. Sort all input files and 
 *compare the results. Does your sorting algorithm work on all 3 input files 
 *(are the output file's number all the same)? You can just compare the output 
 *files manually to see that the sorting algorithm handles each input correctly.*/


//Citation: Text Book, pg 615
//
std::vector<int> bubbleSort(std::vector<int> a, int size)
{
	int temp;
	bool madeAswap;

	do
	{
		madeAswap = false;
		for (int count = 0; count < (size -1); count++)
		{
			if (a[count] > a[count +1])
			{
				temp = a[count];
				a[count] = a[count +1];
				a[count +1] = temp;
				madeAswap = true;
			}
		}
	}while (madeAswap);
	return a;
	
}

//3 Binary Search
/*Find an algorithm for binary search. Implement it in a program that searches 
 *for the target value in your data file. Remember that you cannot use any of
 * the original files since they are not sorted. Create the data files that 
 * suitable for this task, or use the output files from task 3. 
 * Cite the reference for the algorithm you use in the comment.*/
//Competive Programming Handbook p32 https://cses.fi/book.pdf 

int binarySearch (std::vector<int>t, int n, int x)
{
	int a = 0, b = n-1;
	while (a <= b)
	{
		int k = (a + b) / 2;
		if (t[k] == x)
		{
			return x;
		}
		if (t[k] > x) b = k - 1;
		else a = k + 1;
	}
}

/*For the searching, you will not hard code the function to search for "0".  
 *Instead, you will ask the user which number to search for. 
You don’t need to provide a testing table or something similar to show your
testing results, but provide a method that allows TAs to check the data
by either printing it to the screen or writing into a file.
*/
