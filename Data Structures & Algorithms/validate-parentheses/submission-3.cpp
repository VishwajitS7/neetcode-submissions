class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='(' ||s[i]=='[' ||s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(s[i]==')' && st.top()!='('){
                    return false;
                }
                if(s[i]==']' && st.top()!='['){
                    return false;
                }
                if(s[i]=='}' && st.top()!='{'){
                    return false;
                }
                st.pop();
            }            
            i++;
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
