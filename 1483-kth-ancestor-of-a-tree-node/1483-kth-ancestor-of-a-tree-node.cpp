class TreeAncestor {
public:vector<vector<int>>P;
    TreeAncestor(int n, vector<int>& parent) {
        P.resize(20,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            P[0][i]=parent[i];
        }
        for(int i=1;i<20;i++)
        {
            for(int j=0;j<n;j++)
            {
                int prev=P[i-1][j];
                if(prev!=-1)
                    P[i][j]=P[i-1][prev];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<20;i++)
        {
            if(k&(1<<i)){
                node=P[i][node];
                if(node==-1)
                    return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */