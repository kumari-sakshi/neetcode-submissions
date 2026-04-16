class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     
     int n=nums.size();
     vector<int> front(n,1);
     vector<int> back(n,1);
     for(int i=0;i<n;i++)
     {
        if(i!=0)
        front[i]=front[i-1]*nums[i];
        else
        front[i]=nums[i];
     }
      for(int i=n-1;i>=0;i--)
     {
        if(i!=n-1)
        back[i]=back[i+1]*nums[i];
        else
        back[i]=nums[i];
     }
     vector<int> ans(n,1);
     for(int i=0;i<n;i++)
     {
        if(i==0)
        ans[i]=back[i+1];
        else if(i==n-1)
        ans[i]=front[i-1];
        else
        ans[i]= back[i+1]*front[i-1];
     }
return ans;
      

    }
};
