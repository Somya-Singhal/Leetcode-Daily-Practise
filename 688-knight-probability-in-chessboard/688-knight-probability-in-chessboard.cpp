class Solution {
public:
    int dx[8]={-2,-1,1,2,2,1,-1,-2},dy[8]={1,2,2,1,-1,-2,-2,-1};
    unordered_map<string,double>mp;
    double solve(int n, int k, int x, int y)
    {
        if(x<0 || x>=n || y<0 || y>=n)
            return 0;
        if(k==0)
            return 1;
        string str=to_string(k)+" "+to_string(x)+" "+to_string(y);
        if(mp.find(str)!=mp.end())
            return mp[str];
        double ways=0;
        for(int i=0;i<8;i++)
        {
            ways+=0.125*solve(n,k-1,x+dx[i],y+dy[i]);
        }
        mp[str]=ways;
        return mp[str];
    }
    double knightProbability(int n, int k, int row, int column) {
        return solve(n,k,row,column);
    }
};