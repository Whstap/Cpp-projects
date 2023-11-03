#pragma once

#include <iostream>
#include <string>
using namespace std;

struct Pen
{
	string color{"black"};
	int	thickness{1};
	Pen(const string& color, const int thickness) : color{ color }, thickness{ thickness } {}	
	Pen() = default;
}; 

struct Brush
{
	string color{"white"};
	Brush(const string& color) : color{ color } {}
	Brush() = default;
};

class Figure
{
//protected:
	Brush background{};
	Pen border{};

public:
	Figure() = default;
	Figure(const Brush& background, const Pen& border) : background{ background }, border{ border } {}

	virtual ostream& output(ostream& out = cout) const
	{
		out << "Background: " << background.color << "\nborder: " << border.color << "\nthickness: " << border.thickness << endl;
		return out;
	}
	virtual void input() 
	{
		cout << "Enter background color: ";	
		cin >> background.color;
		cout << "Enter border color: ";
		cin >> border.color;
		cout << "Enter border thickness: ";
		cin >> border.thickness;
	}

	virtual double area() const = 0; 
};

class Rectangle : public Figure
{
protected:
	int side1{};
	int side2{};
public:
	Rectangle() = default;
	Rectangle(const Brush& background, const Pen& border, const int side1, const int side2) 
		: Figure(background, border), side1{side1}, side2{side2} {}

	virtual ostream& output(ostream& out = cout) const override
	{
		out << "Rectangle: " << endl;
		Figure::output(out);
		out << "side1: " << side1 << "\tside2: " << side2 << endl;
		return out;
	}

	virtual void input() override
	{
		Figure::input();
		cout << "Enter side1: ";
		cin >> side1;
		cout << "Enter side2: ";
		cin >> side2;
	}

	virtual double area() const override
	{
		return side1 * side2;
	}
};

class Square : public Rectangle
{
public:
	Square() = default;
	Square(const Brush& background, const Pen& border, const int side1) 
		: Rectangle(background, border, side1, side1) {}

	virtual ostream& output(ostream& out = cout) const override
	{
		out << "Square: " << endl;
		Figure::output(out);
		out << "side: " << side1 <<  endl;
		return out;
	}

	virtual void input() override
	{
		Figure::input();
		cout << "Enter side: ";
		cin >> side1;
	}
};

class Circle : public Figure
{
	int radius{};
public:
	Circle() = default;
	Circle(const Brush& background, const Pen& border, const int radius) 
		: Figure(background, border), radius{ radius } {}

	virtual ostream& output(ostream& out = cout) const override
	{
		out << "Circle: " << endl;
		Figure::output(out);
		out << "radius: " << radius << endl;
		return out;
	}

	virtual void input() override
	{
		Figure::input();
		cout << "Enter radius: ";
		cin >> radius;
	}
};

class Triangle : public Figure
{
protected:
	int side1{};
	int side2{};
	int side3{};
public:
	Triangle() = default;
	Triangle(const Brush& background, const Pen& border, const int side1, const int side2, const int side3)
		: Figure(background, border), side1{ side1 }, side2{ side2 }, side3{ side3 } {}

	virtual ostream& output(ostream& out = cout) const override
	{
		out << "Triangle: " << endl;
		Figure::output(out);
		out << "side1: " << side1 << "\tside2: " << side2 << "\tside3: " << side3 << endl;
		return out;
	}

	virtual void input() override
	{
		Figure::input();
		cout << "Enter side1: ";
		cin >> side1;
		cout << "Enter side2: ";
		cin >> side2;
		cout << "Enter side3: ";
		cin >> side3;
	}
};

class Ellipse : public Figure
{
protected:
	int radius1{};
	int radius2{};
public:
	Ellipse() = default;
	Ellipse(const Brush& background, const Pen& border, const int radius1, const int radius2)
		: Figure(background, border), radius1{ radius1 }, radius2{ radius2 } {}

	virtual ostream& output(ostream& out = cout) const override
	{
		out << "Ellipse: " << endl;
		Figure::output(out);
		out << "radius1: " << radius1 << "\tradius2: " << radius2 << endl;
		return out;
	}

	virtual void input() override
	{
		Figure::input();
		cout << "Enter radius1: ";
		cin >> radius1;
		cout << "Enter radius2: ";
		cin >> radius2;
	}
};

class Rhombus : public Figure
{
	int side1{};
	int side2{};
	int angle1{};
	int angle2{};	
public:
	Rhombus() = default;
	Rhombus(const Brush& background, const Pen& border, const int side1, const int side2, const int angle1, const int angle2)
		: Figure(background, border), side1{ side1 }, side2{ side2 }, angle1{ angle1 }, angle2{ angle2 } {}

	virtual ostream& output(ostream& out = cout) const override
	{
		out << "Rhombus: " << endl;
		Figure::output(out);
		out << "side1: " << side1 << "\tside2: " << side2 << "\tangle1: " << angle1 << "\tangle2: " << angle2 << endl;
		return out;
	}

	virtual void input() override
	{
		Figure::input();
		cout << "Enter side1: ";
		cin >> side1;
		cout << "Enter side2: ";
		cin >> side2;
		cout << "Enter angle1: ";
		cin >> angle1;
		cout << "Enter angle2: ";
		cin >> angle2;
	}
};

class Trapeze : public Figure
{
	int side1{};
	int side2{};
	int side3{};
	int side4{};
	int height{};
public:
	Trapeze() = default;
	Trapeze(const Brush& background, const Pen& border, const int side1, const int side2, const int side3, const int side4, const int height)
		: Figure(background, border), side1{ side1 }, side2{ side2 }, side3{ side3 }, side4{ side4 }, height{ height } {}

	virtual ostream& output(ostream& out = cout) const override
	{
		out << "Trapeze: " << endl;
		Figure::output(out);
		out << "side1: " << side1 << "\tside2: " << side2 << "\tside3: " << side3 << "\tside4: " << side4 << "\theight: " << height << endl;
		return out;
	}
	 
	virtual void input() override
	{
		Figure::input();
		cout << "Enter side1: ";
		cin >> side1;
		cout << "Enter side2: ";
		cin >> side2;
		cout << "Enter side3: ";
		cin >> side3;
		cout << "Enter side4: ";
		cin >> side4;
		cout << "Enter height: ";
		cin >> height;
	}
};

class Parallelogram : public Figure
{
	int side1{};
	int side2{};
public:
	Parallelogram() = default;
	Parallelogram(const Brush& background, const Pen& border, const int side1, const int side2)
		: Figure(background, border), side1{ side1 }, side2{ side2 } {}

	virtual ostream& output(ostream& out = cout) const override
	{
		out << "Parallelogram: " << endl;
		Figure::output(out);
		out << "side1: " << side1 << "\tside2: " << side2 << endl;
		return out;
	}

	virtual void input() override
	{
		Figure::input();
		cout << "Enter side1: ";
		cin >> side1;
		cout << "Enter side2: ";
		cin >> side2;
	}
};