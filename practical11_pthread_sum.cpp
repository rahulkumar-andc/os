// ==============================================================================
// UNIVERSITY OF DELHI - OPERATING SYSTEMS PRACTICAL LAB (GE / PME)
// PRACTICAL 11
//
// QUESTION:
// Write a program to calculate sum of n numbers using Pthreads.
// (Multi-threaded sum computation with mutex synchronization)
// ==============================================================================

#include <iostream>
#include <vector>
#include <pthread.h>

using namespace std;

struct ThreadData {
    int thread_id;
    int start_idx;
    int end_idx;
    const vector<int>* arr;
};

// Global shared variables
long long total_sum = 0;
pthread_mutex_t sum_mutex = PTHREAD_MUTEX_INITIALIZER;

void* computePartialSum(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);
    long long local_sum = 0;

    for (int i = data->start_idx; i <= data->end_idx; i++) {
        local_sum += (*(data->arr))[i];
    }

    // Critical Section protected by Mutex
    pthread_mutex_lock(&sum_mutex);
    total_sum += local_sum;
    cout << "[Thread " << data->thread_id << "] Summed range [" 
         << data->start_idx << " - " << data->end_idx << "] -> Partial Sum = " 
         << local_sum << " | Current Total = " << total_sum << endl;
    pthread_mutex_unlock(&sum_mutex);

    pthread_exit(nullptr);
}

int main() {
    cout << "==========================================================" << endl;
    cout << "        MULTITHREADED SUM COMPUTATION USING PTHREADS      " << endl;
    cout << "==========================================================" << endl;

    int n = 8;
    int num_threads = 2;
    vector<int> numbers = {10, 20, 30, 40, 50, 60, 70, 80};

    cout << "Array size (N) : " << n << endl;
    cout << "Numbers        : ";
    for (int x : numbers) cout << x << " ";
    cout << endl;
    cout << "Threads used   : " << num_threads << endl;
    cout << string(58, '-') << endl;

    vector<pthread_t> threads(num_threads);
    vector<ThreadData> tdata(num_threads);

    int chunk = n / num_threads;
    for (int i = 0; i < num_threads; i++) {
        tdata[i].thread_id = i + 1;
        tdata[i].start_idx = i * chunk;
        tdata[i].end_idx = (i == num_threads - 1) ? (n - 1) : ((i + 1) * chunk - 1);
        tdata[i].arr = &numbers;

        pthread_create(&threads[i], nullptr, computePartialSum, &tdata[i]);
    }

    // Wait for all threads to finish execution
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], nullptr);
    }

    pthread_mutex_destroy(&sum_mutex);

    cout << string(58, '-') << endl;
    cout << "FINAL AGGREGATED SUM = " << total_sum << endl;
    cout << "==========================================================" << endl;

    return 0;
}
