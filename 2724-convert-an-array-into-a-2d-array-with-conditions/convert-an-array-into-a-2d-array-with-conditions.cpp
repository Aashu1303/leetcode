class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1 , 0);
        for(int i = 0 ; i <  n ; i++){
            freq[nums[i]]++;
        }
        int maxm = *max_element(freq.begin() , freq.end());
        cout << maxm << endl;
        vector<vector<int>> ans(maxm);
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            ans[mp[nums[i]]].push_back(nums[i]);
            mp[nums[i]]++;
        }

        return ans;
    }
};