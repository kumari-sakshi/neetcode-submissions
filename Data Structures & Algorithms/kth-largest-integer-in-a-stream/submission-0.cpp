class KthLargest {
public:
   // unordered_map<int,int> m;
    priority_queue<int,vector<int>,greater<int>> pq;
    int k1=0; 
    KthLargest(int k, vector<int>& nums) {
        k1=k;
        for(int i=0;i<nums.size();i++)
        {
           // if(m.find(nums[i])==m.end())
            pq.push(nums[i]);
            if(pq.size()>k)
            {
               // m.erase(pq.top());
                pq.pop();
            }
        }
    }
    
    int add(int val) {

         pq.push(val);
        while(pq.size()>k1)
        pq.pop();
        return pq.top();
        
    }
};
