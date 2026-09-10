#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the minimum number of coins
int getMinCoins(const vector<int>& coins, int amount) {
    // Create a DP array initialized with a value greater than the target amount
    vector<int> dp(amount + 1, amount + 1);
    
    // Base case: 0 coins are needed to make an amount of 0
    dp[0] = 0;
    
    // Compute minimum coins for every sub-amount from 1 to 'amount'
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    // If dp[amount] wasn't updated, the amount cannot be formed
    return dp[amount] > amount ? -1 : dp[amount];
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
    
    int result = getMinCoins(coins, targetAmount);
    
    if (result == -1) {
        cout << "\nIt is impossible to make change for " << targetAmount << " with the given coins.\n";
    } else {
        cout << "\nMinimum coins required: " << result << "\n";
    }
    
    return 0;
}
