class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n=removable.size();
        int lo=0,hi=n,ans=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            string str=s;
            for(int i=0;i<mid;i++)
            {
                str[removable[i]]='*';
            }
            cout<<str<<" ";
            int j=0;
            for(int i=0;i<str.length() && j<p.length();i++)
            {
                if(str[i]!='*' && str[i]==p[j])
                    j++;
            }
            if(j==p.length()){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};