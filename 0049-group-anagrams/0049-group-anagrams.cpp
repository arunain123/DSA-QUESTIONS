class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mp;
        
        for(int i=0;i<strs.size();i++){
            vector<int> vis(26,0);
            for(int j=0;j<strs[i].size();j++){
                vis[strs[i][j]-'a']++;
            }
            mp[vis].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto v: mp){
            vector<string> temp;
            for(auto u:v.second){
                temp.push_back(u);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};