/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe5.5.cc
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */


#include "box.h"
#include "sphere.h"
#include <iostream>
#include <assert.h>
#include <cmath>
#include <UnitTest++.h>

using namespace std;

SUITE(extended_box_testsuite)
{
	TEST(check_def_constructor)
	{
		box box;
		CHECK_EQUAL(box.name(), "box");
		CHECK_EQUAL(box.Color(), color(0,0,0));
	}
	TEST(check_constructor)
	{
		box box(point3d(-1,-1,-1), 2, 2, 2);
		CHECK_EQUAL(box.name(), "box");
		CHECK_EQUAL(box.Color(), color(0,0,0));
	}
}

SUITE(extended_sphere_testsuite)
{
	TEST(check_def_constructor)
	{
		sphere sphere;
		CHECK_EQUAL(sphere.name(), "sphere");
		CHECK_EQUAL(sphere.Color(), color(0,0,0));
	}	
	TEST(check_constructor)
	{
		sphere sphere(point3d(-1,-1,-1), 2);
		CHECK_EQUAL(sphere.name(), "sphere");
		CHECK_EQUAL(sphere.Color(), color(0,0,0));
	}
}

int main()
{
	return UnitTest::RunAllTests();
}