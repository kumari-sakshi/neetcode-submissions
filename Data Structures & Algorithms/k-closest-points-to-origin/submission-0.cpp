class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;

        for(auto c :points)
        {
            pq.push({c[0]*c[0]+c[1]*c[1],c});
            if(pq.size()>k)
            pq.pop();
        }
    

    vector<vector<int>> ans;
    while(!pq.empty())
    { // vector<int> v;
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
    }
};
