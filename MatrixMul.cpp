#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int>& p) {
    int n = p.size() - 1;
  
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] +
                            dp[k + 1][j] +
                            p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n];
}

int main() {
    // Matrices:
    // A1 = 10 x 20
    // A2 = 20 x 30
    // A3 = 30 x 40
    // A4 = 40 x 30
    vector<int> dimensions = {10, 20, 30, 40, 30};

    cout << "Minimum multiplications: "
         << matrixChainMultiplication(dimensions) << endl;

    return 0;
}
