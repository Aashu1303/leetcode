class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long ans = 0 , n = nums.size();
        stack<pair<int,int>> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && nums[i] > st.top().first){
                st.pop();
            }
            if(!st.empty() && (nums[i] == st.top().first)){
                int count = st.top().second;
                ans+=count;
                count++;
                st.pop();
                st.push({nums[i] , count});
            }else{
                st.push({nums[i] , 1});
            }
            ans++;
        }

        return ans;
    }
};