/*
	Johanna Nguyen
	Gilbert Paderogo
	Richard Phan

	CPSC 323 Compilers and Languages
	Syntax Analyzer
	November 5, 2019
*/

#ifndef assembly_hpp
#define assembly_hpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <tuple>
#include <string>
#include <vector>
using namespace std;


vector<tuple<string, int, string>> genSymbols(vector<tuple<string, string>> list);

bool checkDuplicate(vector<tuple<string, string>> table, string id);

void genInstruction(string operation, string id);

string getAddress(vector<tuple<string, int, string>> table, string token);

#endif