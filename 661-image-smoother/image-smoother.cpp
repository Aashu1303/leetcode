class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row = img.size(), col = img[0].size();
        vector<vector<int>> ans(row,vector<int> (col , 0));
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                int count = 0;
                for(int nr = i-1; nr <= i+1; ++nr){
                    for(int nc = j-1 ; nc <= j+1 ; ++nc){
                        if(nr >= 0 && nr < row && nc >= 0 && nc < col){
                            ans[i][j] += img[nr][nc];
                            count ++; 
                        }
                    }
                }
                ans[i][j] /= count;
            }
        }
        return ans;
    }
};