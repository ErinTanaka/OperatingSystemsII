#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

//global variables
int numProcesses = 0;
int array[4];

//links for singly linked list
struct node{
  int content;
  node * next;
};

//function to generate random numbers for linked list
int genRandNum(int range){
  return rand() % range;
}

//fns for threads to call?
//examine the list
void searcherfn(struct * node list){
  tmpnode = list;
  while(tmonode->next != NULL){
    cout << tmpnode.content << endl;
    tmpnode = tmpnode->next;
  }
}
//insert a link in list
void inserterfn(struct * node list){
  node * tmpnode = new node;
  tmpnode->content=genRandNum(20);
  if (list==NULL){
    list=tmpnode;
    tmpnode->next=NULL;
  }
  else{
    node * itr = list
    while (itr->next != NULL){
      itr=itr->next
    }
    itr->next=tmpnode;
    itr->next->next = NULL;
  }
}
//removes link from list
void deleterfn(struct * node list, int removeIdx){

}

bool problem1(){ //returns true if process can start
  if (numProcesses < 3){
    return true;
  }
  else{
    return false;
  }
}

bool problem2(int processType){
  if (processType == 2 && numProcesses==0){
    return true;
  }
  else if (processType == 1 && isOnlySearchers() && problem1()){
    return true;
  }
  else if (processType == 3 && problem1()){
    return true;
  }
  else{
    return false;
  }
}

//check if process fits rules for beginning
bool canStartProcess(int processType){
  if (problem1() && problem2(processType)){
    return true;
  }
	return false;
}

int main(){
  pthread_t thread1, thread2, thread3, thread4;
  string thread = "thread";

  //create threads
  struct node list;
  int i;
  for(i = 0; i < 4; i++){
    int getStart = genRandNum(3);
    if(canStartProcess(getStart)){
      threadNum = thread + tostring(i);
    switch(getStart){
      case 1: //inserter
        array[i] = 1;
        pthread_create(threadNum, NULL, inserterfn(), NULL);
      case 2: //deleter
        array[i] = 2;
      	pthread_create(threadNum, NULL, deleterfn(), NULL);
      case 3: //searcher
        array[i] = 3;
      	pthread_create(threadNum, NULL, searcherfn(), NULL);
    }
    numProcesses++;
    }
  }

  return 0;
}
