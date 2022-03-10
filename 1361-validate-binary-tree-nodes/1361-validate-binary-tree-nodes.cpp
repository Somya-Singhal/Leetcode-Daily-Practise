class Solution {
public:
    int find(int i,vector<int>& parent)
    {
        if(parent[i]<0)
            return i;
        return parent[i]=find(parent[i],parent);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>parent(n,-1),indegree(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                int p=find(i,parent),c=find(leftChild[i],parent);
                if(p!=c)
                {
                    parent[leftChild[i]]=i;
                    indegree[leftChild[i]]++;
                }
                else
                    return false;
            }
            if(rightChild[i]!=-1)
            {
                int p=find(i,parent),c=find(rightChild[i],parent);
                if(p!=c)
                {
                    parent[rightChild[i]]=i;
                    indegree[rightChild[i]]++;
                }
                else
                    return false;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]>1)
                return false;
            if(indegree[i]==0)
                count++;
        }
        return (count==1);
    }
};