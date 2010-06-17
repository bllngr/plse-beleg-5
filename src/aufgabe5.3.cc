/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe5.3.cc
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#include <iostream>
#include <assert.h>
#include <cmath>
#include <UnitTest++.h>
#include "box.h"
#include "sphere.h"

using namespace std;

SUITE(box_testsuite)
{
	TEST(check_constructor)
	{
		box box(point3d(-1,-1,-1), 2, 2, 2);
		CHECK_EQUAL(box.corner(), point3d (-1,-1,-1));
		CHECK_EQUAL(box.length(), 2);
		CHECK_EQUAL(box.width(), 2);
		CHECK_EQUAL(box.height(), 2);
	}
	TEST(check_volume)
	{
		box box(point3d(0,0,0), 1, 2, 1);
		CHECK_EQUAL(box.volume(), 2);
	}
	TEST(check_surface)
	{
		box box(point3d(0,0,0), 1, 2, 1);
		CHECK_EQUAL(box.surface(), 10);
	}
	TEST(check_in_inside)
	{
		point3d punkt1(5,2,1);
		box box1(point3d(4,.5,0), 1, 2, 2);
		CHECK(box1.is_inside(punkt1));
	}
}

SUITE(sphere_testsuite)
{
	TEST(check_constructor)
	{
		sphere sphere(point3d(0,0,0), 1);
		CHECK_EQUAL(sphere.center(), point3d(0,0,0));
		CHECK_EQUAL(sphere.radius(), 1);
	}
	TEST(check_volume)
	{
		sphere sphere(point3d(0,0,0), 1);
		CHECK_EQUAL(sphere.volume(), 4./3 * M_PI);
	}
	TEST(check_surface)
	{
		sphere sphere(point3d(0,0,0), .5);
		CHECK_EQUAL(sphere.surface(), M_PI);
	}
	TEST(check_in_inside)
	{
		point3d punkt(.25,0,-.3);
		sphere sphere(point3d(0,0,0), 1);
		CHECK(sphere.is_inside(punkt));
	}
}

int main()
{
	return UnitTest::RunAllTests();
}