class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> s1,s2;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > 0){
                s1.push(i);
            }else{
                s2.push(i);
            }
        }
        vector<int> ans;
        ans.push_back(nums[s1.front()]);
        s1.pop();
        bool f = true;
        while(!s2.empty()){
            if(f){
                ans.push_back(nums[s2.front()]);
                s2.pop();
                f = false;
            }else{
                ans.push_back(nums[s1.front()]);
                s1.pop();
                f = true;
            }
        }

        while(!s1.empty()){
            ans.push_back(nums[s1.front()]);
            s1.pop();
        }

        return ans;
    }
};