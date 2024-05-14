class Solution {
    int solve(vector<vector<int>> &grid , int i , int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;
        if(grid[i][j] == 0) return 0;
        int curr = grid[i][j];
        grid[i][j] = 0;   
        int down = solve(grid , i+1 , j);
        int up = solve(grid , i-1 , j );
        int right = solve(grid , i , j+1 );
        int left = solve(grid , i , j-1);
        grid[i][j] = curr;
        return curr + max({left , right, up , down});
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]) ans = max(ans , solve(grid , i , j));
            }
        }
        return ans;
    }
};