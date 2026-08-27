//Link : https://www.geeksforgeeks.org/problems/maximum-weight-node--170645/1


//Company Asked : JUSPAY

class Solution {
  public:
    int maxWeightCell(vector<int> &exits) {
        // code here
        
        int n = exits.size();
        vector<int>sum(n,0);
        
        for(int i= 0;i<n;i++)
        {
            if(exits[i]!=-1)
            {
                sum[exits[i]] = sum[exits[i]] + i;
            }
            
        }
        
        int maxValue = 0;
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(sum[i]>=maxValue)
            {
                maxValue = sum[i];
                res =i;
            }
        }
        
        return res;
    }
};