class Solution {
public:
void dfs(int x,int y,vector<vector<int>>& heights,vector<vector<int>>& vis){

   vis[x][y]=1;
   int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    for(int i=0;i<4;i++)
    {
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>=0 && x1<heights.size() && y1>=0 && y1<heights[0].size())
        {
            if(!vis[x1][y1] && heights[x][y]<=heights[x1][y1])
            dfs(x1,y1,heights,vis);
        }
    }

}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> pacific(n,vector<int>(m,0));
         vector<vector<int>> atlantic(n,vector<int>(m,0));

         for(int i=0;i<m;i++)
         dfs(0,i,heights,pacific);

         for(int i=0;i<n;i++)
         dfs(i,0,heights,pacific);

         for(int i=0;i<m;i++)
          dfs(n-1,i,heights,atlantic);

           for(int i=0;i<n;i++)
          dfs(i,m-1,heights,atlantic);   

          vector<vector<int>> v;
          for(int i=0;i<n;i++)
          {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] &&atlantic[i][j])
                v.push_back({i,j});
            }
          }  

          return v;     
    }
};
