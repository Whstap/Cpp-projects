#pragma once

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employer
{
	string name{};
	string surname{};

	short id{}; // 4 digits
	int salary{};
	double capital{};
	int hours{};
	int days{};

public:
	Employer() = default;
	Employer(const string& _name, const string& _surname, const short _id, const int _salary, const int _hours, const int _days)
		: name{ _name }, surname{ _surname }, id{ _id }, salary{ _salary }, hours{ _hours }, days{_days} {};

	//getters/setters

	const string& Name() const { return name; }
	string& Name() { return name; }

	const string& Surname() const { return surname; }
	string& Surname() { return surname; }

	const short& Id() const { return id; }
	short& Id()  { return id; }

	const int& Salary() const { return salary; }
	int& Salary() { return salary; }

	const int& Hours() const { return hours; }
	int& Hours() { return hours; }

	const int& Days() const { return days; }
	int& Days() { return days; }
	
	const double& Capital () const { return capital; }

	//methods

	void giveSalary()
	{
		capital += getSalary();
	}
	

	virtual string getPost() const = 0;

	virtual double getSalary() const = 0;

	virtual void ClassOriginalSetter(const int n) = 0; //для зміни в класі Manager і President, іншого способу не придумав

	virtual ostream& output(ostream& out = cout) const
	{
		out << "Name:    "  << name << endl;
		out << "Surname: "  << surname << endl;
		out << "ID:      " << id << endl;
		out << "Salary:  " << salary << endl;
		out << "Hours:   "  << hours << endl;
		out << "Days:    "   << days << endl;
		return out;
	}

	virtual istream& input(istream& in = cin)
	{
		cout << "Name: ";
		in >> name;
		cout << "Surname: ";
		in >> surname;
		cout << "ID: ";
		in >> id;
		cout << "Salary: ";
		in >> salary;
		cout << "Hours: ";
		in >> hours;
		while (hours >= 23) {
			system("cls");
			cout << "Wrong input.\n";
			cout << "Hours: ";
			in >> hours;
		}
		if (hours > 12)
			cout << "\nIt seems to me that your employee is working too much, please reduce his working hours :( \n\n";
		cout << "Days: ";
		in >> days;
		while (days > 30) {
			system("cls");
			cout << "Wrong input.\n";
			cout << "Days: ";
			in >> days;
		}
		return in;
	}
};

class Worker : public Employer
{
public:
	Worker() = default;
	Worker(const string& _name, const string& _surname, const short _id, const int _salary, const int _hours, const int _days)
		: Employer{ _name, _surname, _id, _salary, _hours, _days } {};

	virtual string getPost() const override { return "Worker"; }

	virtual double getSalary() const override
	{
		return (Hours() * Salary()) * Days();
	}

	virtual void ClassOriginalSetter(const int n) {}; //немає своїх унікальних данних

	virtual ostream& output(ostream& out = cout) const override
	{
		out << "    Worker\n";
		Employer::output();
		return out;
	}
};

class Manager : public Employer
{
	int workers{};
public:
	Manager() = default;
	Manager(const string& _name, const string& _surname, const short _id, const int _salary, const int _hours, const int _days, const int _workers)
		: Employer{ _name, _surname, _id, _salary, _hours, _days }, workers{ _workers } {};

	const int& Workers() const { return workers; }
	int& Workers() { return workers; }

	virtual string getPost() const override { return "Manager"; }

	virtual double getSalary() const override
	{	
		return (Hours() * Salary()) * Days() + (workers * 650);
	}

	virtual void ClassOriginalSetter(const int n) override
	{
		workers = n;
	}

	virtual ostream& output(ostream& out = cout) const override
	{
		out << "    Manager\n";
		Employer::output();
		out << "Workers: " << left << setw(11) << workers << endl;
		return out;
	}

	virtual istream& input(istream& in = cin) override
	{
		Employer::input();
		cout << "Workers: ";
		in >> workers;
		return in;
	}
};

class President : public Employer
{
	int profit{};
public:
	President() = default;
	President(const string& _name, const string& _surname,const short _id, const int _profit)
		: Employer{ _name, _surname, _id, 0, 0, 0}, profit{_profit} {};

	const int& Profit() const { return profit; }
	int& Profit() { return profit; }

	virtual string getPost() const override { return "President"; }

	virtual double getSalary() const override
	{
		return profit * 0.07;
	};

	virtual void ClassOriginalSetter(const int n) override
	{ 
		profit = n;
	}

	virtual ostream& output(ostream& out = cout) const override
	{
		out << "    President\n";
		out << "Name:    "  << Name() << endl;
		out << "Surname: "  << Surname() << endl;
		cout << "ID:     " << Id();
		out << "Company profit:" << profit << endl;
		return out;
	}

	virtual istream& input(istream& in = cin) override
	{
		cout << "Name: ";
		in >> Name();
		cout << "Surname: ";
		in >> Surname();
		cout << "ID: ";
		in >> Id();
		cout << "Company profit: ";
		in >> profit;
		return in;
	}
};