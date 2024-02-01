class Solution {
    bool check(int a ,int b , int c , int k){
        if((abs(a-b) <= k) && (abs(b-c) <= k) && (abs(c-a) <= k)) return true;
        return false;
    }
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        if((n % 3) != 0){
            return ans;
        }
        vector<int> temp;
        for(int i = 0 ; i < n; i++){
            if(temp.size() == 3){
                if(!check(temp[0],temp[1],temp[2],k)) return {};
                ans.push_back(temp);
                temp.clear();
            }
            temp.push_back(nums[i]);
        }
        if(!check(temp[0],temp[1],temp[2],k)) return {};
        ans.push_back(temp);
        return ans;
    }
};