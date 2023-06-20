#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int coinChange(int coins[], int numCoins, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = amount+1;//INT_MAX;
        for (int j = 0; j < numCoins; j++) {
            if (coins[j] <= i) {
                if (dp[i - coins[j]] != INT_MAX) {

                    printf("dp[%d] = min(dp[%d]=%d,dp[%d-%d]+1=%d)\n",i,i,dp[i],i,coins[j],dp[i - coins[j]] + 1);
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        printf("\n");
    }
    
    for(int i = 0;i<amount+1;i++)
    {
        printf("dp[%d]=%d\n",i,dp[i]);
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 2,3,5,7};
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    int amount = 20;

    int result = coinChange(coins, numCoins, amount);
    printf("Minimum number of coins required: %d\n", result);

    return 0;
}