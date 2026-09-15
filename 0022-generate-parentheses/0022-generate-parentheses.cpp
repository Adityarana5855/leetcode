class Solution {
public:
    vector<string>ans;
    void backtrack(string s,int open,int close,int  n){
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s+='(';
            backtrack(s,open+1,close,n);
            s.pop_back();
        }
        if(close<open){
            s+=')';
            backtrack(s,open,close+1,n);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        backtrack("",0,0,n);
        return ans;


        
    }
};