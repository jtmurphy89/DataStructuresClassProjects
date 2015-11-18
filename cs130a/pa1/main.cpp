#include <iostream>
#include <string>
#include "hash_table.cpp"

using namespace std;

int main ()
{
  hash_table table;
  table.insert(1,"blah");
  table.insert(6,"foo");
  table.lazy_delete(1);
  table.lookup(6);
  return 0;
}
