class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int lo=0,hi=n-1;
        int count=0;
        while(lo<=hi)
        {
            if((limit-people[hi])>=people[lo])
            lo++;
    
            hi--;
            count++;
        }
        return count;
    }
};