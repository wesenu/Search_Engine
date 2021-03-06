//
//  main.cpp
//  Pthread_tst
//
//  Created by Elahe on 12/21/15.
//  Copyright (c) 2015 Elahe & Amineh. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <pthread.h>


#include <unistd.h>
using namespace std;

//#define NUM_THREADS     5
//
//void *PrintHello(void *threadid)
//{
//    long tid;
//    tid = (long)threadid;
//    cout << "Hello World! Thread ID, " << tid << endl;
//    pthread_exit(NULL);
//}
//
//int main ()
//{
//    pthread_t threads[NUM_THREADS];
//    int rc;
//    int i;
//    for( i=0; i < NUM_THREADS; i++ ){
//        cout << "main() : creating thread, " << i << endl;
//        rc = pthread_create(&threads[i], NULL,
//                            PrintHello, (void *)i);
//        if (rc){
//            cout << "Error:unable to create thread," << rc << endl;
//            exit(-1);
//        }
//    }
//    pthread_exit(NULL);
//}

#define NUM_THREADS     5

void *wait(void *t)
{
    int i;
    long tid;
    
    tid = (long)t;
    
    sleep(1);
    cout << "Sleeping in thread " << endl;
    cout << "Thread with id : " << tid << "  ...exiting " << endl;
    pthread_exit(NULL);
}

int main ()
{
    int rc;
    int i;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    void *status;
    
    // Initialize and set thread joinable
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    for( i=0; i < NUM_THREADS; i++ ){
        cout << "main() : creating thread, " << i << endl;
        rc = pthread_create(&threads[i], NULL, wait, (void *)i );
        if (rc){
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    
    // free attribute and wait for the other threads
    pthread_attr_destroy(&attr);
    for( i=0; i < NUM_THREADS; i++ ){
        rc = pthread_join(threads[i], &status);
        if (rc){
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
        }
        cout << "Main: completed thread id :" << i ;
        cout << "  exiting with status :" << status << endl;
    }
    
    cout << "Main: program exiting." << endl;
    pthread_exit(NULL);
}