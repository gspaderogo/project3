/*
	Johanna Nguyen
	Gilbert Paderogo
	Richard Phan

	CPSC 323 Compilers and Languages
	Syntax Analyzer
	November 5, 2019
*/

#ifndef Instruction_hpp
#define Instruction_hpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

struct Instruction {
	int address;
	string operation;
	string operand;
};

#endif;