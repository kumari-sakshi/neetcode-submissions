class Solution {
public:
   
    int findParent(int a,vector<int>&parent)
    {
        if(parent[a]==a)
        return a;
        else
        return parent[a]=findParent(parent[a],parent);
    }
    bool unionFind(int a,int b, vector<int> &parent, vector<int> & rank)
    {
        int x=findParent(a,parent);
        int y=findParent(b,parent);
        if(x==y)
        return 0;
       else 
        {
            if(rank[x]>rank[y])
            {
                parent[y]=x;
            
            }else if(rank[y]>rank[x])
            {
                parent[x]=y;
              
            }else
            {
                 parent[y] = x;
            rank[x]++;
            }
        }
        return 1;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
    
      vector<int> parent(n,0);
      vector<int> rank(n,1);
    
      for(int i=0;i<n;i++)
      {
        parent[i]=i;
      }
    int cnt =n;
      for(auto c: edges)
      {
       if( unionFind(c[0],c[1], parent,rank))
       cnt--;
      }
   

     return cnt;
    
    }
};
