class Solution {
public:
    bool judgeSquareSum(int c) {
        ios::sync_with_stdio(false);
        long long x = sqrt(c) + 1;
        vector<long long> temp;
        for(long long i = 0 ; i <= x ; i++){
            temp.push_back(i*i);
        }

        map<long long , int> mp;
        for(int i = 0 ; i < temp.size() ; i++){
            long long target = c - temp[i];
            if((target >= 0 && mp[target] > 0) || (2LL * temp[i] == c)){
                return true;
            }
            mp[temp[i]]++;
        }
        return false;
    }
};