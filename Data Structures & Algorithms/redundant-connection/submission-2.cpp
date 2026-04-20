class Solution {
public:
    class DSU{

        public:
        vector<int>rank,parent;

        DSU(int n)
        {
            rank.resize(n,1);
            parent.resize(n);
            for(int i=1;i<n;i++)
            parent[i]=i;
        }

        int findParent(int a)
        {
            if(parent[a]==a)
            return a;
            return parent[a]=findParent(parent[a]);
        }
        bool unionFind(int a,int b)
        {
            int x=findParent(a);
            int y=findParent(b);
            if(x==y)
            return 1;
            else{
             if(rank[x]>rank[y])
             {
                parent[y]=x;
             }else if(rank[x]<rank[y]){
                parent[x]=y;
             }else{
                rank[x]++;
                parent[y]=x;
             }

            }
            return 0;
        }
        
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n+1);
        vector<int> v;
        for(auto edge: edges)
        {
            if(dsu.unionFind(edge[0],edge[1])){
               v=edge; 
            }
        }
        return v;
    }
};
