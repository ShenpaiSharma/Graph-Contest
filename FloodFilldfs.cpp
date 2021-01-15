class Solution {
public:
    
    int n,m;
    int New;
    int Old;
    
    void dfs(vector<vector<int>> &image, int x, int y){
        if(x < 0 || y < 0 || x >= n || y >= m || image[x][y] != Old) return;
        image[x][y] = New;
        dfs(image, x+1, y);
        dfs(image, x-1, y);
        dfs(image, x, y-1);
        dfs(image,x,y+1);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        New = newColor;
        if(image[sr][sc] == newColor) return image;
        Old = image[sr][sc];
        dfs(image, sr, sc);
        return image;
    }
};
