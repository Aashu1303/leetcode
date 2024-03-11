class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        string ans = "";
        for(auto i : s) mp[i]++;

        for(auto i : order){
            if(mp[i] > 0){
                while(mp[i]){
                    ans += i;
                    mp[i]--;
                }
            }
        }

        for(auto i : mp){
            if(i.second > 0){
                while(i.second){
                    ans += i.first;
                    i.second--;
                }
            }
        }

        return ans;
    }
};