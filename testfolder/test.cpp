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
bool canStartProcesses(){
	if(numProcesses == MAX_THREADS || hitMaxThreads==true)return false;
	return true;
}

void *executeProcess(void *threadid) {
   long tid;
   tid = (long)threadid;
	 int sleepTime= rand() % 10 + 1;
	 cout << "Thread ID: " << tid << " going to sleep for "<< sleepTime << endl;
   sleep(sleepTime);
   cout << "Thread ID: " << tid << " woke up" << endl;
   numProcesses--;
	 if(numProcesses==0){
		 hitMaxThreads=false;
	 }
   pthread_exit(NULL);
}

int main () {
	srand (time(NULL));
   pthread_t threads[NUM_THREADS];
   int i;
   for(i = 0; i < NUM_THREADS; i++ ) {
   	  if(canStartProcesses()){
				cout << "Creating thread: " <<  i << endl;
				pthread_create(&threads[i], NULL, executeProcess, (void *)i);
     	 numProcesses++;
			 if (numProcesses==MAX_THREADS){
				 hitMaxThreads=true;
			 }
   	  }
   	  else{
				//cout << "to many threads to start thread: " << i << endl;
				pthread_join(threads[i-1], NULL);
				pthread_join(threads[i-2], NULL);
				pthread_join(threads[i-3], NULL);
				cout << "threads joined moving on " << i << endl;
				//sleep(1);
				i--;

   	  }

   }
   pthread_join(threads[NUM_THREADS-1], NULL);
	 //sleep(10);
	 //cout << "Doneskis" << endl;
	 return 0;
}
