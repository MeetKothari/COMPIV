#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps){ // the test case provided

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9) == 51);

}

BOOST_AUTO_TEST_CASE(stepexample){ // a test meant to test the step function 
  FibLFSR a("11101111111111111100");
  BOOST_REQUIRE(a.step() == 1);
  BOOST_REQUIRE(a.step() == 1);
  BOOST_REQUIRE(a.step() == 0);
}

BOOST_AUTO_TEST_CASE(generateexample){ // a test meant to test the generate function
  FibLFSR test3("1100011011000011");
  BOOST_REQUIRE(test3.generate(5) == 6);
}
