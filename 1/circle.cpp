//
// Created by eric on 19/05/16.
//

#include <iostream>
#include <cmath>
#include "circle.h"

using namespace std;

//private:
//	x coordinate (an int), can be negative
int x;

//	y coordinate (an int), can be negative
int y;

//	radius (a double), must be greater than 0.0
double radius;

//public methods
//A default constructor that creates a circle of radius 10 at position 0,0
Circle::Circle():
		x(0),
		y(0),
		radius(10)
{
//nothing
}

//A constructor with parameters for x, y, and radius
Circle::Circle(int newx, int newy, double newradius):
		x(newx),
		y(newy),
		radius(newradius)
{
	//nothing
}

//normal destructor
Circle::~Circle()
{
//nothing
}

//moves the circle the given horizontal and vertical distances (therefore changing its x and y attributes)
void Circle::move(int horiz, int vert)
{
	if(horiz > 0)
	{
		x += horiz;
	}

	if(vert > 0)
	{
		y += vert;
	}
}

//changes the circle's radius to r, or to 10.0 if r is invalid
void Circle::setRadius(double r)
{
	if(r > 0)
	{
		radius = r;
	}
	else
	{
		radius = 10;
	}
}

//returns the circle's x coordinate
int Circle::getX()
{
	return x;
}

//returns the circle's y coordinate
int Circle::getY()
{
	return y;
}

//returns the circle's radius
double Circle::getRadius()
{
	return radius;
}

//returns the circle's area
double Circle::getArea()
{
	double pi = 3.14159265359;
	return pi * radius * radius;
}

//displays the circle's attributes like this: "radius 10.0 at point x = 12, y = 17"
void Circle::displayCircle()
{
	cout << "radius " << radius << " at point x = " << x << ", y = " << y << endl;
}

//returns true if c intersects the calling circle;this is an optional method, so finish everything else first!
bool Circle::intersect(Circle c)
{
	//find the hypotenuse between the 2 centers, then compare with combined radius.
	// if hypotenuse is greater, then there is no overlap

	if( ((radius - c.radius)*(radius - c.radius)) <= ((x - c.x)*(x - c.x) + (y - c.y)*(y - c.y))
			&& ((x - c.x)*(x - c.x) + (y - c.y)*(y - c.y)) <= ((radius + c.radius)*(radius + c.radius)))
	{
		return 1;
	}

	return 0;
}
