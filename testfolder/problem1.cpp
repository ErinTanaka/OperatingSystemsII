#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 7
#define MAX_THREADS 3

//global variables
int numProcesses = 0;
bool hitMaxThreads=false;
int resource[8192];


void *executeProcess(void *threadid) {
   long tid;
   tid = (long)threadid;
	 while(true){
	 	if(numProcesses != MAX_THREADS && hitMaxThreads==false){
		 numProcesses++;
		 if (numProcesses==MAX_THREADS){
			 hitMaxThreads=true;
		 }
		 cout << tid << " accessing resource " << endl;

 	   for (int i=0; i<8192; i++){
 		   int temp = resource[i];
 	   }
   cout << tid << " finished" << endl;
   numProcesses--;
	 if(numProcesses==0){
		 hitMaxThreads=false;
	 }
   pthread_exit(NULL);
	}
	
}
}

int main () {

   pthread_t threads[NUM_THREADS];
   int i;
   for(i = 0; i < NUM_THREADS; i++ ) {
   	  // if(canStartProcesses()){
			cout << "Starting: " <<  i << endl;
				pthread_create(&threads[i], NULL, executeProcess, (void *)i);


   }
	 for(int i=0; i<NUM_THREADS; i++){
	 pthread_join(threads[i], NULL);
 }

	 //sleep(10);
	 //cout << "Doneskis" << endl;
	 return 0;
}
