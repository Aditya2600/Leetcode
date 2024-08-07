class Solution {
public:
    /*int helper(vector<int>& coins, int amount, vector<int> &dp){
        
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        if(dp[amount] != -2) return dp[amount];
        int ans = INT_MAX; 
        for(int i=0; i<coins.size(); i++){
            int res = min(helper(coins,amount - coins[i],dp),ans);
            if(res >= 0 && res < ans){
                ans = 1 + res;
            }
        }
        dp[amount] = (ans == INT_MAX) ? -1 : ans;
        return dp[amount];
    }*/


    int coinChange(vector<int>& coins, int amount) {
         vector<int> dp(amount + 1,amount + 1);
         dp[0] = 0;
         for(int i=1; i<= amount; i++){
            for(auto coin : coins){
                if(i - coin >= 0){
                    dp[i] = min(dp[i],dp[i-coin] + 1);
                }
            }
         }
         return dp[amount] > amount ? -1 : dp[amount];
    }
};