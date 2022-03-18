class Solution {
public:
    //binary search
    long mod=1e9+7;
    int maxProfit(vector<int>& inventory, int orders) {
        
       sort(inventory.rbegin(),inventory.rend());
       long ans=0,curr=inventory[0],i=0,n=inventory.size();
       while(orders)
       {
           while(i<n && inventory[i]==curr)
               i++;
           long next=i==n?0:inventory[i],h=curr-next,count=min((long)orders,i*h),rem=0;
           if(orders<i*h)
           {
               h=orders/i;
               rem=orders%i;
           }
           long val=curr-h;
           ans=(ans+(curr+val+1)*h/2*i+val*rem)%mod;
           orders-=count;
           curr=next;
       }
        return ans;
    }
};