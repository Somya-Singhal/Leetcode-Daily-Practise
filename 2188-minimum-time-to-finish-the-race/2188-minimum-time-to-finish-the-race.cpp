class Solution {
public:
    // int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
    //     int n=tires.size();
    //     vector<vector<int>>withoutChange(n,vector<int>(20,2e9));
    //     for(int i=0;i<n;i++)
    //     {
    //         withoutChange[i][1]=tires[i][0];
    //         //x->no of laps        
    //         for(int x=2;x<20;x++)
    //         {
    //             if((long long)withoutChange[i][x-1]*tires[i][1]>=2e9)
    //                 break;
    //             withoutChange[i][x]=withoutChange[i][x-1]*tires[i][1];
    //         }
    //         for(int x=2;x<20;x++)
    //         {
    //             if((long long)withoutChange[i][x-1]+withoutChange[i][x]>=2e9)
    //                 break;
    //             withoutChange[i][x]+=withoutChange[i][x-1];
    //         }
    //     }
    //     vector<int>dp(numLaps+1,2e9);
    //     for(int i=0;i<n;i++)
    //     {
    //         dp[1]=min(dp[1],tires[i][0]);
    //     }
    //     //x->no of laps 
    //     for(int x=1;x<=numLaps;x++)
    //     {
    //         if(x<20)
    //         {
    //           for(int i=0;i<n;i++)
    //           {
    //               dp[x]=min(dp[x],withoutChange[i][x]);
    //           }
    //         }
    //         for(int j=x-1;j>0 && j>=x-18;j--)
    //         {
    //             dp[x]=min(dp[x],dp[j]+changeTime+dp[x-j]);
    //         }
    //     }
    //     return dp[numLaps];
    // }
    
    vector<vector<int>> preprocess(vector<vector<int>>& tires)
    {
        int n=tires.size();
        sort(tires.begin(),tires.end());
        vector<vector<int>>newTires;
        for(int i=0;i<n;i++)
        {
            if(newTires.empty() || newTires.back()[1]>tires[i][1])
                newTires.push_back(tires[i]);
        }
        return newTires;
    }
    
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        tires=preprocess(tires);
         int n=tires.size();
        vector<vector<int>>withoutChange(n,vector<int>(20,2e9));
        for(int i=0;i<n;i++)
        {
            withoutChange[i][1]=tires[i][0];
            //x->no of laps        
            for(int x=2;x<20;x++)
            {
                if((long long)withoutChange[i][x-1]*tires[i][1]>=2e9)
                    break;
                withoutChange[i][x]=withoutChange[i][x-1]*tires[i][1];
            }
            for(int x=2;x<20;x++)
            {
                if((long long)withoutChange[i][x-1]+withoutChange[i][x]>=2e9)
                    break;
                withoutChange[i][x]+=withoutChange[i][x-1];
            }
        }
        vector<int>dp(numLaps+1,2e9);
        for(int i=0;i<n;i++)
        {
            dp[1]=min(dp[1],tires[i][0]);
        }
        //x->no of laps 
        for(int x=1;x<=numLaps;x++)
        {
            if(x<20)
            {
              for(int i=0;i<n;i++)
              {
                  dp[x]=min(dp[x],withoutChange[i][x]);
              }
            }
            for(int j=x-1;j>0 && j>=x-18;j--)
            {
                dp[x]=min(dp[x],dp[j]+changeTime+dp[x-j]);
            }
        }
        return dp[numLaps];
    }
};