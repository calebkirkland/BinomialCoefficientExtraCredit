#include "binomial.h"
#include <chrono>
#include <iostream>

using namespace std::chrono;
using std::cout;
using std::endl;
using std::fixed;

void DandC (int n, int k) {
    BinomialCoefficient computation;

    auto start = std::chrono::high_resolution_clock::now(); // Starting timer
    std::ios_base::sync_with_stdio(false); // Unsync IO of C and C++

    int result = computation.DandCAlgorithm(n, k);

    auto end = std::chrono::high_resolution_clock::now(); // Ending the timer
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); // Putting the time value in a double
    time_taken *= 1e-9; // Nano * 10^-9 = seconds

    std::cout << "Divide and Conquer(" << n << ", " << k << ") = "<< result <<  "     Time taken: " << fixed << time_taken << " seconds" << endl; 
}

void Dynamic(int n, int k) {
    BinomialCoefficient computation;

    auto start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);

    unsigned int result = computation.DynamicAlgorithm(n, k);

    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Dynamic Programming(" << n << ", " << k << ")     = "<< result <<  "     Time taken: " << fixed << time_taken << " seconds" << endl; 
}

void Memo (int n, int k) {
    BinomialCoefficient computation;

    auto start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);

    int result = computation.MemoAlgorithm(n, k);

    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    cout << "Memoization(" << n << ", " << k << ")        = "<< result <<  "     Time taken: " << fixed << time_taken << " seconds" << endl; 
}

int main() {

    DandC(52, 5);
    Dynamic(52, 5);
    Memo(52, 5);

    return 0;
}