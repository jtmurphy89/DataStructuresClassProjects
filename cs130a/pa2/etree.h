#ifndef ETREE_H
#define ETREE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TNode
{
TNode* left;
TNode* right;
int freq;
char letter;
};


class min_heap
{

private:
int next;
vector<TNode*> heap_array;

public:
min_heap(); //default constructor
~min_heap();
void push(TNode* node);
TNode* pop(); 
void percolate_up();
void percolate_down();
 



}





#endif
