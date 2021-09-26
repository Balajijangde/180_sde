class Solution {
public:
    void paintIt(vector<vector<int>>& image, int sr, int sc, int newColor, int &oldColor){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor) return;
        if(image[sr][sc] == newColor) return;
        
        image[sr][sc] = newColor;
        
        paintIt(image, sr - 1, sc, newColor, oldColor);
        paintIt(image, sr + 1, sc, newColor, oldColor);
        paintIt(image, sr, sc - 1, newColor, oldColor);
        paintIt(image, sr, sc + 1, newColor, oldColor);
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        paintIt(image, sr, sc, newColor, oldColor);
        return image;
    }
};