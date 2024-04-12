class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        stack<int> st;
        // take minimum of current maximum and prevMax
        for(int i = 0 ; i < height.size() ; i++){
            while(!st.empty() && height[st.top()] < height[i]){
                int top = st.top();
                st.pop();
                if(st.empty()) break;
                int second = st.top();
                int h = min((height[i] - height[top]) , (height[second] - height[top]));
                int w = i-second-1;
                ans +=h * w;   
            }
            st.push(i);
        }
        return ans;
    }
};