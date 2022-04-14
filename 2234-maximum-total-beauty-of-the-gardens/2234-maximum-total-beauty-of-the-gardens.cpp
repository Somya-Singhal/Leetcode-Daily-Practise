class Solution {
public:
    
    //two pointers
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        long long n=flowers.size(),sum=0,ans=0,p1=0;
        sort(begin(flowers),end(flowers),greater<int>());
        for(;p1<n;p1++)
        {
            if(newFlowers<target-flowers[p1])
                break;
            newFlowers-=max(0,target-flowers[p1]);
        }
        if(p1==n)
            return max(n*full,full*(n-1)+(flowers.back()<target?(long long)partial*(target-1):full));
        for(long long minp=flowers.back(),p2=n-1;minp<target;){
            while(p2>=p1 && flowers[p2]<=minp){
               sum+= flowers[p2--];
            }
            int needed=(n-p2-1)*minp-sum;
            if(newFlowers<needed){
                if(--p1<0)
                    break;
                newFlowers+=max(0,target-flowers[p1]);
            }
            else{
                ans=max(ans,full*p1+partial*minp);
                ++minp;
            }
        }
       return ans; 
    }
};