class Solution {
public:
    unordered_map<string,double>mp;
    double solve(int na,int nb)
    {
        if(na==0 && nb==0)
            return 0.5;
        if(na==0)
            return 1;
        if(nb==0)
            return 0;
        string str=to_string(na)+" "+to_string(nb);
        if(mp.find(str)!=mp.end())
            return mp[str];
        mp[str]=0.25*(solve(max(na-100,0),nb)+solve(max(na-75,0),max(nb-25,0))+solve(max(na-50,0),max(nb-50,0))+solve(max(0,na-25),max(0,nb-75)));
        return mp[str];
    }
    double soupServings(int n) {
        if(n>4800)
            return 1.0;
        return solve(n,n);
    }
};