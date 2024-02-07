class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto i : s){
            mp[i]++;
        }
        vector<pair<int,char>>p;
        for(auto i : mp){
            p.push_back(make_pair(i.second , i.first));
        }
        sort(p.begin() , p.end());
        string ans;
        for(auto i : p){
            int n = i.first;
            while(n--){
                ans.push_back((i.second));
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};