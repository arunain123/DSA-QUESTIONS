class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
         priority_queue<  pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
         int maxi=-1e9;
         
         for(int i=0;i<nums.size();i++){ maxi=max(maxi,nums[i][0]);pq.push({nums[i][0],{i,0}});}
        
        int ans=1e9;
        int a=-1e4;
        int b=1e4;
        
        
        
        
        while(!pq.empty()){
            int mini=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(maxi-mini<ans){ a=mini;b=maxi; ans=maxi-mini;}
            if(j+1==nums[i].size()) return {a,b};
            maxi=max(maxi,nums[i][j+1]);
            pq.push({nums[i][j+1],{i,j+1}});
                
            }
        
        
         return {a,b};
        }
//         while(true){
//             int mini=1e6;
//             int ind1=-1;
            
//             int maxi=-1e6;
//             int ind2=-1;
//             for(int i=0;i<nums.size();i++){
//                 if(t[i]>=nums[i].size()) return {a,b};
//                 if(ind1==-1 || nums[i][t[i]]<mini){
//                     mini=nums[i][t[i]];
//                     ind1=i;
//                 }
                
//                 if(ind2==-1 || nums[i][t[i]]>maxi){
//                     maxi=nums[i][t[i]];
//                     ind2=i;
//                 }
                
                
//             }
            
//             if(ind1!=-1 && ind2!=-1){  if(maxi-mini<ans){ans=maxi-mini;a=mini;b=maxi;} t[ind1]++;}
//             else break;
            
//         }
        
       
        
    
};