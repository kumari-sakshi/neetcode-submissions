class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int> m1;
       unordered_map<char,int> m2;

       int min_len=INT_MAX;
       for(auto c: t)
       {
        m1[c]++;
       } 
       int req=m1.size();
       int i=0,strt=0,j=0,need=0;
       while(j<s.length())
       {
        m2[s[j]]++;
        if(m1.find(s[j])!=m1.end() && m1[s[j]]==m2[s[j]])
        need++;

        while(need==req)
        {
            if(min_len >j-i+1)
            {
                strt=i;
                min_len =j-i+1;
            }
            char str =s[i];
            m2[str]--;
            if(m1.find(str)!=m1.end()&& m2[str]<m1[str])
            need--;

            i++;
        }

        j++;
       }

       return min_len == INT_MAX ?"":s.substr(strt,min_len);
     
    
     
    }
};
