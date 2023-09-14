class Solution {
public:
    
    int recursive(vector<vector<vector<int>>>& dp,vector<int>& nums,int i,int j,int turn){
        if(i>j) return 0;
        if(dp[i][j][turn]!=-1) return dp[i][j][turn];
        int ans;
        if(turn==0){
            ans=max(nums[i]+recursive(dp,nums,i+1,j,1),nums[j]+recursive(dp,nums,i,j-1,1));
        }
        else{
            ans=min(-nums[i]+recursive(dp,nums,i+1,j,0),-nums[j]+recursive(dp,nums,i,j-1,0));
        }
        return dp[i][j][turn]=ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(2,-1)));
        int ans=recursive(dp,nums,0,nums.size()-1,0);
        return ans>=0;
    }
};