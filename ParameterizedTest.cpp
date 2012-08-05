#include "gmock/gmock.h"

using namespace ::testing;

// START:SumCase
struct SumCase {
   int a, b, expected;
   SumCase(int anA, int aB, int anExpected) 
      : a(anA), b(aB), expected(anExpected) {}
};
// END:SumCase

// START:SumCaseFixture
class AnAdder: public TestWithParam<SumCase> {
};
// END:SumCaseFixture

// START:Adder
class Adder {
public:
   static int sum(int a, int b) {
      return a + b;
   }
};
// END:Adder

// START:RegularAdderTest
TEST(AnAdder, GeneratesASumFromTwoNumbers) {
   ASSERT_THAT(Adder::sum(1, 1), Eq(2));
}
// END:RegularAdderTest

// START:ParameterizedAdderTest
TEST_P(AnAdder, GeneratesLotsOfSumsFromTwoNumbers) {
   SumCase input = GetParam();
   ASSERT_THAT(Adder::sum(input.a, input.b), Eq(input.expected));
}

SumCase sums[] = { 
   SumCase(1, 1, 2), 
   SumCase(1, 2, 3),
   SumCase(2, 2, 4) 
};

INSTANTIATE_TEST_CASE_P(Parameterized, AnAdder, ValuesIn(sums));
// END:ParameterizedAdderTest

