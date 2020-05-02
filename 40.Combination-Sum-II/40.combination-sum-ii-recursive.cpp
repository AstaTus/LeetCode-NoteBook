/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// #include <gtest/gtest.h>

// @lc code=start
#include<vector>
// #include <map>
// #include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,ans,v,0,target);
        return ans;
    }
    void backtrack(vector<int>& candidates, vector<vector<int>> &ans, vector<int> &v,int start, int target){
        if(target==0){
            ans.push_back(v);
            return ;
        }
        for(int i=start;i<candidates.size() && candidates[i]<=target;i++){
            if (/* condition */)
            {
                /* code */
            }
            
            v.push_back(candidates[i]);
            backtrack(candidates,ans,v,i+1,target-candidates[i]);
            while (i+1<candidates.size() && candidates[i + 1]==candidates[i])
                i++;
            v.pop_back();
        }
    }
};
// @lc code=end

// TEST(XieXing, GanSi)
// {

// }

int main(int argc, char **argv)
{
    // printf("asdasdsada");
    //testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
    vector<int> params = vector<int>{1,1,2,1,1,2,1,1,1,1};
    vector<vector<int>> r = (Solution().combinationSum2(params, 7));

    return 0;
}

