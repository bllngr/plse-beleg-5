/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * shape.cc
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#include "shape.h"
#include <typeinfo>

using namespace std;

shape::shape() :
name_("shape"),
color_(color(0,0,0))
{}

shape::shape(string const& name, color const& color) :
name_(name),
color_(color)
{}

string const& shape::name () const
{
	return name_;
}

color const& shape::Color () const
{
	return color_;
}

/* virtual */ void shape::printOn(std::ostream& os) const
{
	os << typeid(*this).name() << "(\"" << name_ << "\", " << color_ << ", ";
}

shape::~shape()
{}

std::ostream& operator<<(std::ostream& os, shape const& shape)
{
	shape.printOn(os);
	return os;
}