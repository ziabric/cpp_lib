//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

//#include <doctest/doctest.h>
#include <iostream>
#include <limits>

#include <arrayd/arrayd.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>


TEST_CASE("Creation & Assignment") {
    ArrayD x;
    CHECK(x.size() == 0);

    ArrayD y(3);
    ArrayD z1(1);
    z1[0] = 1.1f;
    z1 = y;
    CHECK(z1.size() == 3);

    ArrayD z2(x);
    CHECK(z2.size() == 0);
}

TEST_CASE("Insertion & Copy") {
    ArrayD x(5);
    x[0] = 2.1f;
    CHECK(fabs(x[0] - 2.1f) < std::numeric_limits<float>::epsilon());

    ArrayD y(3);
    y[0] = 3.1f;
    y[1] = 4.2f;
    y[2] = 5.3f;
    x = y;
    CHECK(x.size() == 3);
    CHECK((x[0] - 3.1f) < std::numeric_limits<float>::epsilon());
    CHECK((x[1] - 4.2f) < std::numeric_limits<float>::epsilon());
    CHECK((x[2] - 5.3f) < std::numeric_limits<float>::epsilon());
}

TEST_CASE("Resizing") {
    ArrayD x;

    x.resize(10);
    CHECK(x.size() == 10);

    x[0] = 2.1;
    x.resize(5);
    CHECK(x.size() == 5);

    }