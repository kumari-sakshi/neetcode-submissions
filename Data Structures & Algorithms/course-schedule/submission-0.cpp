class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

     vector<int> v[numCourses];
     vector<int> indegree(numCourses,0);
     for(auto c:prerequisites)   
     {
        v[c[1]].push_back(c[0]);
        indegree[c[0]]++;
     }

     queue<int> q;
     for(int i=0;i<numCourses;i++)
     {
        if(indegree[i]==0)
        q.push(i);
     }
     
     int cnt =0;
     while(!q.empty())
     {
        int temp=q.front();
        q.pop();
        cnt++;
        for(auto x: v[temp])
        {
            indegree[x]--;
            if(indegree[x]==0)
            q.push(x);
        }
     }

     if(cnt==numCourses)
     return 1;
     return 0;

    }
};
