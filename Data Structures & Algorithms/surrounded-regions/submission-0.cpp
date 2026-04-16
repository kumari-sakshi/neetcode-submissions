class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n= board.size();
        int m =board[0].size();
       
       queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')
            q.push({0,i});
            if(board[n-1][i]=='O')
            q.push({n-1,i});
            
        }

        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            q.push({i,0});
            if(board[i][m-1]=='O')
            q.push({i,m-1});
        }
       
       int dx[4]={1,-1,0,0};
       int dy[4]={0,0,1,-1};
        while(!q.empty())
        {
           auto temp=q.front();
           q.pop();
           int x=temp.first;
           int y=temp.second;
          
           board[x][y]='Y';
          for(int i=0;i<4;i++)
          {
            int x1=x+dx[i];
            int y1= y+dy[i];

            if(x1>=0 && x1<n && y1>=0 & y1<m && board[x1][y1]=='O')
            {
                q.push({x1,y1});
            }
          }

        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='Y')
                board[i][j]='O';
                else
                board[i][j]='X';
            }
        }

    }
};
