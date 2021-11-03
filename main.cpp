#include "binomial.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

void DandC (int n, int k) {
    BinomialCoefficient computation;
 
    auto t1 = high_resolution_clock::now();
    int result = computation.DandCSolution(n, k);
    auto t2 = high_resolution_clock::now();

    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;
    cout << "Divide and Conquer(" << n << ", " << k << ") = "<< result << "    Time Taken: " << ms_double.count() << " ms" << endl;
}

void Memo (int n, int k) {
    BinomialCoefficient computation;

    auto t1 = high_resolution_clock::now();
    int result = computation.Memo(n, k);
    auto t2 = high_resolution_clock::now();

    auto ms_int = duration_cast<milliseconds>(t2 - t1);
    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;
    cout << "Memo(" << n << ", " << k << ") = " << result << "    Time Taken: " << ms_double.count() << " ms" << endl;
}


int main() {
    DandC(42,4);
    Memo(42, 4);


    return 0;
}