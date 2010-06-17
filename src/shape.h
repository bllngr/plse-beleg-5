/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * shape.h
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
#include "point3d.h"
#include "color.h"

class shape {
public:
	shape();
	shape(std::string const& name, color const& color);
	virtual double volume() const = 0;
	virtual double surface() const = 0;
	virtual bool is_inside(point3d const& point) const = 0;
	std::string const& name() const;
	color const& Color() const;  // cannot be of the same name as the struct color
	virtual void printOn(std::ostream& os) const;
	~shape();
private:
	std::string name_;
	color color_;
};

std::ostream& operator<<(std::ostream& os, shape const& shape);

#endif // SHAPE_H