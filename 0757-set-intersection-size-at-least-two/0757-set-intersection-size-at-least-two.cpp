class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        stack<vector<int>>s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && s.top()[1]>=intervals[i][1])
                s.pop();
            s.push({intervals[i][0],intervals[i][1]});
        }
        int m=s.size();
        vector<vector<int>>arr(m,vector<int>(2,0));
        for(int i=m-1;i>=0;i--)
        {
            arr[i][0]=s.top()[0];
            arr[i][1]=s.top()[1];
            s.pop();
        }
        int ans=2;
        int num1=arr[0][1]-1,num2=arr[0][1];
        for(int i=1;i<m;i++)
        {
            bool b1=(num1>=arr[i][0] && num1<=arr[i][1]);
            bool b2=(num2>=arr[i][0] && num2<=arr[i][1]);
            if(b1 && b2)
                continue;
            if(b2)
            {
                num1=num2;
                num2=arr[i][1];
                ans+=1;
                continue;
            }
            else
            {
                num1=arr[i][1]-1;
                num2=arr[i][1];
                ans+=2;
            }
        }
        return ans;
    }
};