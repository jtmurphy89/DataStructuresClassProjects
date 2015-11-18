#include <iostream> 
#include <string>
#include <vector>
#include "etree.h"

using namespace std;


min_heap::min_heap()
{
  next = 1;

}


min_heap::~min_heap()
{



}



void min_heap::push(TNode* node)
{
  heap_array.push_back(node); //add to array

  if(heap_array[next]->left == NULL) //add to heap
    heap_array[next]->left = node; 
  else 
    {
      heap_array[next]->right = node; 
      next++; //update next
    }
  percolate_up();

}


TNode* min_heap::pop()
{
  heap_array[0] = heap_array[1]; //swap first and last nodes in array
  heap_array[1] = heap_array[heap_array.size()-1];
  heap_array[heap_array.size()-1] = heap_array[0];
  
  heap_array[heap_array.size()-1]->left = NULL; //swap first and last nodes in heap
  heap_array[heap_array.size()-1]->right = NULL;
  heap_array[1]->left = heap_array[2];
  heap_array[1]->right = heap_array[3];


  int parent = heap_array.size()/2; //set pointer to popped node equal to null
  if(heap_array[parent]->right == NULL)
    heap_array[parent]->left = NULL;
  else 
    heap_array[parent]->right = NULL;

  
  TNode* tmp = heap_array.pop_back(); //remove from array representing min_heap

  if(heap_array[next-1]->right == NULL) //adjust next if necessary
    next --;
  
  percolate_down();
  return tmp;

}


void min_heap::percolate_up()
{
  int child = heap_array.size()-1;
 
  while(1){

    if(heap_array[child]->freq >= heap_array[child/2]->freq) //check if satisfies invariant
      break;
    else //if not
      {
	heap_array[0] = heap_array[child]; //swap nodes in array
	heap_array[child] = heap_array[child/2];
	heap_array[child/2] = heap_array[0];
	
	heap_array[child]->left = heap_array[child/2]->left; //swap nodes in heap                                                                                                                        
	heap_array[child]->right = heap_array[child/2]->right;
	heap_array[child/2]->left = heap_array[0]->left;
	heap_array[child/2]->right = heap_array[0]->right;
	 

	





}



void min_heap::percolate_down()
{






}



