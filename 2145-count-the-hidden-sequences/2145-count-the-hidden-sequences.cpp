class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        //brute force
        // int n=differences.size();
        // int ans=0,curr=upper;
        // if(differences[n-1]<0)
        //     curr=upper+differences[n-1];
        // while(curr>=lower)
        // {
        //     int temp=curr;
        //      int mymin=curr,mymax=curr;
        //     for(int i=n-1;i>=0;i--)
        //     {
        //         temp-=differences[i];
        //         mymax=max(mymax,temp);
        //         mymin=min(mymin,temp);
        //     }
        //     // cout<<mymin<<" "<<mymax<<"\n";
        //     if(mymin>=lower && mymax<=upper)
        //         ans++;
        //     curr--;
        // }
        // return ans;
        
        long a=0,mymin=0,mymax=0;
        int n=differences.size();
        for(int i=0;i<n;i++)
        {
            a+=differences[i];
            mymin=min(mymin,a);
            mymax=max(mymax,a);
        }
        return max(0L,(upper-lower)-(mymax-mymin)+1);
    }
};