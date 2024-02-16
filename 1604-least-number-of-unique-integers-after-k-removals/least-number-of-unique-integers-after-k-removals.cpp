class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto i : arr){
            mp[i]++;
        } 
        vector<int> freq;
        for(auto i : mp) freq.push_back(i.second);
        int n = freq.size();
        sort(freq.begin() , freq.end());
        int i = 0;
        while(k--){
            freq[i]--;
            if(freq[i] == 0) i++;
        }

        return n-i;
    }
};