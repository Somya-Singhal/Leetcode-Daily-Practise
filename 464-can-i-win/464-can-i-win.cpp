class Solution {
public:
    // bool canIWin(int maxChoosableInteger, int desiredTotal) {
    //     if(desiredTotal<=0)
    //         return true;
    //     if(desiredTotal>(maxChoosableInteger+1)*maxChoosableInteger/2)
    //         return false;
    //     vector<bool>arr(maxChoosableInteger+1,false);
    //     return solve(maxChoosableInteger,desiredTotal,arr);
    // }
    // bool solve(int maxChoosableInteger, int desiredTotal,vector<bool>& arr)
    // {
    //     if(desiredTotal<=0)
    //         return false;
    //     for(int i=1;i<=maxChoosableInteger;i++)
    //     {
    //         if(arr[i]==true)
    //             continue;
    //         arr[i]=true;
    //         if(!solve(maxChoosableInteger,desiredTotal-i,arr))
    //         {
    //             arr[i]=false;
    //             return true;
    //         }
    //         arr[i]=false;
    //     }
    //     return false;
    // }
    
    
   bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal<=0)
            return true;
        if(desiredTotal>(maxChoosableInteger+1)*maxChoosableInteger/2)
            return false;
        unordered_map<int,bool>mp;
        string str(maxChoosableInteger+1,'0');
        return solve(maxChoosableInteger,desiredTotal,mp,str);
    }
    bool solve(int maxChoosableInteger, int desiredTotal,unordered_map<int,bool>& mp,string & str)
    {
        if(desiredTotal<=0)
            return false;
        int num=atoi(str.c_str());
        if(mp.find(num)!=mp.end())
            return mp[num];
        for(int i=1;i<=maxChoosableInteger;i++)
        {
            if(str[maxChoosableInteger+1-i]=='1')
                continue;
            str[maxChoosableInteger+1-i]='1';
            // cout<<num<<endl;
            if(!solve(maxChoosableInteger,desiredTotal-i,mp,str))
            {
                mp[num]=true;
                str[maxChoosableInteger+1-i]='0';
                return true;
            }
            str[maxChoosableInteger+1-i]='0';
        }
        return mp[num]=false;
    }
};