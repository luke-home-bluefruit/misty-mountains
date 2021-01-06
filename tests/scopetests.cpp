#include <cassert>
#include <iostream>
#include "../src/DummyThing.h"

using namespace DummyThing;
using namespace std;

void dummy_thing_provides_the_ultimate_answer()
{
  // when
  int result = TheAnswer();

  // then
  int expected = 42;
  assert(expected == result);
}


int main()
{
  dummy_thing_provides_the_ultimate_answer();

  cout << "All tests passed!" << endl;
  return 0;
}