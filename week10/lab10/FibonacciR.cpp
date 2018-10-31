/*********************************************************************
** Program name: algotest (lab10)
** Author: Jonathan Raleigh
** Date: 6/11/17
** Description: function for the recursive calculation of the 
**				Fibonacci sequence. Used code from
*				https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
*				as suggested by the assignment.
*********************************************************************/

/*
* FibonacciClass1.cpp
*
*  Created on: Sep 10, 2010
*      Author: julian
*/
#include "FibonacciR.hpp"
#include <iostream>

FibonacciR::FibonacciR() 
	{

	}

FibonacciR::FibonacciR(const int &n) :n_(&n) 
	{

	}

FibonacciR::~FibonacciR() 
	{

	}

int FibonacciR::Fibonacci(const int &n) 
	{
  		if (n == 0)
  			return 0;
  		else if (n == 1)
  			return 1;
  		return Fibonacci(n - 1) + Fibonacci(n - 2);

	}
void FibonacciR::PrintFibonacci() 
	{
  		int FibonaciNum = Fibonacci(*n_);
  		std::cout << *n_ << "th fibonaci number: " << FibonaciNum << std::endl;

	}