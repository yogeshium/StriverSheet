class Solution {
    // Recursion
    /*
    int solve(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=INT_MAX, left=INT_MAX;
        //up
        if(i-1>=0)
            up=min(up,solve(i-1,j,grid,dp));
        //left
        if(j-1>=0)
            left=min(left,solve(i,j-1,grid,dp));

        return dp[i][j]=grid[i][j]+min(up,left);
    }
    */
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // Recursion
        /*
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
        */

        // tabulation
        /*
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else {
                    int up=0,left=0;
                    // up
                    if (i - 1 >= 0)
                        up=dp[i - 1][j];
                    else
                        up=INT_MAX;
                    // left
                    if (j - 1 >= 0)
                        left = dp[i][j - 1];
                    else
                        left=INT_MAX;

                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
        */

        //space optimization
        vector<int> prevRow(n,0);
        vector<int> curr(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=grid[i][j];
                else{
                    int up=0,left=0;
                    // up
                    if (i - 1 >= 0)
                        up=prevRow[j];
                    else
                        up=INT_MAX;
                    // left
                    if (j - 1 >= 0)
                        left=curr[j-1];
                    else
                        left=INT_MAX;

                    curr[j] = grid[i][j] + min(up, left);
                }
                prevRow=curr;
            }
        }
        return curr[n-1];
    }
};
