#include "Test.h"

#include <list>
#include <typeinfo>
#include <set>

using namespace GTU;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::list;
using std::set;


int main() {

  testLinkedList();
  testArrayList();
  testHashSet();

  cout << "I have written different test functions you can try all concerete classes seperately if you want" << endl;


  return 0;
}
