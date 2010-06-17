#include <UnitTest++.h>
#include "point3d.h"

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
}

int main()
{
	return UnitTest::RunAllTests();
}