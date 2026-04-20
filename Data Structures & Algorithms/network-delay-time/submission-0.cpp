class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> v(n+1);
        for(auto x: times)
        {
            v[x[0]].push_back({x[1],x[2]});
        }

        vector<int> dis(n+1, INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;
        dis[k]=0;
       pq.push({0,k});
    
       while(!pq.empty())
       {
        auto [dist,node] =pq.top();
        pq.pop();

        for(auto x: v[node])
        {
            int nd=x.first;
            int dst =x.second;

            if(dis[nd]> dist+dst)
            {
                dis[nd]=dist+dst;
                pq.push({dis[nd],nd});
            }
        }

       }
        int maxm=0;
  for(int i=1;i<n+1;i++)
  {
    if(dis[i]==INT_MAX)
    return -1;
    maxm=max(maxm,dis[i]);

  }
       return maxm;
        
    }
};
