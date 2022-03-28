#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "matrixvs.h"

TEST_CASE("Creation & Assignment") {

SUBCASE("Constructors") {
MatrixVs mv(3, 2);
CHECK(mv.rowCount() == 2);
CHECK(mv.colCount() == 3);

}

}

TEST_CASE("Insertion") {
SUBCASE("Assignment") {
MatrixVs mv(2, 2);
mv.at(0, 0) = 1.2f;
CHECK(mv.at(0, 0) == 1.2f);

}

}

TEST_CASE("Math Operations") {
SUBCASE("Transpose") {
MatrixVs mv(2, 1);
mv.at(0, 0) = 2.1f;
mv.at(0, 1) = -1.1f;
mv.transpose();

CHECK(mv.rowCount() == 2);
CHECK(mv.colCount() == 1);
CHECK(mv.at(0, 0) == 2.1f);
CHECK(mv.at(1, 0) == -1.1f);
}

SUBCASE("Swaps") {
MatrixVs mv(3, 2);
mv.at(0, 0) = 1.1f; mv.at(0, 1) = 2.1f; mv.at(0, 2) = 3.1f;
mv.at(1, 0) = 1.2f; mv.at(1, 1) = 2.2f; mv.at(1, 2) = 3.2f;

mv.swapColumns(1, 2);

CHECK(mv.at(0, 1) == 3.1f);
CHECK(mv.at(1, 1) == 3.2f);

mv.swapRows(0, 1);

CHECK(mv.at(0, 0) == 1.2f);
CHECK(mv.at(0, 1) == 3.2f);
CHECK(mv.at(0, 2) == 2.2f);
}

SUBCASE("Multiply") {
MatrixVs mv1(2, 2);
mv1.at(0, 0) = 1.0f; mv1.at(0, 1) = 2.0f;
mv1.at(1, 0) = 2.0f; mv1.at(1, 1) = 3.0f;
MatrixVs mv2(3, 2);
mv2.at(0, 0) = 1.0f; mv2.at(0, 1) = 2.0f; mv2.at(0, 2) = 3.0f;
mv2.at(1, 0) = 3.0f; mv2.at(1, 1) = 4.0f; mv2.at(1, 2) = 5.0f;

mv1.multiply(mv2);
CHECK(mv1.colCount() == 3);
CHECK(mv1.at(0, 0) == 7.0f);
CHECK(mv1.at(0, 1) == 10.0f);
CHECK(mv1.at(0, 2) == 13.0f);
CHECK(mv1.at(1, 0) == 11.0f);
CHECK(mv1.at(1, 1) == 16.0f);
CHECK(mv1.at(1, 2) == 21.0f);

}
}