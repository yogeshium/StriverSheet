class Solution {
    // recursion
    /*
    int solve(int i,int j, vector<vector<int>>& tri){
        if(i==0) return tri[0][0];
        //up
        int top=INT_MAX;
        if(tri[i-1].size()!=j)
            top=solve(i-1,j,tri);

        //up-left
        int topLeft=INT_MAX;
        if(j-1>=0)
            topLeft=min(topLeft,solve(i-1,j-1,tri));

        return tri[i][j]+min(top,topLeft);
    }
    */
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // recursion
        /*
        int ans=INT_MAX;
        for(int j=0;j<triangle[m-1].size();j++)
            ans=min(ans,solve(m-1,j,triangle));
        return ans;
        */

        // tabulation
        /*
        vector<vector<int>> dp(m, vector<int>(triangle[m - 1].size(), 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = triangle[i][j];
                else {
                    // up
                    int top = INT_MAX;
                    if (triangle[i - 1].size() != j)
                        top = dp[i - 1][j];

                    // up-left
                    int topLeft = INT_MAX;
                    if (j - 1 >= 0)
                        topLeft = dp[i - 1][j - 1];
                    
                    dp[i][j]=triangle[i][j]+min(top,topLeft);
                }
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<triangle[m-1].size();j++){
            ans=min(ans,dp[m-1][j]);
        }
        return ans;
        */

        //Space Optimization
        vector<int> prevRow(triangle[m-1].size(),0);
        vector<int> curr(triangle[m-1].size(),0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i == 0 && j == 0)
                    curr[j] = triangle[i][j];
                else {
                    // up
                    int top = INT_MAX;
                    if (triangle[i - 1].size() != j)
                        top = prevRow[j];

                    // up-left
                    int topLeft = INT_MAX;
                    if (j - 1 >= 0)
                        topLeft = prevRow[j - 1];
                    
                    curr[j]=triangle[i][j]+min(top,topLeft);
                }
            }
            prevRow=curr;
        }
        int ans=INT_MAX;
        for(int j=0;j<triangle[m-1].size();j++){
            ans=min(ans,curr[j]);
        }
        return ans;
    }
};
