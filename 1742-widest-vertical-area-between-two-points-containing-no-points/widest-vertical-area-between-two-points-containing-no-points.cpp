class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin() , points.end());
        int prevx = points[0][0];
        int prevy = points[0][1];
        int ans = 0;
        for(int i = 1 ; i < points.size() ; i++){
            int currx = points[i][0];
            int curry = points[i][1];
            if(prevx != currx){
                ans = max(ans , currx - prevx);
                if(prevy != curry){
                    prevx = currx;
                    prevy = curry;
                }
            }
        }        

        return ans;
    }
};