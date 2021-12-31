class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long long suff=1;
        int orig_no=0,zeros=0;
        double pref=1.0;
      for(int i=left;i<=right;i++)
      {
          pref*=i;
          while(pref>=1.0)
          {
              pref/=10.0;
              orig_no++;
          }
          suff*=i;
          while(suff%10==0)
          {
              suff/=10;
              zeros++;
          }
          if(suff>pow(10,8)) suff%=(long long)pow(10,8);
      }
        if(orig_no-zeros<=10)
            return to_string((long long)(pref*pow(10,orig_no-zeros)+0.5))+'e'+to_string(zeros);
        else
        {
            string str="0000"+to_string(suff);
            return to_string((int)(pref*100000))+"..."+str.substr(str.length()-5)+'e'+to_string(zeros);
        }
        
    }
};