class Solution {
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<pair<int,int>> p = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int old = image[sr][sc];
        if (image[sr][sc] == newColor) return image;
        queue<pair<int,int>> Q;
        Q.push(make_pair(sr,sc));
        image[sr][sc] = newColor;
        while(!Q.empty()){
            auto x = Q.front();
            int i = x.first;
            int j = x.second;
            Q.pop();
            for(auto it=p.begin();it != p.end(); ++it){
                int X = i + it->first;
                int Y = j + it->second;
                if(X >= 0 && Y >= 0 && X < n && Y < m && image[X][Y] == old){
                    Q.push(make_pair(X,Y));
                    image[X][Y] = newColor;
                }
            }
        }
        return image;
    }
};
