class Solution {
  public:
  vector<int> weight;
  vector<int> value;
  int dp[1001][1001];
  int knap(int w,int n){
      if(n==0 or w==0){
          return 0;
          
      }
      if(dp[w][n]!=-1){
          return dp[w][n];
      }
      if(w>=weight[n-1]){
          int take=knap(w-weight[n-1],n-1)+value[n-1];
          int dtake=knap(w,n-1);
          return dp[w][n]=max(take,dtake);
      }
      else{
          return dp[w][n]=knap(w,n-1);
      }
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        weight=wt;
        value=val;
        int n=val.size();
        memset(dp,-1,sizeof(dp));
        return knap(W,n);
        
        
    }
};