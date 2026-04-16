class Solution {
public:
    bool isValid(string s) {
       
     stack<char> st;
     for(auto c : s)
     {
      if((c == ')' && (st.empty() || st.top()!='(')) ||(c == '}' && (st.empty() || st.top()!='{'))|| (c == ']' && (st.empty() || st.top()!='[')))
      return 0;
      else if(c=='(' || c=='{' ||c=='[')
      st.push(c);
      else
      st.pop();
     }
     return st.empty()? true :false;


    }
};
