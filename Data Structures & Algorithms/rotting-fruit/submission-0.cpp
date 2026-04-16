class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size();
        int m= grid[0].size();

        queue<pair<int , pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    pq.push({0,{i,j}});
                }
            }
        }
        int maxm=0;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!pq.empty())
        {
            auto temp =pq.front();
            pq.pop();
            int time =temp.first;
            int x=temp.second.first;
            int y=temp.second.second;
             
           maxm= max(maxm,time);

            for(int i=0;i<4;i++)
            {
                int x1 =x+dx[i];
                int y1 =y+dy[i];

                if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1]==1)
                {
                    grid[x1][y1]=2;
                    pq.push({time+1 ,{x1,y1}});
                }

            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }

        return maxm;
        
    }
};
