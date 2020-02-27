// [二维数组中的查找](https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e)
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        size_t rows = array.size();
        if (rows == 0) {
            return false;
        }
        size_t cols = array[0].size();
        if (cols == 0) {
            return false;
        }
        auto i = rows - 1;
        auto j = 0;
        do {
            const auto val = array[i][j];
            if (val == target) {
                return true;
            } else if (val > target) {
                if (i == 0) return false;
                i = i - 1;
            } else if (val < target) {
                if (j == cols - 1) return false;
                j = j + 1;
            }
        } while (true);
    }
};