typedef vector<vector<bool>> vvb;
class Solution {
public:
    void dfs(vvb &poss, int m, int n, vector<vector<int>>& heights, int i,int j){
        if(i>=m or i<0 or j>=n or j<0 or poss[i][j]==true){
            return;
        }
        poss[i][j] = true;
        
        if((i+1)<m and heights[i][j]<=heights[i+1][j]){
            dfs(poss,m,n,heights,i+1,j);
        }
        if((j+1)<n and heights[i][j]<=heights[i][j+1]){
            dfs(poss,m,n,heights,i,j+1);
        }
        if((i-1)>=0 and heights[i][j]<=heights[i-1][j]){
            dfs(poss,m,n,heights,i-1,j);
        }
        if((j-1)>=0 and heights[i][j]<=heights[i][j-1]){
            dfs(poss,m,n,heights,i,j-1);
        }
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vvb possiblep(m,vector<bool>(n,false));
        vvb possiblea(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            dfs(possiblep,m,n,heights,i,0);
        }
        for(int j=0;j<n;j++){
            dfs(possiblep,m,n,heights,0,j);
        }
        for(int i=0;i<m;i++){
            dfs(possiblea,m,n,heights,i,n-1);
        }
        for(int j=0;j<n;j++){
            dfs(possiblea,m,n,heights,m-1,j);
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(possiblep[i][j] and possiblea[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
