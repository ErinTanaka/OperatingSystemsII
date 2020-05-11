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
int resource[4096];
bool canStartProcesses(){
	if(numProcesses == MAX_THREADS || hitMaxThreads==true)return false;
	return true;
}

void *executeProcess(void *threadid) {
   long tid;
   tid = (long)threadid;
	 while(true){
	 if(numProcesses == MAX_THREADS || hitMaxThreads==true){
		 numProcesses++;
		 if (numProcesses==MAX_THREADS){
			 hitMaxThreads=true;
		 }
		 cout << "Thread ID: " << tid << " accessing resource " << endl;

 	   for (int i=0; i<4096; i++){
 		   int temp = resource[i];
 	   }
   cout << "Thread ID: " << tid << " finished" << endl;
   numProcesses--;
	 if(numProcesses==0){
		 hitMaxThreads=false;
	 }
   pthread_exit(NULL);
	}
}
}

int main () {
	srand (time(NULL));
   pthread_t threads[NUM_THREADS];
   int i;
   for(i = 0; i < NUM_THREADS; i++ ) {
   	  // if(canStartProcesses()){
			// 	cout << "Running thread: " <<  i << endl;
				pthread_create(&threads[i], NULL, executeProcess, (void *)i);
     	//  numProcesses++;
			//  if (numProcesses==MAX_THREADS){
			// 	 hitMaxThreads=true;
			//  }
   	  // }
   	  // else{
			// 	cout << "Max threads hit waiting for resource" << endl;
			// 	pthread_join(threads[i-1], NULL);
			// 	pthread_join(threads[i-2], NULL);
			// 	pthread_join(threads[i-3], NULL);
			// 	cout << "resource available, moving on to thread: " << i << endl;
			// 	//sleep(1);
			// 	i--;
			//
   	  // }

   }
	 for(int i=0; i<MAX_THREADS; i++){
	 pthread_join(threads[i], NULL);
 }

	 //sleep(10);
	 //cout << "Doneskis" << endl;
	 return 0;
}
