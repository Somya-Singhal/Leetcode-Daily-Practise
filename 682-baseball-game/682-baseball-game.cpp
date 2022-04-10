class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n=ops.size();
        int sum=0;
        vector<int>nums;
        for(int i=0;i<n;i++){
            if(ops[i]=="+")
            {
                nums.push_back(nums[nums.size()-1]+nums[nums.size()-2]);
            }
            else if(ops[i]=="C"){
                nums.pop_back();
            }
            else if(ops[i]=="D"){
                nums.push_back(nums.back()*2);
            }
            else{
                nums.push_back(atoi(ops[i].c_str()));
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        return sum;
    }
};