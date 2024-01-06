class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& v) {
        int n = v.size();
        double x = v[0][0] , y = v[0][1] , prev = DBL_MAX;
        if(x != v[1][0]){
            prev = (v[1][1] - y) / (v[1][0] - x);
        }
        for(int i = 2 ; i < n;  i++){
            double curr = DBL_MAX;
            if(v[i][0] != x){
                curr = (v[i][1] - y) / (v[i][0] - x);
            }
            if(curr != prev){
                return false;
            } 
        }
        return true;
    }
};