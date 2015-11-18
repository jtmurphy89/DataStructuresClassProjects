#include <iostream>
#include <string> 
#include "hash_table.h"
using namespace std;

static int lookup_switch = 1;
static int insert_switch = 1;

hash_table::hash_table(){
  head = new Bucket[5];
  for(int i=0; i<5; i++)
    head[i].status=0;
  size = 5;
  elts = 0; 
};


hash_table::~hash_table(){
  delete [] head;
}


void hash_table::insert(int key, string value){
  lookup_switch =0;
  if(lookup(key)==1){
    if(insert_switch==1)
      cout << "item already present" << endl;
  }
  else{
      int hash_key = hash(key);
      for(int i=0; i<size; i++){
	if(head[hash_key].status == 0 || head[hash_key].status == -1){
	  head[hash_key].name = value;
	  head[hash_key].key = key;
	  head[hash_key].status = 1;
	  elts++;
	  if(insert_switch==1)
	    cout << "item successfully inserted" << endl;
	  double e = elts;
	  double lambda = e/size;
       	  if(lambda > 0.7)
	    resize();
	  break;
	}
	else hash_key = (hash_key+1) % size;
      }
  }
  lookup_switch=1;
};


void hash_table::lazy_delete(int key){
  lookup_switch=0;
  if(lookup(key) == 0)
    cout << "item not present in the table" << endl;
  else {
    int hash_key=hash(key);
    for(int i=0; i<size; i++){
      if(head[hash_key].key == key){
	head[hash_key].status = -1;
	elts = elts-1;
	cout << "item successfully deleted" << endl;
	break;
      }
      else hash_key = (hash_key + 1) % size;
    }
  }
  lookup_switch=1;
};


int hash_table::lookup(int key){
  int hash_key = hash(key);
  for(int i=0; i<size; i++){
    if(head[hash_key].status == 1){ 
      if(head[hash_key].key==key){
	if(lookup_switch==1)
	  cout << "item found; " << head[hash_key].name << " " << hash_key << endl;
	return 1;
      }
    }
    else if(head[hash_key].status == 0){
      if(lookup_switch==1)
	cout << "item not found" << endl;
      return 0;
    }
    hash_key=(hash_key+1) % size;
  }
  if(lookup_switch==1)
    cout << "item not found" << endl;
  return 0;
};


void hash_table::resize(){
  insert_switch=0;
  Bucket* rehash = new Bucket[2*size];
  Bucket* tmp = head;
  head = rehash;
  size = 2*size;
  elts = 0;
  for(int i=0; i<size; i++)
    head[i].status=0;
  for(int i=0; i < (size/2); i++){
    if(tmp[i].status == 1)
      insert(tmp[i].key,tmp[i].name);
  }
  cout << "table doubled" << endl;
  delete [] tmp;
  insert_switch=1;
};


void hash_table::print(){
  for(int i=0; i < size; i++){
    if(head[i].status == 1)
      cout << "(" << head[i].key << "," << head[i].name << ")";
  }
  cout << endl;
};


int hash_table::hash(int key){
  return (key % 443 % size);

};


