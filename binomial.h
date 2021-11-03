#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

class BinomialCoefficient {
public:

    int DandCSolution(int n, int k) {
        if (k == 0 || k == n) {
            return 1;
        }
        else {
            return (DandCSolution(n-1, k) + DandCSolution(n-1, k-1));
        }
        return n+k;
    }

    int DynamicSolution(){}

    int Memo(int n, int k) {
        int** dp; // make a temporary lookup table
        dp = new int*[n + 1];
    
        // loop to create table dynamically
        for (int i = 0; i < (n + 1); i++) {
            dp[i] = new int[k + 1];
        }
    
        // nested loop to initialise the table with -1
        for (int i = 0; i < (n + 1); i++) {
            for (int j = 0; j < (k + 1); j++) {
                dp[i][j] = -1;
            }
        }
    
        return binomialCoeffUtil(n, k, dp);
    }

private:

    int binomialCoeffUtil(int n, int k, int** dp) {
        // If value in lookup table then return
        if (dp[n][k] != -1) //    
            return dp[n][k];
    
        // store value in a table before return
        if (k == 0) {
            dp[n][k] = 1;
            return dp[n][k];
        }
        
        // store value in table before return
        if (k == n) {
            dp[n][k] = 1;
            return dp[n][k];
        }
        
        // save value in lookup table before return
        dp[n][k] = binomialCoeffUtil(n - 1, k - 1, dp) +
                binomialCoeffUtil(n - 1, k, dp);
        return dp[n][k];
    }


};

























    // auto start = chrono::high_resolution_clock::now();
    // // unsync the I/O of C and C++.
    // ios_base::sync_with_stdio(false);


    // auto end = chrono::high_resolution_clock::now();
    // // Calculating total time taken by the program.
    // double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // time_taken *= 1e-9;
    // cout << "      " << fixed  << time_taken;




    // auto start = chrono::high_resolution_clock::now(); // Starting timer
    // ios_base::sync_with_stdio(false); // Unsync IO of C and C++

    // int result = computation.DandCSolution(n, k);

    // auto end = chrono::high_resolution_clock::now(); // Ending the timer
    // double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // // time_taken *= 1e-9; // Nano * 10^-9 = seconds

    // cout << "Divide and Conquer(" << n << ", " << k << ") = "<< result <<  "     Time taken: " << fixed << time_taken <<" seconds" << endl; 