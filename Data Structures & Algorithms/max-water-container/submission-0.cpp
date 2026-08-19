class Solution {
public:
    int maxArea(vector<int>& heights) {

        int n=heights.size();

        int i=0,j=n-1;
        int maxm=0;
        while(i<j)
        {
            if(heights[i]<=heights[j])
            {
                maxm=max(maxm,heights[i]*(j-i));
                i++;

            }
            else 
            {
                 maxm=max(maxm,heights[j]*(j-i));
                j--;
            }
        }
        return maxm;
        
    }
};
