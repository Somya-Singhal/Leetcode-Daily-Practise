class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int lo=0,hi=n-1,count=0;
        while(lo<=hi)
        {
            if(people[lo]+people[hi]<=limit)
            {
                count+=1;
                lo+=1;
                hi-=1;
            }
            else if(people[lo]+people[hi]>limit)
            {
                count+=1;
                hi-=1;
            }
            
        }
        return count;
    }
};