class Solution {
public:
    bool backTrack(char charset[],vector<int>& charCount,vector<bool>& nonleadingzeros,vector<int>& used,int steps,int diff,int len)
    {
        if(steps==len)
            return diff==0;
        for(int i=0;i<=9;i++)
        {
            if(!used[i] && (i>0 || !nonleadingzeros[charset[steps]]))
            {
                used[i]=1;
                if(backTrack(charset,charCount,nonleadingzeros,used,steps+1,diff+charCount[charset[steps]]*i,len))
                    return true;
                used[i]=0;
            }
        }
        return false;
    }
    bool isSolvable(vector<string>& words, string result) {
        int n=words.size();
        set<char>s;
        vector<int>pos={1,10,100,1000,10000,100000,1000000};
        vector<bool>nonleadingzeros(91,false);
        vector<int>charCount(91,0);
        vector<int>used(10,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                if(j==0 && words[i].length()>1)
                    nonleadingzeros[words[i][j]]=true;
                 s.insert({words[i][j]});
                 charCount[words[i][j]]+=pos[words[i].length()-j-1];
            }
        }
        for(int i=0;i<result.length();i++)
        {
            if(i==0 && result.length()>1)
                    nonleadingzeros[result[i]]=true;
                 s.insert({result[i]});
                 charCount[result[i]]-=pos[result.length()-i-1];
        }
        int len=s.size();
        char charset[len];
        int i=0;
        for(auto c: s)
            charset[i++]=c;
        return backTrack(charset,charCount,nonleadingzeros,used,0,0,len);
    }
};