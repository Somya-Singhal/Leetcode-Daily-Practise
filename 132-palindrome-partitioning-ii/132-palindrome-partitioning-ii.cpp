class Solution {
public:
    /*check palindrome or not and then take min where it is false else if true put 0 :)*/
    //time->O(n^3)
//     int minCut(string s) {
//         int n=s.length();
//         vector<vector<bool>>checkpalin(n,vector<bool>(n,false));
//         vector<vector<int>>count(n,vector<int>(n,0));
        
//         //constructing boolean matrix to find which substring is palindrome
//         for(int gap=0;gap<n;gap++)
//         {
//             for(int i=0,j=gap;j<n;i++,j++)
//             {
//                 if(j==i)
//                   checkpalin[i][j]=true; 
//                 else if(j==i+1)
//                 {
//                     if(s[i]==s[j])
//                         checkpalin[i][j]=true;
//                 }
//                 else{
//                     if(s[i]==s[j] && checkpalin[i+1][j-1])
//                         checkpalin[i][j]=true;     
//                 }
//             }
//         }
        
//         //constructing final ans matrix to store min count
//         for(int gap=0;gap<n;gap++)
//         {
//             for(int i=0,j=gap;j<n;i++,j++)
//             {
//                 if(j==i)
//                   count[i][j]=0; 
//                 else if(j==i+1)
//                 {
//                     if(checkpalin[i][j]==true)
//                         count[i][j]=0;
//                     else
//                      count[i][j]=1;
//                 }
//                 else{
//                     if(checkpalin[i][j]==true)
//                         count[i][j]=0;
//                     else
//                     {
//                         int countmin=INT_MAX;
//                         for(int k=i;k<j;k++)
//                         {
//                             countmin=min(countmin,1+count[i][k]+count[k+1][j]);
//                         }
//                         count[i][j]=countmin;
//                     }
//                 }
//             }
//         }
//         return count[0][n-1];
//     }
    
    //time-->O(n^2)
    int minCut(string s) {
        int n=s.length();
        vector<vector<bool>>checkpalin(n,vector<bool>(n,false));
        vector<int>count(n);
        
        //constructing boolean matrix to find which substring is palindrome
        for(int i=0;i<n;i++)
        {
            int mincut=i;
            for(int j=0;j<=i;j++)
            {
                if(s[i]==s[j] &&((i-j)<2 || checkpalin[j+1][i-1]))
                {
                    checkpalin[j][i]=true;
                    mincut=min(mincut,(j==0)?0:count[j-1]+1);
                }
            }
            count[i]=mincut;
        }
        return count[n-1];
    }
};