class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        ans.push_back({rStart,cStart});
        int n = 0 , y = 0 , x = 1;
        while(ans.size() < (rows*cols)){
            for(int i = 0 ; i < n/2 + 1 ; i++){
                rStart += y , cStart += x;
                if(0 <= rStart && rStart < rows && 0 <= cStart && cStart < cols){
                    ans.push_back({rStart,cStart});
                } 
            }
            int temp = y;
            y = x , x = -temp;
            n++;
        }

        return ans;
    }   
};