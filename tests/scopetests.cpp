#include <cassert>
#include <iostream>
#include "../src/DummyThing.h"
#include "../src/ClocksDriver.h"

using namespace ::DummyThing;
using namespace ::Drivers;
using namespace ::std;

void dummy_thing_provides_the_ultimate_answer()
{
  // when
  int result = TheAnswer();

  // then
  int expected = 42;
  assert(expected == result);
}

void initial_clock_frequency_matches_the_default_value()
{
  const uint16_t expected = 1234;
  const uint16_t actual = ClocksDriver::GetClockFrequency();

  assert(expected == actual);
}

int main()
{
  dummy_thing_provides_the_ultimate_answer();
  initial_clock_frequency_matches_the_default_value();

  cout << "All tests passed!" << endl;
  return 0;
}