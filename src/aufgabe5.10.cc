/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe5.10.cc
 * Copyright (C) Julius Bullinger 2010 <julius.bullinger@uni-weimar.de>
 *
 *   This program is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2, as
 * published by Sam Hocevar. See http://sam.zoy.org/wtfpl/COPYING for more
 * details.
 * 
 */

#include <list>
#include "box.h"
#include "sphere.h"

using namespace std;

int main()
{
	list<shape*> shapes;

	shape* shapePointer1 = new box;
	shape* shapePointer2 = new sphere;
	shape* shapePointer3 = new box(point3d(4,-3,8), .2, 8, 1, "non-default box",
		color(255,0,0));
	shape* shapePointer4 = new sphere(point3d(0,1,-4), 4);

	box* boxPointer = new box(point3d(-.5, -.5, -.5), 1, 1, 1);
	sphere* spherePointer = new sphere;

	shapes.push_back(shapePointer1);
	shapes.push_back(shapePointer2);
	shapes.push_back(shapePointer3);
	shapes.push_back(shapePointer4);
	shapes.push_back(boxPointer);
	
	cout << "the shapes list contains the following " << shapes.size()
		<< " elements:" << endl;

	int i = 0;
	list<shape*>::iterator it;
	for (it = shapes.begin(); it != shapes.end(); ++it)
	{
		cout << "[" << i << "]: " << **it << endl;
		++i;
	}
	
	return 0;
}