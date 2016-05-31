// circle.h
// A circle class that works with circles
// Created by eric on 19/05/16.
//

#ifndef INC_1_CIRCLE_H
#define INC_1_CIRCLE_H

class Circle
{
private:
	//	x coordinate (an int), can be negative
	int x;

	//	y coordinate (an int), can be negative
	int y;

	//	radius (a double), must be greater than 0.0
	double radius;

public:
	//A default constructor that creates a circle of radius 10 at position 0,0
	Circle();

	//A constructor with parameters for x, y, and radius
	Circle(int newx, int newy, double newradius);

	//normal destructor
	~Circle();

	//moves the circle the given horizontal and vertical distances (therefore changing its x and y attributes)
	void move(int horiz, int vert);
	
	//changes the circle's radius to r, or to 10.0 if r is invalid
	void setRadius(double r);

	//returns the circle's x coordinate
	int getX();

	//returns the circle's y coordinate
	int getY();

	//returns the circle's radius
	double getRadius();

	//returns the circle's area
	double getArea();

	//displays the circle's attributes like this: "radius 10.0 at point x = 12, y = 17"
	void displayCircle();

	//returns true if c intersects the calling circle;this is an optional method, so finish everything else first!
	bool intersect(Circle c);

};

#endif //INC_1_CIRCLE_H