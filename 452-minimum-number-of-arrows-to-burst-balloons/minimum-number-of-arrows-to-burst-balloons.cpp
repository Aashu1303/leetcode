class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = points.size();
        sort(points.begin(),points.end());
        vector<int> v = points[0];
        vector<vector<int>> ans;
        for(int i = 1 ; i < n ; i++){
            vector<int> temp = points[i];
            if(v[0] <= temp[0] && v[1] >= temp[0]){
                v[0] = max(temp[0] , v[0]);
                v[1] = min(temp[1] , v[1]);
            }else{
                ans.push_back(v);
                v = temp;
            }
        }

        ans.push_back(v);

        // for(auto i : ans) {
        //     cout << i[0] << " " << i[1] << endl;
        // }

        return ans.size();
    }
};