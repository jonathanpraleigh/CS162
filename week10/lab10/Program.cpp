/*********************************************************************
** Program name: algotest (lab10)
** Author: Jonathan Raleigh
** Date: 6/11/17
** Description: Implementation of Fibnoacci sequence calculators.
**				Added my own clock() to test time. 
*				https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*				as suggested by the assignment.
*********************************************************************/

/*
* Program.cpp
*
*  OS: Fedora 13
*  Language: Native C++
*  Compiler: GNU g++
*  Created on: Sep 11, 2010
*      Author: julian
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "FibonacciR.hpp"
#include "FibonacciNR.hpp"

using namespace std;

void Usage() 
	{
		cout << "Correct Usage:" << endl;
		cout << "./Fibonacci [n]" << endl;
	}

int main(int argc, char** args) 
	{
	clock_t start;
	double duration;
     try {
         const char* input;
         if (args[1] != 0)
         {
             cout << "1st passed arguement: '" << args[1] << "'" << endl;
             input = args[1];
         }
		 int n = 40;
         cout << "Finding '" << n << "'th " << "fibonacci number...." << endl;
         cout << "Calling Recursive Fibonacci implementation" << endl;
		 start = clock();
         FibonacciR fr(n);
         fr.PrintFibonacci();
		 duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		 cout << "It took " << duration << " clicks\n."; 
         cout << "Calling Non-Recursive Fibonacci implementation" << endl;
		 start = clock();
         FibonacciNR fnr(n);
         fnr.PrintFibonacci();
		 duration = (clock() - start)/(double)CLOCKS_PER_SEC;
		 cout << "It took " << duration << " clicks\n.";
         cout << "Done!!!!" << endl;
         return 0;

	}
     catch (...)
     {
         cout << "Oops an error occured! Please check usage" << endl;
         Usage();
         return 1;
     }

}
