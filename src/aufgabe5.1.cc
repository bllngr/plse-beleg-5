/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe5.1.cc
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */


#include "point3d.h"
#include <iostream>
#include <assert.h>
#include <UnitTest++.h>

using namespace std;

SUITE(point3d_testsuite)
{
	TEST(check_constructor_and_get_operator_with_indices)
	{
		point3d punkt(1, -1, 3);
		CHECK_EQUAL(punkt[0], 1);
		CHECK_EQUAL(punkt[1], -1);
		CHECK_EQUAL(punkt[2], 3);
	}
	TEST(check_default_constructor)
	{
		point3d punkt;
		CHECK_EQUAL(punkt[0], 0);
		CHECK_EQUAL(punkt[1], 0);
		CHECK_EQUAL(punkt[2], 0);
	}
	/* TEST(check_equal_operator)
	{
		point3d p1(0,0,0);
		point3d p2(0,0,0);
		// CHECK_EQUAL(p1, p2);
	} */
}

int main()
{
	return UnitTest::RunAllTests();
}