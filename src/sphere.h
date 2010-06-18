/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * sphere.h
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#ifndef SPHERE_H
#define SPHERE_H

#include "shape.h"
#include "point3d.h"

class sphere: public shape
{
public:
	// constructors and destructors
	sphere(); // def c'tor
	sphere(point3d const& center, double radius);
	sphere(point3d const& center, double radius, std::string const& name,
		color const& color);
	sphere(sphere const&); // copy c'tor
	/* virtual */ ~sphere(); // des'tor

	// getters
	double radius() const;
	point3d center() const;

	// inherited member functions from shape
	/* virtual */ double volume() const;
	/* virtual */ double surface() const;
	/* virtual */ bool is_inside(point3d const& point) const;
	/* virtual */ void printOn(std::ostream& os) const;
private:
	double radius_;
	point3d center_;
};

// ostream operator (external declaration)
std::ostream& operator<<(std::ostream& os, sphere const& sphere);

#endif // SPHERE_H
