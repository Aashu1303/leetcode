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
            if(prevx == currx){
                continue;
            }else{
                if(prevy != curry){
                    ans = max(ans , currx - prevx);
                    prevx = currx;
                    prevy = curry;
                }else{
                    ans = max(ans , currx - prevx);
                }
            }
        }        

        return ans;
    }
};