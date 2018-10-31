/*********************************************************************
** Program name: algotest (lab10)
** Author: Jonathan Raleigh
** Date: 6/11/17
** Description: header file for R Fibonacci sequence calculation
*********************************************************************/
/*
* FibonacciR.h
*
*  Created on: Sep 10, 2010
*      Author: julian
*/

#ifndef FIBONACCIR_HPP
#define FIBONACCIR_HPP

class FibonacciR {
public:
     FibonacciR(const int &n);
     virtual ~FibonacciR();
     void PrintFibonacci();
private:
     FibonacciR();
     int Fibonacci(const int &n);
     const int *n_;

};

#endif /* FIBONACCIR_HPP */