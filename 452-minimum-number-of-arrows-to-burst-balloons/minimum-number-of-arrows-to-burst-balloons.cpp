class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = points.size();
        vector<pair<int,int>> p;
        for(auto &i : points){
            p.push_back({i[0],i[1]});
        }
        sort(p.begin(),p.end());
        pair<int,int> v = p[0];
        vector<pair<int,int>> ans;
        for(int i = 1 ; i < n ; i++){
            if(v.first <= p[i].first && v.second >= p[i].first){
                v.first = max(p[i].first , v.first);
                v.second = min(p[i].second , v.second);
            }else{
                ans.push_back(v);
                v = p[i];
            }
        }

        ans.push_back(v);

        // for(auto i : ans) {
        //     cout << i[0] << " " << i[1] << endl;
        // }

        return ans.size();
    }
};