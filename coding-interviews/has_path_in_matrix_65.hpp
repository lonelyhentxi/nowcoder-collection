// [矩阵中的路径](https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc)
#pragma once
#define let const auto
#include <vector>
#include <string>

namespace task65 {
    using namespace std;
    class Solution {
    public:
        bool hasPath(char* matrix, int rows, int cols, char* str)
        {
            string target{ str };
            if(target.empty())
            {
                return true;
            }
            if(rows * cols==0)
            {
                return false;
            }
            auto valid_chars = vector<bool>(256, false);
            for(let ch: target)
            {
                valid_chars[static_cast<size_t>(ch)] = true;
            }
            auto invalid_pos = vector<bool>(rows * cols, false);
            for(auto i=0;i<rows;i++)
            {
                for(auto j=0;j<cols;j++)
                {
                    invalid_pos[xy2pos(rows, cols, i, j)] = !valid_chars[static_cast<size_t>(matrix[xy2pos(rows, cols, i, j)])];
                }
            }
            for(auto i=0;i<rows;i++)
            {
                for(auto j=0;j<cols;j++)
                {
                    if (has_path_dfs(matrix, rows, cols, i, j, target, 0, invalid_pos))
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        bool has_path_dfs(char* matrix, int rows, int cols, int x, int y, const string& target, int read, vector<bool> visited)
        {
            if(!valid_pos(rows, cols, x, y, visited))
            {
                return false;
            }
            if(matrix[xy2pos(rows, cols, x, y)]!=target[read])
            {
                return false;
            }
            visited[xy2pos(rows, cols, x, y)] = true;
            if(read+1==target.size())
            {
                return true;
            }
            return (
                    has_path_dfs(matrix, rows, cols, x, y+1, target, read+1, visited) ||
                    has_path_dfs(matrix, rows, cols, x, y - 1, target, read + 1, visited) ||
                    has_path_dfs(matrix, rows, cols, x + 1, y, target, read + 1, visited) ||
                    has_path_dfs(matrix, rows, cols, x - 1, y, target, read + 1, std::move(visited))
            );
        }

        inline int xy2pos(int rows, int cols, int x, int y)
        {
            return x * cols + y;
        }

        inline bool valid_pos(int rows, int cols, int x, int y, const vector<bool>& visited)
        {
            return (x >= 0 && y >= 0 && x < rows && y < cols && !visited[xy2pos(rows, cols, x, y)]);
        }
    };
}
