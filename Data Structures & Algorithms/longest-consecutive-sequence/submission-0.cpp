class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
    
        unordered_set<int> s(nums.begin(),nums.end());

        int maxm=0;
        for(auto x:nums)
        {
            if(s.find(x-1)==s.end())
            {
                int cnt=1;
                int curnum=x;

                while(s.find(curnum+1)!=s.end())
                {
                    cnt++;
                    curnum++;
                }

                maxm=max(cnt,maxm);
            }
        }

        return maxm;
        

        
    }
};
