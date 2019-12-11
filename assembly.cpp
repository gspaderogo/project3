#include "assembly.h"
#include "Instruction.h"

vector<Instruction> instrTable;
vector<tuple<string, int, string>> symbolTable;
tuple<string, int, string> item;

int memLoc = 5000;
int instrAddress = 1;
int i = 0;

string currentKey;
string identifier;

bool repeat = false;

vector<tuple<string, int, string>> genSymbols(vector<tuple<string, string>> list) 
{
	while(i < list.size())
	{
		if (get<0>(list.at(i)) == "KEYWORD")
		{
			currentKey = get<1>(list.at(i));
		}

		if (get<0>(list.at(i)) == "IDENTIFIER" && (checkDuplicate(symbolTable, get<1>(list.at(i))) == false))
		{
			identifier = get<1>(list.at(i));
			symbolTable.push_back(make_tuple(identifier, memLoc, currentKey));
			++memLoc;
		}
		++i;
	}

	cout << endl << "----- SYMBOL TABLE -----" << endl;
	cout << "Identifier\t" << "Memory Location\t\t" << "Type" << endl;
	for (auto i : symbolTable) {
		cout << get<0>(i) << "\t\t"
			<< get<1>(i) << "\t\t\t"
			<< get<2>(i) << endl;
	}

	return symbolTable;
}

bool checkDuplicate(vector<tuple<string, int, string>> table, string id)
{
	int i = 0;
	while (i < table.size())
	{
		if (get<0>(table.at(i)) == id)
		{
			return true;
		}
		++i;
	}
	return false;
}

void genInstruction(string operation, string operand) {
	Instruction instr;

	instr.address = instrAddress;
	instr.operation = operation;
	instr.operand = operand;

	instrTable.push_back(instr);
	instrAddress++;
}

string getAddress(vector<tuple<string, int, string>> table, string token) {
	for (auto i : table) {
		if (get<0>(i) == token) {
			return to_string(get<1>(i));
		}
	}
}