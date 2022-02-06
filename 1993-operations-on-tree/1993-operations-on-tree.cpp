class LockingTree {
public:
    vector<vector<int>>nodes;
    unordered_map<int,vector<int>>descendent;
    int n;
    LockingTree(vector<int>& parent) {
        n=parent.size();
        nodes.resize(n,vector<int>(2,-1));
        nodes[0][0]=-1;
        for(int i=1;i<n;i++)
        {
            nodes[i][0]=parent[i];
            descendent[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(nodes[num][1]!=-1)
            return false;
        nodes[num][1]=user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(nodes[num][1]!=user)
        return false;
        nodes[num][1]=-1;
        return true;
    }
   void countlockeddesc(int num,bool &present)
    {
        if(descendent.count(num)==0 || descendent[num].size()==0)
        return;
        for(auto &x: descendent[num])
        {
            if(nodes[x][1]!=-1)
            {
                present=true;
                return;
            }
            countlockeddesc(x,present);
        }
    }
    void removedescendent(int num)
    {
        if(descendent.count(num)==0  || descendent[num].size()==0)
            return;
        for(auto x: descendent[num])
        {
            nodes[x][1]=-1;
           removedescendent(x); 
        }
    }
    // bool ancestor(int num)
    // {
    //     if(num==-1)
    //         return false;
    //     return nodes[num][1]!=-1 || ancestor(nodes[num][0]);
    // }
    bool upgrade(int num, int user) {
        if(nodes[num][1]!=-1)
            return false;
         bool present=false;
        countlockeddesc(num,present);
        if(!present)
            return false;
        int i=nodes[num][0];
        while(i!=-1)
        {
            if(nodes[i][1]!=-1)
                return false;
            i=nodes[i][0];
        }
       // if(ancestor(nodes[num][0]))
       //     return false;
        removedescendent(num);  
        nodes[num][1]=user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */