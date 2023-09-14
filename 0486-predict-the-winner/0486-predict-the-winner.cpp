class Solution {
public:
    
    int recursive(vector<vector<int>>& dp,vector<int>& nums,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans;
        
        ans=max(nums[i]-recursive(dp,nums,i+1,j),nums[j]-recursive(dp,nums,i,j-1));
       
        return dp[i][j]=ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        int ans=recursive(dp,nums,0,nums.size()-1);
        return ans>=0;
    }
};