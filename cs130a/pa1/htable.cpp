#include <iostream>
#include <string>
#include "hash_table.h"

using namespace std; 

int main(){

  hash_table table; 
  string s1,s2;
  int i1;

  while(1){
    cin >> s1;
    if (cin.eof())
      break;
    if(s1.at(0) == 'i'){
      cin >> i1; 
      cin >> s2;
      table.insert(i1,s2);
      if (cin.eof())
	break;
    }
    else if(s1.at(0) == 'l'){
      cin >> i1;
      table.lookup(i1);
      if (cin.eof())
	break;
    }
    else if(s1.at(0) == 'd'){
      cin >> i1;
      table.lazy_delete(i1);
      if (cin.eof())
	break;
    }
    else if(s1.at(0) == 'p'){
      table.print();
      if (cin.eof())
	break;
    }
  }

  return 0;

}
