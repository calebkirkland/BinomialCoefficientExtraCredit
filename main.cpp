// Caleb Kirkland
// Intro to Algorithms Extra Credit 2
// 11/3/21
// Made with Visual Studio Code and GCC

#include "binomial.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

void DandC (int n, int k) {
    BinomialCoefficient computation;

    auto start = chrono::steady_clock::now(); // Starting timer
    ios_base::sync_with_stdio(false); // Unsync IO of C and C++

    int result = computation.DandCAlgorithm(n, k);

    auto end = chrono::steady_clock::now(); // Ending the timer
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9; // Nano * 10^-9 = seconds

    cout << "Divide and Conquer(" << n << ", " << k << ") = "<< result <<  "     Time taken: " << fixed << time_taken << " seconds" << endl; 
}

void Memo (int n, int k) {
    BinomialCoefficient computation;

    auto start = chrono::steady_clock::now(); // Starting timer
    ios_base::sync_with_stdio(false); // Unsync IO of C and C++

    int result = computation.MemoAlgorithm(n, k);

    auto end = chrono::steady_clock::now(); // Ending the timer
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9; // Nano * 10^-9 = seconds

    cout << "Memoization(" << n << ", " << k << ")        = "<< result <<  "     Time taken: " << fixed << time_taken << " seconds" << endl; 
}

void DynamicProgramming(int n, int k) {
    BinomialCoefficient computation;

    auto start = chrono::steady_clock::now(); // Starting timer
    ios_base::sync_with_stdio(false); // Unsync IO of C and C++

    int result = computation.DynamicProgrammingAlgorithm(n, k);

    auto end = chrono::steady_clock::now(); // Ending the timer
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9; // Nano * 10^-9 = seconds

    cout << "Dynamic Programming(" << n << ", " << k << ")        = "<< result <<  "     Time taken: " << fixed << time_taken << " seconds" << endl; 

}

int main() {

    DandC(52, 5);
    Memo(52, 5);

    return 0;
}