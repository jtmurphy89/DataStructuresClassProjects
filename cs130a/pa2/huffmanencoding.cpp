#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
//#include "etree.h"

using namespace std;

struct letter {
  
  char ch;
  int freq;

};


int* get_freq(char* input_file)
{
  static int char_array[27]={0};
  ifstream in;
  string firstLine;
  char ch;
  int j;
  in.open(input_file);
  getline(in, firstLine);
  for(int i=0; i< firstLine.size(); i++){
    ch=firstLine[i];
    if(ch==' ')
      char_array[0]++;
    else 
      {
	j = ch;
	j = j - 96;
	char_array[j]++;
      }

  }
  in.close();
  return char_array;
}



vector<struct letter> sort(int * oldArray)
{
  static vector<struct letter> newArray;
  struct letter temp;
  int max = oldArray[0];

  for (int i = 0; i < 27; i++)
    {
      if (oldArray[i] > max)
	max = oldArray[i];
    }

  for (int i = 1; i <= max; i++)
    {
      for (int j = 0; j < 27; j++)
	{
	  if (oldArray[j] == i)
	    {
	      if (j > 0)
		temp.ch = j+96;
	      else
		temp.ch = ' ';
	      temp.freq = i;
	      
	      newArray.push_back(temp);
	    }	    
	}
    }
  return newArray;

}








int main(int argc, char* argv[])
{
  int* p;
  vector<struct letter> q;
  p=get_freq(argv[1]);
  q=sort(p);
  for (int i = 0; i < q.size(); i++)
    {
      cout << q[i].ch << ' ' << q[i].freq << endl;
    }


  return 0;

}
