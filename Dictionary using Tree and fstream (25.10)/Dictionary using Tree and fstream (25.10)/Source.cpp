#include "Tree.h"
#include <fstream>


int main() {

	ifstream fin;

	fin.open("text.txt");
	if (!fin.is_open()) {
		cerr << "Error opening file" << endl;
		return 1;
	}
	// key = eng, value = french
	Tree<string, string> tree;

	// read from file like this: key : value (endl) another_key : another_value
	string key;
	string value;
	while (!fin.eof())
	{
		getline(fin, key, '|');
		getline(fin, value, '\n');
		if (key == "")
			break;
		tree.add(key, value);
	}
	fin.close();


	bool isTrue = true;
	while (isTrue)
	{
		cout << "1. - show tree" << endl;
		cout << "2. - add new word" << endl;
		cout << "3. - exit" << endl;
		int command;
		cin >> command;
		switch (command)
		{
		case 1:
			system("cls");
			tree.show(cout, " : ", "\n");
			break;
		case 2:
			cin.ignore();
			cout << "Enter new word:" << endl;
			getline(cin, key);
			cout << "Enter translation:" << endl;
			getline(cin, value);
			tree.add(key, value);
			break;
		case 3:
			isTrue = false;
			break;
		default:
			cerr << "Wrong command" << endl;
			break;
		}
		system("pause");
		system("cls");
	}

	ofstream fout;
	fout.open("text.txt");
	if (!fout.is_open()) {
		cerr << "Error opening file" << endl;
		return 1;
	}
	// write to file using show method
	tree.show(fout, "|", "\n");
	fout.close();

	return 0;
}