###############################################################################  Question  ###################################################################################################################################






You are a hiker preparing for an upcoming hike. You are given heights[][], a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find the route with minimum effort.

Note: A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Example 1:

Input:
row = 3
columns = 3 
heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 
2
Explaination: 
The route 1->3->5->3->5 has a maximum absolute difference of 2 in consecutive cells. This is better than the route 1->2->2->2->5, where the maximum absolute difference is 3.
Example 2:

Input:
row = 2
columns = 2 
heights = [[7,7],[7,7]]
Output: 
0
Explaination: 
Any route from the top-left cell to the bottom-right cell has a maximum absolute difference of 0 in consecutive cells.
Your Task:
You don't need to read input or print anything. Your task is to complete the function MinimumEffort() which takes intergers rows, columns, and the 2D array heights[][]  and returns the minimum effort required to travel from the top-left cell to the bottom-right cell.

Expected Time Complexity: O(rowsxcolumns)
Expected Space Complexity: O(rowsxcolumns)

Constraints:
1 <= rows, columns <= 100
rows == heights.length
columns == heights[i].length
0 <= heights[i][j] <= 106








###############################################################################  Solution  ###################################################################################################################################
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  bool possible(vector<vector<int>> &height, int k){
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<int>> visited(height.size(), vector<int>(height[0].size(), 0));
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i == height.size()-1 && j == height[0].size() - 1) return true;
            if( i + 1 < height.size() && abs(height[i][j] - height[i+1][j]) <= k && !visited[i+1][j]){
                visited[i+1][j] = 1;
                q.push({i+1, j});
            }
            if( j + 1 < height[0].size() && abs(height[i][j] - height[i][j+1]) <= k && !visited[i][j+1]){
                visited[i][j+1] = 1;
                q.push({i, j+1});
            }
            if( i > 0 && abs(height[i][j] - height[i-1][j]) <= k && !visited[i-1][j]){
                visited[i-1][j] = 1;
                q.push({i-1, j});
            }
            if( j > 0 && abs(height[i][j] - height[i][j-1]) <= k && !visited[i][j-1]){
                visited[i][j-1] = 1;
                q.push({i, j-1});
            }
        }
        return false;
    }
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        int start = 0, end = 1e6, ans = 1e6;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(possible(heights, mid)){
                ans = mid;
                end = mid - 1;
            }else start = mid + 1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends
