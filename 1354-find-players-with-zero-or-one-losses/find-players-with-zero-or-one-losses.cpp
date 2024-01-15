class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& v) {
        vector<vector<int>> ans(2);
        map<int,pair<int,int>> mp;
        // pair<win,loss>;
        for(int i = 0 ; i < v.size() ; i++){
            mp[v[i][0]].first++;
            mp[v[i][1]].second++;
        }

        for(auto i : mp){
            if(i.second.second == 0) ans[0].push_back(i.first);
            else if(i.second.second == 1) ans[1].push_back(i.first);
        }

        return ans;
    }
};