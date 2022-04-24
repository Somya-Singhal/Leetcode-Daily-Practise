class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int n=flowers.size();
        int p=persons.size();
        vector<int>start,v_end;
//         map<int,int>m;
        for(int i=0;i<n;i++)
        {
            start.push_back(flowers[i][0]);
            v_end.push_back(flowers[i][1]);
        }
        sort(start.begin(),start.end());
        sort(v_end.begin(),v_end.end());
//         int i=0,j=0,count=0;
//         while(i<n && j<n){
//             int time;
//            if(start[i]<v_end[j])
//            {
//                time=start[i];
//                count++;
//                i++;
//            }
//             else if(start[i]>v_end[j])
//             {
//                 time=v_end[j];
//                 count--;
//                 j++;
//             }
//             else
//             {
//                 time=start[i];
//                 i++;
//                 j++;
//             }
//           m[time]=count;
//         }
//         for(int i=0;i<p;i++)
//         {
//             if(m.find(persons[i])!=m.end())
//                 ans[i]=m[persons[i]];
//             else{
//                 auto it=m.lower_bound(persons[i]);
//                     ans[i]=it->second;

//             }
//         }
//         return ans;
        vector<int>ans;
        for(int i=0;i<p;i++)
        {
            int f=upper_bound(start.begin(),start.end(),persons[i])-start.begin();
            int l=lower_bound(v_end.begin(),v_end.end(),persons[i])-v_end.begin();
            ans.push_back(f-l);
        }
        return ans;
    }
};