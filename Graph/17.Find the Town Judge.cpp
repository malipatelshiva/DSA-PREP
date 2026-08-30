// Leetcode : 997.Find the Town Judge
//Link : https://leetcode.com/problems/find-the-town-judge/description/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {


        vector<int>temp(n+1,0);

        for(int i=0;i<trust.size();i++)
        {   

            int u = trust[i][0];
            int v = trust[i][1];

            temp[v]++;
            temp[u]--;

        }

        //in-degree - out-degree = N - 1

        for(int i=1;i<=n;i++)
        {
            if(temp[i]==n-1)
            {
                return i;
            }
        }
        return -1;
        
    }
};