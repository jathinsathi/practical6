#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum number of scalar multiplications
int matrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1; // Number of matrices
    
    // dp[i][j] stores the minimum multiplication cost for matrices from Mi to Mj
    // Tables are 1-indexed to match standard algorithmic convention
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // l is the chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            // Try all possible split points k between i and j-1
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // The result for multiplying the full chain from matrix 1 to n
    return dp[1][n];
}

int main() {
    // Example: 3 matrices with dimensions:
    // M1: 10 x 20
    // M2: 20 x 30
    // M3: 30 x 40
    vector<int> arr = {10, 20, 30, 40};
    
    int minOps = matrixChainOrder(arr);
    
    cout << "Minimum number of multiplications is: " << minOps << endl;
    
    return 0;
}
