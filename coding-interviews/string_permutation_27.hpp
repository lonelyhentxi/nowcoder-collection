// [字符串的排列](https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7)

#include <set>
#include <string>
#include <vector>
#define let const auto

namespace task27 {
 using namespace std;
    class Solution {
    public:
        vector<string> Permutation(const string& str) {
            auto res = set<string>{};
            permute_rec({}, res, vector<bool>(str.size(), false), 0, str);
            res.erase("");
            return vector<string>{res.begin(), res.end()};
        }

        void permute_rec(const string &added, set<string>& permutation, vector<bool> visited, int level, const string& elems) {
            if(level==elems.size()) {
                permutation.insert(added);
            }
            else {
                for(auto i=0;i<elems.size();i++) {
                    if(!visited[i]) {
                        auto added_copy = added;
                        added_copy.push_back(elems[i]);
                        auto visited_copy = visited;
                        visited_copy[i] = true;
                        permute_rec(added_copy, permutation, visited_copy, level+1, elems);
                    }
                }
            }
        }
    };
}