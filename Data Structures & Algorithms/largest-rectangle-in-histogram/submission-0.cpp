class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n=heights.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        int maxm=0;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            s.pop();
            if(s.empty())
            left[i]=-1;
            else
            left[i]=s.top();
            s.push(i);
        }
        while(!s.empty()) {
        s.pop();
       }
          for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            s.pop();
            if(s.empty())
            right[i]=n;
            else
            right[i]=s.top();
            s.push(i);
        }

        for(int i=0;i<n;i++)
        {
            maxm=max(maxm, (right[i]-left[i]-1)*heights[i]);
        }
        return maxm;
        
    }
};
