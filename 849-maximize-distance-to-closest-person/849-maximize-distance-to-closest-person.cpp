class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int first=-1,second=-1,maxdist=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(seats[i]==1)
            {
                if(first==-1)
                {
                    maxdist=i;
                    first=i;
                }
                else
                {
                    second=first;
                    first=i;
                    maxdist=max(maxdist,(first-second)/2);
                }
            }
        }
        return max(maxdist,n-first-1);
    }
};