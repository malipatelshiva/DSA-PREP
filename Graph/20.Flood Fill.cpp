//Link : https://leetcode.com/problems/flood-fill/description/

//Code : 


class Solution {
public:

    bool isValid(vector<vector<int>>& image, int i, int j, int oldColor,int m,int n)
    {
         if( i>=0 && i<m && j>=0 && j<n && image[i][j]==oldColor)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void FillData(vector<vector<int>>& image, int i, int j, int oldColor,int newColor,int m,int n)
    {
       image[i][j] = newColor;
        if(isValid(image,i+1,j,oldColor,m,n))
            FillData(image,i+1,j,oldColor,newColor,m,n);
            
        if(isValid(image,i-1,j,oldColor,m,n))
            FillData(image,i-1,j,oldColor,newColor,m,n);

        if(isValid(image,i,j-1,oldColor,m,n))
        FillData(image,i,j-1,oldColor,newColor,m,n);

        if(isValid(image,i,j+1,oldColor,m,n))
            FillData(image,i,j+1,oldColor,newColor,m,n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {


        int m = image.size();
        int n = image[0].size();

        int oldColor = image[sr][sc];
        int newColor = color;


        // below is very important condition if oldColor == newColor then we will return image as it is because if we do not check this condition then it will go into infinite loop and give TLE error
        // will not check this condition then it will go into infinite loop and give TLE error
         if(oldColor == newColor)   
            return image;

        FillData(image,sr,sc,oldColor,newColor,m,n);
        return image;
        
    }
};