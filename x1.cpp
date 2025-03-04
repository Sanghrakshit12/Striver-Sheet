#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coins(vector<int>& input, int amount, vector<vector<int>>& dp, int i) {
    if (amount == 0) return 0;  // Base case: no coins needed to make amount 0
    if (amount < 0 || i >= input.size()) return -1; // Invalid case

    // Check if the result is already computed
    if (dp[i][amount] != -2) return dp[i][amount];

    // Include the current coin
    int take = coins(input, amount - input[i], dp, i);
    // Exclude the current coin
    int notTake = coins(input, amount, dp, i + 1);

    // Determine the best option
    if (take == -1 && notTake == -1) {
        dp[i][amount] = -1;  // Cannot make the amount
        return -1;
    }
    if (take == -1) return dp[i][amount] = notTake; // Only notTake is valid
    if (notTake == -1) return dp[i][amount] = take + 1; // Only take is valid

    // Return the minimum coins needed
    return dp[i][amount] = min(take + 1, notTake);
}

int main() {
    int n;
    cout << "Enter the number of denominations: ";
    cin >> n;

    vector<int> input(n);
    cout << "Enter the denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    vector<vector<int>> dp(n, vector<int>(amount + 1, -2));
    
    int result = coins(input, amount, dp, 0);
    
    if (result != -1) {
        cout << "Minimum coins needed: " << result << endl;
    } else {
        cout << "Cannot make the amount with the given coins." << endl;
    }

    return 0;
}
