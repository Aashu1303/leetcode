class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1) return 1;
        unordered_map<int,int> t , nt;
        for(auto i : trust){
            t[i[0]]++;
            nt[i[1]]++;
        }

        for(auto i : nt){
            if(i.second == n-1 && (t[i.first] == 0)){
                return i.first;
            }
        }

        return -1;
    }
};