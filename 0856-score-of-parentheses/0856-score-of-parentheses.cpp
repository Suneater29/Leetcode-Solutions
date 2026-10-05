class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        int ans=0;
        for(char c:s){
            if(c=='(') st.push(0);
            else{
                int val=st.top();
                st.pop();
                ans=max(2*val,1);
                st.top()+=ans;
            }
        }
        return st.top();
    }
};