class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> v(26,0);
        for(auto c: tasks)
        {
            v[c-'A']++;
        }
        sort(v.rbegin(),v.rend());
        int max_freq= v[0];
        int cnt=0;
        for(int i=0;i<26;i++){
            if(max_freq==v[i])
            cnt++;
        }
     int m= tasks.size();
        return max(m,(max_freq-1)*(n+1)+cnt);
    }
};
