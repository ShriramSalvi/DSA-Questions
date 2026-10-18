
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> visited(
            n, vector<int>(m, INT_MAX)
        );

        // {gap, vertex, row, col}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > minheap;

        visited[0][0] = 0;

        minheap.push({0, heights[0][0], 0, 0});

        while (!minheap.empty()) {

            auto temp = minheap.top();
            minheap.pop();

            int gap = temp[0];
            int vertex = temp[1];
            int row = temp[2];
            int col = temp[3];

            if (visited[row][col] > gap)
                continue;

            // Going right
            if (col + 1 < m &&
                visited[row][col + 1] >
                max(gap, abs(vertex - heights[row][col + 1]))) {

                visited[row][col + 1] =
                    max(gap, abs(vertex - heights[row][col + 1]));

                minheap.push({
                    visited[row][col + 1],
                    heights[row][col + 1],
                    row,
                    col + 1
                });
            }

            // Going left
            if (col - 1 >= 0 &&
                visited[row][col - 1] >
                max(gap, abs(vertex - heights[row][col - 1]))) {

                visited[row][col - 1] =
                    max(gap, abs(vertex - heights[row][col - 1]));

                minheap.push({
                    visited[row][col - 1],
                    heights[row][col - 1],
                    row,
                    col - 1
                });
            }

            // Going up
            if (row - 1 >= 0 &&
                visited[row - 1][col] >
                max(gap, abs(vertex - heights[row - 1][col]))) {

                visited[row - 1][col] =
                    max(gap, abs(vertex - heights[row - 1][col]));

                minheap.push({
                    visited[row - 1][col],
                    heights[row - 1][col],
                    row - 1,
                    col
                });
            }

            // Going down
            if (row + 1 < n &&
                visited[row + 1][col] >
                max(gap, abs(vertex - heights[row + 1][col]))) {

                visited[row + 1][col] =
                    max(gap, abs(vertex - heights[row + 1][col]));

                minheap.push({
                    visited[row + 1][col],
                    heights[row + 1][col],
                    row + 1,
                    col
                });
            }
        }

        return visited[n - 1][m - 1];
    }
};
