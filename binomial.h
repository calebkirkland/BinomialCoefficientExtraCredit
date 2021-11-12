#include <cstring>
#include <algorithm>
#include <iostream>

class BinomialCoefficient {
public:

    int DandCAlgorithm(int n, int k) {
        if (k == 0 || k == n) {
            return 1;
        }
        else {
            return (DandCAlgorithm(n-1, k) + DandCAlgorithm(n-1, k-1));
        }
        return n+k;
    }

        int DynamicAlgorithm(int n, int k) {
        if (k == 0 || k == n) {
            return 1;
        }
        else {
            return DynamicAlgorithm(n-1,k-1) + DynamicAlgorithm(n-1,k);
        }
    }

    int MemoAlgorithm(int n, int k) {
        int coef[k+1];
        memset(coef, 0, sizeof(coef));
        coef[0] = 1;
        
        for(int i = 1; i <= n; i++){
            for (int j = std::min(i, k); j > 0; j--){
                coef[j] = (coef[j] + coef[j-1]);
            }
        }
        return coef[k];
    }
};