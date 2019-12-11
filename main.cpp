/*
	Johanna Nguyen
	Gilbert Paderogo
	Richard Phan

	CPSC 323 Compilers and Languages
	Lexical Analyzer
	September 19, 2019
*/

#include "lexicalAnalyzer.h"
#include "syntaxAnalyzer.h"

bool	checkDuplicate(vector<tuple<string, string>> table, string id);

int main()
{
	ifstream inFile;
	string userInput;
	ofstream outFile("output.txt");

	cout << "------------------------------------------------------------\n"
		<< "SYNTAX ANALYZER by:\n"
		<< "Johanna Nguyen, Gilbert Paderogo, Richard Phan\n"
		<< "------------------------------------------------------------\n"
		<< "Enter a text file location and name.\n"
		<< "Remember to use double slashes!\n\n"
		<< "Example: C:\\\\Users\\\\Desktop\\\\input.txt\n"
		<< "------------------------------------------------------------\n"
		<< "Your file name: ";

	cin >> userInput;				//Saves file destination as string

	inFile.open(userInput);			//Opens file by passing string									

	if (inFile.is_open())
	{
		//outFile << left << setw(40) << "TOKEN" << "LEXEME" << endl;
		vector<tuple<string, string>> list;

		while (!inFile.eof())
		{
			//lexer(inFile, outFile);

			tuple<string, string> token = backgroundLex(inFile); // puts data into vector
			list.push_back(token);
		}

		analyzer(list);

		cout << "------------------------------------------------------------\n"
			<< "File has successfully been processed.\n"
			<< "Your results have been printed to \"output.txt.\"\n\n";

		//--------------------------------- SYMBOL TABLE -----------------------------//
		vector<tuple<string, string>> symbolTable;
		cout << "TEST\n";
		cout << "MEMORY\tIDENTIFIER\tTYPE\n";
		int i = 0;
		string currentKey; // to keep track of the current key word for mulitple variable declarations
		//Adds all cases of "IDENTIFIER" to a symbol table vector
		string identifier = get<1>(list.at(i));
		while (i < list.size())
		{
			if (get<0>(list.at(i)) == "KEYWORD")
			{
				currentKey = get<1>(list.at(i)); 
			}

			if (get<0>(list.at(i)) == "IDENTIFIER" && (checkDuplicate(symbolTable, get<1>(list.at(i))) == false ))
			{
				identifier = get<1>(list.at(i));
				//symbolTable.push_back(make_tuple(identifier, "integer"));
				symbolTable.push_back(make_tuple(identifier, currentKey));
			}
			++i;
		}
		int j = 0;
		int k = 1;
		//Removes duplicates by comparing each element
		/*while (j < symbolTable.size())
		{
			while (k < symbolTable.size())
			{
				if (get<0>(symbolTable.at(j)) == get<0>(symbolTable.at(k)))
				//if (symbolTable[j] == symbolTable[k])
				{
					symbolTable.erase(symbolTable.begin() + k);
				}
				++k;
			}
			++j;
			k = j + 1;
		}*/
		//Prints the symbol table 
		for (int i = 0; i < symbolTable.size(); ++i)
		{
			cout << i + 5000 
				<< "\t" 
				<< get<0>(symbolTable.at(i)) 
				<< "\t\t" 
				<< get<1>(symbolTable.at(i)) << "\n";
		}
	}
	else
		cerr << "------------------------------------------------------------\n"
		<< "\nError - file could not be opened.\n\n";

	inFile.close();

	system("Pause");
	return 0;
}

bool	checkDuplicate(vector<tuple<string, string>> table, string id)
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
