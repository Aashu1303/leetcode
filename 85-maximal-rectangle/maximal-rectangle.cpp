class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n == 0 || m == 0) return 0;
        vector<vector<int>> v(n+1 , vector<int>(m+1,0));
        for(int i = 0 ; i < m ; i++){
            if(matrix[0][i] == '1') v[0][i]++;
        }
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(matrix[i][j] == '1'){
                    v[i][j] += (v[i-1][j] + 1);
                }
            }
        }
        // for(auto i : v){
        //     for(auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            stack<int> st;
            for(int j = 0 ;  j < m+1 ; j++){
                while(!st.empty() && v[i][j] < v[i][st.top()]){
                    int h = v[i][st.top()];
                    st.pop();
                    int w = st.empty() ? j : j-st.top()-1;
                    ans = max(ans , h*w);
                }
                st.push(j);
            }
        }
        return ans;
    }
};