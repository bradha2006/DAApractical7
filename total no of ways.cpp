#include <iostream>
#include <vector>

using namespace std;

// Function to count total unique ways to make change
long long getTotalWays(const vector<int>& coins, int amount) {
    // Create DP array initialized to 0. Use long long to prevent integer overflow.
    vector<long long> dp(amount + 1, 0);
    
    // Base case: There is 1 way to make an amount of 0 (by choosing no coins)
    dp[0] = 1;
    
    // Loop through each coin denomination
    for (int coin : coins) {
        // Update the DP array for all amounts equal to or greater than the current coin
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    
    return dp[amount];
}

int main() {
    int numCoins, targetAmount;
    
    cout << "Enter the number of coin denominations: ";
    cin >> numCoins;
    
    vector<int> coins(numCoins);
    cout << "Enter the coin denominations:\n";
    for (int i = 0; i < numCoins; ++i) {
        cin >> coins[i];
    }
    
    cout << "Enter the target amount: ";
    cin >> targetAmount;
    
    long long result = getTotalWays(coins, targetAmount);
    
    cout << "\nTotal unique ways to make change: " << result << "\n";
    
    return 0;
}
