class Solution {
public:
    bool isSubsetSum(vector<int>& st, int sum) {

        int n = st.size();
        bool dp[n+1][sum+1];

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {

                if(j == 0) {
                    dp[i][j] = 1;
                    continue;
                }

                
                if(i == 0) {
                    dp[i][j] = 0;
                    continue;
                }

                if(j >= st[i-1]) {

                    bool take = dp[i-1][j-st[i-1]];
                    bool dtake = dp[i-1][j];

                    dp[i][j] = take || dtake;
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }
};