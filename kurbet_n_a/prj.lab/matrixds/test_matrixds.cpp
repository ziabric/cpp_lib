#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "matrixds.h"

TEST_CASE("Creation & Assignment") {

SUBCASE("Constructors") {
MatrixDs mv(3, 2);
CHECK(mv.rowCount() == 2);
CHECK(mv.colCount() == 3);

}

}

TEST_CASE("Insertion") {
SUBCASE("Assignment") {
MatrixDs mv(2, 2);
mv.at(0, 0) = 1.2f;
CHECK(mv.at(0, 0) == 1.2f);

}

}

TEST_CASE("Math Operations") {
SUBCASE("Transpose") {
MatrixDs mv(2, 1);
mv.at(0, 0) = 2.1f;
mv.at(0, 1) = -1.1f;
mv.transpose();

CHECK(mv.rowCount() == 2);
CHECK(mv.colCount() == 1);
CHECK(mv.at(0, 0) == 2.1f);
CHECK(mv.at(1, 0) == -1.1f);
}

SUBCASE("Swaps") {
MatrixDs mv(3, 2);
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

}