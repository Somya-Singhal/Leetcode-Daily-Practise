class Solution {
public:
    //direction should change or moved 0 blocks(means returned back to start)
    //see both these properties after doing one iteration of given instruction
    //OR
    //iterate 4 times and check whether a cycle exists or not
    bool isRobotBounded(string instructions) {
        int n=instructions.length();
        int direction=0,posx=0,posy=0;
        for(int i=0;i<n;i++)
        {
            if(instructions[i]=='G')
            {
                if(direction==0)
                {
                    posy++;
                }
                if(direction==1)
                {
                    posx++;
                }
                if(direction==2)
                {
                    posy--;
                }
                if(direction==3)
                {
                    posx--;
                }
            }
            if(instructions[i]=='R')
            {
                direction++;
                if(direction<0)
                   direction=(4+direction)%4; 
                else
                    direction%=4;
                cout<<direction<<" ";
            }
            if(instructions[i]=='L')
            {
                direction--;
                if(direction<0)
                   direction=(4+direction)%4; 
                else
                    direction%=4;
                cout<<direction<<" ";
            }
        }
        if(direction!=0 || (posx==0 && posy==0))
            return true;
        return false;
    }
};