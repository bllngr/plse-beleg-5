/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * box.cc
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#include <cmath> // M_PI, pow()
#include <iostream>
#include <ostream>
#include "box.h"

using namespace std;

// constructors and destructors
box::box() :
corner_(point3d(-.5,-.5,.5)),
length_(1),
width_(1),
height_(2),
shape("box", color(0,0,0))
{
	cout << "box def c'tor" << endl;
}

box::box(point3d const& corner, double length, double width, double height) :
corner_(corner),
length_(length),
width_(width),
height_(height),
shape("box", color(0,0,0))
{
	cout << "box c'tor" << endl;
}

box::box(point3d const& corner, double length, double width, double height,
	std::string const& name, color const& color) :
corner_(corner),
length_(length),
width_(width),
height_(height),
shape(name, color)
{
	cout << "box c'tor" << endl;
}

box::box(box const& other) :
corner_(other.corner()),
length_(other.length()),
width_(other.width()),
height_(other.height()),
shape(other.name(), other.Color())
{
	cout << "box copy c'tor" << endl;
}

/* virtual */ box::~box()  // dec'tor
{
	cout << "box d'tor" << endl;
}

// getters
double box::width() const
{
	return width_;
}

double box::length() const
{
	return length_;
}

double box::height() const
{
	return height_;
}

point3d box::corner() const
{
	return corner_;
}

// inherited member functions from shape
/* virtual */ double box::volume() const
{
	return length_ * width_ * height_;
}

/* virtual */ double box::surface() const
{
	double front = length_ * height_;
	double side  = width_ * height_;
	double top   = length_ * width_;
	return 2 * front + 2 * top + 2 * side;
}

/* virtual */ bool box::is_inside(point3d const& point) const
{
	cout << "corner: " << corner_ << endl;
	cout << "point: " << point << endl;
	if(corner_[0] > point[0] || corner_[0] + length_ < point[0]) return false;
	if(corner_[1] > point[1] || corner_[1] + height_ < point[1]) return false;
	if(corner_[2] > point[2] || corner_[2] + width_ < point[2]) return false;
	// else
	return true;
}

/* virtual */ void box::printOn(std::ostream& os) const
{
	shape::printOn(os);
	os << corner_ << ", " << length_ << ", " << width_ <<", " <<
		height_ << ")";
}

// ostream operator (external definition)
std::ostream& operator<<(std::ostream& os, box const& box)
{
	box.printOn(os);
	return os;
}
