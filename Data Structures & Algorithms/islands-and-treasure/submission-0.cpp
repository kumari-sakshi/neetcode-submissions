class Solution {
public:
   
    void dfs(int x ,int y, vector<vector<int>>& vis,vector<vector<int>>& grid, int dis)
    {
        grid[x][y]=dis;
        vis[x][y]=1;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        for(int i=0;i<4;i++)
        {
            int x1=x+dx[i];
            int y1=y+dy[i];

            if(x1>=0 && x1<grid.size()&& y1>=0 && y1<grid[0].size()  && grid[x1][y1]!= -1 && grid[x1][y1]!= 0)
            {   if(!vis[x1][y1] || grid[x1][y1]>dis+1)
                dfs(x1,y1,vis,grid,dis+1);
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int INF= 2^31-1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==0)
                {
                    dfs(i,j,vis,grid,0);
                }
            }
        }
        return ;
        
    }
};
