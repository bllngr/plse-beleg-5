/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe5.6.cc
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
#include <UnitTest++.h>
#include <cassert>
#include "shape.h"
#include "box.h"

using namespace std;

SUITE(shape_testsuite)
{
	TEST(check_print_on)
	{
		box box1;
		shape* shapePointer = box1;
		cout << (*shapePointer) << endl;
		assert(shapePointer != 0); // makro assert
		delete shapePointer;
		shapePointer = 0;

	}
}

int main()
{
	return UnitTest::RunAllTests();
}