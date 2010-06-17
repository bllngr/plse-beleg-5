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

#include "sphere.h"
#include <cmath> // M_PI, pow()

using namespace std;

sphere::sphere() :
center_(point3d(0,0,0)),
radius_(1),
shape("sphere", color(0,0,0))
{}

sphere::sphere(point3d const& center, double radius) :
center_(center),
radius_(radius),
shape("sphere", color(0,0,0))
{}

sphere::sphere(point3d const& center, double radius, string const& name,
		color const& color) :
center_(center),
radius_(radius),
shape(name, color)
{}

sphere::sphere(sphere const& other) :
center_(other.center()),
radius_(other.radius()),
shape(other.name(), other.Color())
{}

double sphere::radius() const
{
	return radius_;
}

point3d sphere::center() const
{
	return center_;
}

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

sphere::~sphere()  // dec'tor
{}

std::ostream& operator<<(std::ostream& os, sphere const& sphere)
{
	sphere.printOn(os);
	return os;
}
