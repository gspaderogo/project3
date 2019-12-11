#include "assembly.h"
#include "Instruction.h"

int memLoc = 5000;
int instrAddress = 1;
vector<tuple<string, int, string>> table;
vector<Instruction> instrTable;

vector<tuple<string, int, string>> genSymbols(vector<tuple<string, string>> list) 
{
	for (auto lexeme : list) {
		if (get<0>(lexeme) == "IDENTIFIER") {

			bool repeat = false;
			tuple<string, int, string> item = make_tuple(get<1>(lexeme), memLoc, "INTEGER");

			for (auto i : table) {
				if (get<0>(i) == get<0>(item)) {
					repeat = true;
				}
			}

			if (!repeat) {
				table.push_back(item);
				memLoc++;
			}
		}
	}

	cout << endl << "----- SYMBOL TABLE -----" << endl;
	cout << "Identifier\t" << "Memory Location\t\t" << "Type" << endl;
	for (auto i : table) {
		cout << get<0>(i) << "\t\t"
			<< get<1>(i) << "\t\t\t"
			<< get<2>(i) << endl;
	}

	return table;
}

bool checkDuplicate(vector<tuple<string, string>> table, string id)
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