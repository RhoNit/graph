class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int fixed_color = image[sr][sc];
        
        // edge case: if the adjacent cells are fixed_colored then no need to do extra work i.e. recursion
        // simply return the `image` as it is
        if(fixed_color == color) return image;
        
        traverse(image, n, m, sr, sc, fixed_color, color);

        return image;
    }

    void traverse(vector<vector<int>> &image, int n, int m, int curr_row, int curr_col, int fixed_color, int color) {
        if(curr_row >= 0 and curr_row < n and curr_col >= 0 and curr_col < m and image[curr_row][curr_col] == fixed_color) {
            // change the color
            image[curr_row][curr_col] = color;

            traverse(image, n, m, curr_row, curr_col+1, fixed_color, color);
            traverse(image, n, m, curr_row, curr_col-1, fixed_color, color);
            traverse(image, n, m, curr_row-1, curr_col, fixed_color, color);
            traverse(image, n, m, curr_row+1, curr_col, fixed_color, color);
        }

        return;
    }
};