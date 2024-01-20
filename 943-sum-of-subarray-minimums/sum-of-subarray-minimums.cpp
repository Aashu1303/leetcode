long long mod = 1e9 + 7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        int n = arr.size();
        vector<int> left(n,-1) , right(n,n);
        stack<int> s , st;
        for(int i = 0 ; i < n ;  i++){
            while((!s.empty()) && (arr[s.top()] >= arr[i])){
                s.pop();
            }
            if(!s.empty()){
                left[i] = s.top();
            }
            s.push(i);
        } 
        for(int i=n-1 ; i >= 0 ;  i--){
            while((!st.empty()) && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i] = st.top();
            }
            st.push(i);
        } 

        for(long long i = 0 ; i < n ; i++){
            ans += static_cast<long long>((i - left[i]) * (right[i] - i) * arr[i]) % mod;
            ans = ans % mod;
        }

        return ans;
    }
};