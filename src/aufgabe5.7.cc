/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * aufgabe5.7.cc
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
#include "shape.h"
#include "box.h"

using namespace std;


int main()
{
	box defaultBox;
	cout << " defaultBox: " << defaultBox << endl;
	cout << "_defaultBox: " << "3box(\"" << defaultBox.name() << "\", "
		<< defaultBox.Color() << ", "
		<< defaultBox.corner() << ", "
		<< defaultBox.length() << ", " << defaultBox.height() << ", "
		<< defaultBox.width() << ")" << endl;
	
	return 0;
}