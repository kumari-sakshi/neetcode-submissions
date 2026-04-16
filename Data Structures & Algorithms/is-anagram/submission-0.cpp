class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        int m= t.length();

        if(n!=m)
        return 0;
        vector<int> v(26,0);
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a']++;
        }
        for(int i=0;i<m;i++)
        {
            v[t[i]-'a']--;
        }

        for(int i=0;i<26;i++)
        {
            if(v[i]!=0)
            return 0;
        }
        return 1;
    }
};
