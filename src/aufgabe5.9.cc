/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe5.9.cc
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#include <assert.h>
#include <iostream>
#include "box.h"
#include "sphere.h"

using namespace std;

int main()
{
	cout << "instantiate default box:" << endl;
	box* defBox = new box();

	cout << endl << "instantiate default sphere:" << endl;
	sphere* defSphere = new sphere();

	cout << endl << "instantiate custom box:" << endl;
	box* custBox = new box(point3d(-4, 0, .5), 2, 4, 1);

	cout << endl << "instantiate custom sphere:" << endl;
	sphere* custSphere = new sphere(point3d(2,2,2), 1);

	cout << endl << "delete default box:" << endl;
	assert(defBox != 0);
	delete defBox;
	defBox = 0;

	/*
	cout << endl << "delete default sphere:" << endl;
	assert(defSphere != 0);
	delete defSphere;
	defSphere = 0; */
	
	cout << endl << "delete custom box:" << endl;
	assert(custBox != 0);
	delete custBox;
	custBox = 0;
	
	/* cout << endl << "delete custom sphere:" << endl;
	assert(custSphere != 0);
	delete custSphere;
	custSphere = 0; */
	
	return 0;
}