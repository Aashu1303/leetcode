class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxE = *max_element(nums.begin(),nums.end());
        if(maxE <= 0) return 1;

        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i = 0 ; i < nums.size() ; i++){
            pq.push(nums[i]);
        }


        int ans = 1;
        while(!pq.empty() && pq.top() <= ans){
            if(pq.top() == ans) ans++;
            pq.pop();
        }

        return ans;
    }
};