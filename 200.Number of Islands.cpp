class Solution {
public:
    void set_water(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == '0') 
            return ;
        grid[i][j] = '0';
        set_water(grid, i - 1, j);
        set_water(grid, i + 1, j);
        set_water(grid, i, j - 1);
        set_water(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ans += 1;
                    set_water(grid, i, j);
                }
            }
        }
        return ans;
    }
};