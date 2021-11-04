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

    int DynamicProgrammingAlgorithm(int n, int k){}
    
    int MemoAlgorithm(int n, int k) {
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