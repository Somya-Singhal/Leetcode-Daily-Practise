class Solution {
public:
    void generaterec(int start,int end,int n,string op,vector<string>& res)
    {
        if(op.length()==n*2)
        {
            res.push_back(op);
            return;
        }
        if(start<n)
        {
            op.append("(");
            generaterec(start+1,end,n,op,res);
            op.pop_back();
        }
        if(end<start)
        {
            op.append(")");
            generaterec(start,end+1,n,op,res);
            op.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string op="";
        vector<string>res;
        generaterec(0,0,n,op,res);
        return res;
    }
};