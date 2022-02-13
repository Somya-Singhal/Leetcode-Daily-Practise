class Solution {
public:
    // int count=0;
    // void solve(int val,int n,vector<int>& v)
    // {
    //     if(val>n)
    //     {
    //         count++;
    //         return;
    //     }
    //     for(int i=1;i<=n;i++)
    //     {
    //         if(v[i]==0 && (val%i==0 || i%val==0))
    //         {
    //             v[i]=val;
    //             solve(val+1,n,v);
    //             v[i]=0; 
    //         }
    //     }
    // }
    // int countArrangement(int n) {
    //     vector<int>v(n+1,0);
    //     solve(1,n,v);
    //     return count;
    // }
    
    int count=0;
     void solve(int val,vector<int>& v)
     {
         if(val==0)
         {
             count++;
             return;
         }
         for(int i=val;i>0;i--)
         {
             if(v[i]%val==0 || val%v[i]==0)
             {
                 swap(v[i],v[val]);
                 solve(val-1,v);
                 swap(v[i],v[val]);
             }
         }
     }
     int countArrangement(int n) {
        vector<int>v(n+1,0);
         for(int i=1;i<=n;i++)
             v[i]=i;
        solve(n,v);
        return count;
    }
};