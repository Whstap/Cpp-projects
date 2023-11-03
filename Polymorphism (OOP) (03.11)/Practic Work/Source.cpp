#include "Employer.h"

int main() {

	int length{};
	Employer** arr{};
	bool isTrue{ true };
	while (isTrue)
	{
		cout << "\tMENU\n";
		cout << "1. - Add Worker\n";
		cout << "2. - Show all Workers\n";
		cout << "3. - Workers' salaries\n";
		cout << "4. - Pay salaries\n";
		cout << "5. - The total amount of payments to Workers\n";
		cout << "6. - Change something\n";
		cout << "9. - clear all Worker\n";
		cout << "0. - Exit\n";
		cout << "-> ";
		int choice{};
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "1. - Worker\n";
				cout << "2. - Manager\n";
				cout << "3. - President\n";
				cout << "0. - Back\n";
				cout << "What type of worker you want add? \n-> ";
				cin >> choice;
				cin.ignore();
				if (choice == 0)
					break;
				{Employer** new_arr{};
				new_arr = new Employer * [length + 1];
				for (int i = 0; i < length; i++)
				{
					new_arr[i] = arr[i];
				}
				system("cls");
				switch (choice)
				{
				case 1:
					new_arr[length] = new Worker();
					break;
				case 2:
					new_arr[length] = new Manager();
					break;
				case 3:
					new_arr[length] = new President();
					break;
				default:
					break;
				}
				new_arr[length]->input();
				delete[] arr;
				arr = new_arr;}
				length++;
				break;
			case 2:
				if (length == 0) {
					cerr << "There are no workers.\n";
					break;
				}
				for (int i = 0; i < length; i++)
					arr[i]->output();
			
				break;
			case 3:
				if (length == 0) {
					cerr << "There are no workers.\n";
					break;
				}
				for (int i = 0; i < length; i++)
				{
					cout << "   " << arr[i]->getPost() << endl;
					cout << arr[i]->Name() << ' ' << arr[i]->Surname() << "\nSalary per month: ";
					cout << arr[i]->getSalary();
					cout << endl;
				}
				break;
			case 4:
				if (length == 0) {
					cerr << "There are no workers.\n";
					break;
				}
				for (int i = 0; i < length; i++) 
					arr[i]->giveSalary();
				break;
			case 5:
				if (length == 0) {
					cerr << "There are no workers.\n";
					break;  
				}
				for (int i = 0; i < length; i++)
				{
					cout << "   " << arr[i]->getPost() << endl;
					cout << arr[i]->Name() << ' ' << arr[i]->Surname() << "\nTotal amount of payments: ";
					cout << arr[i]->Capital();
					cout << endl;
				}
				break;
			case 6:
				cout << "1. - Change name\n";
				cout << "2. - Change surname\n";
				cout << "3. - Change salary\n";
				cout << "4. - Change work hours\n";
				cout << "5. - Change work days\n";
				cout << "6. - Change workers amount (only for manager)\n";
				cout << "7. - Change profit company (only for president)\n";
				cout << "-> ";
				cin >> choice;

				cout << "enter worker id\n-> ";
				{
					short n;
					cin >> n;

					bool isFind = false;
					for (int i = 0; i < length; i++)
					{
						if (arr[i]->Id() == n) {
							isFind = true;
							n = i;
							break;
						}
					}
					if (isFind)
					{
						switch (choice)
						{
						case 1:
							cout << "Enter name: ";
							cin >> arr[n]->Name();
							break;
						case 2:
							cout << "Enter surname: ";
							cin >> arr[n]->Surname();
							break;
						case 3:
							cout << "Enter salary: ";
							cin >> arr[n]->Salary();
							break;
						case 4:
							cout << "Enter hours: ";
							cin >> arr[n]->Hours();
							break;
						case 5:
							cout << "Enter days: ";
							cin >> arr[n]->Days();
							break;
						case 6:
							cout << "Enter workers: ";
							{
							int temp{};
							cin >> temp;
							arr[n]->ClassOriginalSetter(temp); 
							}
							break;
						case 7:
						
							cout << "Enter profit: ";
							{
							int temp{};
							cin >> temp;
							arr[n]->ClassOriginalSetter(temp);
							}
							break;
						default:
							break;
						}
					}
					else
						cerr << "No worker found with the same ID.\n";
					
				}
				break;
			case 9:
				delete[] arr;
				arr = {};
				length = 0;
				cout << "Workers Laid Off.\n";
				break;
	
			case 0:
				isTrue = false;
				break;
		default:
			cerr << "Wrong choice.\n";
			break;
		}
		
		system("pause");
		system("cls");

	}

	
	return 0;
}