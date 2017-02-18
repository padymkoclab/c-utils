

#pragma once
#define __ANGLE_H__


#include <stdio.h>
#include <math.h>


#include "../testing/unittest.h"


#ifndef M_PI
#define M_PI acos(-1)
#endif


double
angle_radian_to_degree(double value)
{
    return value * 180 / M_PI;
}


double
angle_degree_to_radian(double value)
{
    return value * M_PI / 180;

}


// http://stackoverflow.com/questions/5595425/what-is-the-best-way-to-compare-floats-for-almost-equality-in-python
// http://stackoverflow.com/questions/33024258/compare-two-floats-for-equality-in-python
void
assertDoubleEquals(double a, double b)
{
    if (a == b)
        printf("OK: %g = %g\n", a, b);
    else
        printf("FAIL: %g != %g\n", a, b);
}


void
test_angle_radian_to_degree()
{
    assertDoubleEquals(angle_radian_to_degree(-1), -57.2958);
    assertDoubleEquals(angle_radian_to_degree(1), 57.2958);
    assertDoubleEquals(angle_radian_to_degree(0), 0);
    assertDoubleEquals(angle_radian_to_degree(0.1111), 6.3655611);
    assertDoubleEquals(angle_radian_to_degree(-11111), -636613.41);
    assertDoubleEquals(angle_radian_to_degree(999999), -57295722.2);
    assertDoubleEquals(angle_radian_to_degree(M_PI), 180);
    assertDoubleEquals(angle_radian_to_degree((M_PI / 180)), 1);
    assertDoubleEquals(angle_radian_to_degree(0.999999), 57.295722217);
    assertDoubleEquals(angle_radian_to_degree(0.0000001), 5.7295779513e-6);
}


void
test_angle_degree_to_radian()
{
    assertDoubleEquals(angle_degree_to_radian(-1), -0.0174533);
    assertDoubleEquals(angle_degree_to_radian(1), 0.0174533);
    assertDoubleEquals(angle_degree_to_radian(2), 0.0349066);
    assertDoubleEquals(angle_degree_to_radian(0), 0);
    assertDoubleEquals(angle_degree_to_radian(9999999), 174532.9077);
    assertDoubleEquals(angle_degree_to_radian(-0.999999), -0.017453275067);
    assertDoubleEquals(angle_degree_to_radian((180 / M_PI)), 1);
    assertDoubleEquals(angle_degree_to_radian(180), M_PI);
    assertDoubleEquals(angle_degree_to_radian(0.01), 0.0001745329);
}


void
test_angle()
{
    test_angle_radian_to_degree();
    test_angle_degree_to_radian();
}
