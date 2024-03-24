class Solution {
    #define ll long long
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        // create map using id as key and its freq as value
        // create set using freq as first and key as second of a pair
        int n = nums.size();
        map<int,ll> mp;
        set<pair<ll,ll>> s;
        vector<ll> ans;
        for(int i = 0 ; i < n ; i++){
            ll old = mp[nums[i]];
            mp[nums[i]] += freq[i];
            s.insert({mp[nums[i]], nums[i]});
            auto it = s.find({old,nums[i]});
            if(it != s.end()){
                s.erase(it);
            }
            pair<ll,ll> p=  *s.rbegin();
            ans.push_back(p.first);
        }

        return ans;
    }
};