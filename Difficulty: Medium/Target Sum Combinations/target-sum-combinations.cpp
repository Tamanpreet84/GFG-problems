class Solution {
  public:
  
  vector<vector<int>> ans;
  
  void helper(vector<int> &arr,int t, vector<int>psf,int start){
  
  if(t<0) return;
  
  if(t==0){
      ans.push_back(psf);
      return;
  }
  for(int i=start;i<arr.size();i++){
      
      psf.push_back(arr[i]);
      helper(arr,t-arr[i],psf,i);
      psf.pop_back();
  }
  
  }
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
       ans.clear();
       helper(arr,target,{},0);
       return ans;
        
        
    }
};