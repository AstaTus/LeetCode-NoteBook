/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// #include <gtest/gtest.h>

// @lc code=start
#include<vector>
#include <map>
#include<algorithm>

using namespace std;

class Solution {
private:
        map<int, vector<vector<int>>> combination_map;
        map<int, vector<vector<int>>> temp_combination_map;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combination_map.clear();
        temp_combination_map.clear();
        for (size_t i = 0; i < candidates.size(); i++)
        {
            temp_combination_map.clear();
            int current;
            if (candidates[i] > target)
            {
               continue;
            }

            for(auto itr = combination_map.begin(); itr!= combination_map.end(); itr++) {
                current = itr->first + candidates[i];
                if (current > target)
                {
                    continue;
                }
                else {
                    vector<vector<int>> current_combinations = itr->second;
                    for (auto current_itr = current_combinations.begin(); current_itr != current_combinations.end(); current_itr++)
                    {
                        current_itr->push_back(candidates[i]);
                    }
                    add_element(current, current_combinations);
                }
            }

            vector<vector<int>> r = vector<vector<int>>{vector<int>{candidates[i]}};
            add_element(candidates[i], r);

            for (auto itr = temp_combination_map.begin(); itr!= temp_combination_map.end(); itr++)
            {
                if (combination_map.find(itr->first) == combination_map.end())
                {
                    combination_map[itr->first] = temp_combination_map[itr->first];
                } else {
                    combination_map[itr->first].insert(combination_map[itr->first].end(), temp_combination_map[itr->first].begin(), temp_combination_map[itr->first].end());
                }
            }

            // combination_map.insert(temp_combination_map.begin(), temp_combination_map.end());
            temp_combination_map.clear();      
        }

        //remove duplicate
        vector<vector<int>> results;
        bool is_equal = false;
        for (auto itr = combination_map[target].begin(); itr != combination_map[target].end(); itr++)
        {
            is_equal = false;
            for (size_t i = 0; i < results.size(); i++)
            {
                is_equal = is_equal_vec(results[i], (*itr));
                if (is_equal)
                {
                    break;
                }
            }

            if (!is_equal)
            {
                results.push_back(*itr);
            }
        }
        
        return results;
    }

private:
    bool is_equal_vec(vector<int>& l, vector<int>& r) {
        if (l.size() == r.size())
        {
            for (size_t i = 0; i < l.size(); i++)
            {
                if(l[i] != r[i]) {
                    return false;
                }
            }

            return true;
        }

        return false;
        
    } 
    void add_element(int target, vector<vector<int>>& r) {
        temp_combination_map[target].insert(temp_combination_map[target].end(), r.begin(), r.end());
    }
};
// @lc code=end

// TEST(XieXing, GanSi)
// {

// }

int main(int argc, char **argv)
{
    printf("asdasdsada");
    //testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
    vector<int> params = vector<int>{10,1,2,7,6,1,5};
    vector<vector<int>> r = (Solution().combinationSum2(params, 8));

    return 0;
}

