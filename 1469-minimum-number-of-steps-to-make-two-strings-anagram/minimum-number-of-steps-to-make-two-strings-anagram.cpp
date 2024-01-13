class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp1 , mp2;
        for(auto c : s) mp1[c]++;
        for(auto c : t) mp2[c]++;
        int count = 0 ;
        for(auto i : mp1){
            if(i.second > mp2[i.first]) count += (i.second - mp2[i.first]);
        }

        return count;
    }
};