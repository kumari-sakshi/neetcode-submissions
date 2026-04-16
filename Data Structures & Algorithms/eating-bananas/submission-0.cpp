 int fun(vector<int>& piles, int m)
 {
    int cnt=0;
    for(int i=0;i<piles.size();i++)
    {
        cnt+=(piles[i]+m-1)/m;
    }
   return cnt;
 }
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l= 1;
        int high =*max_element(piles.begin(),piles.end());
          int ans=0;
        while(l<=high)
        {
            int mid=(l+high)/2;
          
            if(fun(piles,mid)<=h)
            {
                ans=mid;
                high=mid-1;
            }else
            l=mid+1;
        }
     return ans;
        
    }
};
