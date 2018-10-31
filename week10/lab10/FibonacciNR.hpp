/*********************************************************************
** Program name: algotest (lab10)
** Author: Jonathan Raleigh
** Date: 6/11/17
** Description: header file for NR Fibonacci sequence calculation
*********************************************************************/

/*
* FibonacciNR.h
*
*  Created on: Sep 11, 2010
*      Author: julian
*/

#ifndef FIBONACCINR_HPP
#define FIBONACCINR_HPP

class FibonacciNR {
public:
	FibonacciNR(const int &n);
	virtual ~FibonacciNR();
	void PrintFibonacci();
private:
	FibonacciNR();
	int Fibonacci(const int &n);
	const int* n_;
	
};

#endif /* FIBONACCINR_HPP */