/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * sphere.cc
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
#include "sphere.h"

using namespace std;

// constructors and destructors
sphere::sphere() :
center_(point3d(0,0,0)),
radius_(1),
shape("sphere", color(0,0,0))
{
	cout << "sphere def c'tor" << endl;
}

sphere::sphere(point3d const& center, double radius) :
center_(center),
radius_(radius),
shape("sphere", color(0,0,0))
{
	cout << "sphere c'tor" << endl;
}

sphere::sphere(point3d const& center, double radius, string const& name,
		color const& color) :
center_(center),
radius_(radius),
shape(name, color)
{
	cout << "sphere c'tor" << endl;
}

sphere::sphere(sphere const& other) :
center_(other.center()),
radius_(other.radius()),
shape(other.name(), other.Color())
{
	cout << "sphere copy c'tor" << endl;
}

/* virtual */ sphere::~sphere()
{
	cout << "sphere de'tor" << endl;
}

// getters
double sphere::radius() const
{
	return radius_;
}

point3d sphere::center() const
{
	return center_;
}

// inherited member functions from shape
/* virtual */ double sphere::volume() const
{
	return (4./3 * M_PI * pow(radius_,3));
}

/* virtual */ double sphere::surface() const
{
	return (4 * M_PI * radius_ * radius_);
}

/* virtual */ bool sphere::is_inside(point3d const& point) const
{
	return (point.distanceTo(center_) <= radius_);
}

/* virtual */ void sphere::printOn(std::ostream& os) const
{
	// shape::printOn(os);
	os << ", " << center_ << ", " << radius_ << ")";
}

// ostream operator (external definition)
std::ostream& operator<<(std::ostream& os, sphere const& sphere)
{
	sphere.printOn(os);
	return os;
}
