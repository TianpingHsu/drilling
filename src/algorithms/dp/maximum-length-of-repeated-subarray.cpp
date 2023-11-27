#include "utils.h"

// https://leetcode.cn/problems/maximum-length-of-repeated-subarray/

static int memo[1024][1024];

// code below solves *maximum_length_of_repeated_subsequence*, take cate `subarray` and `subsequence`
int maximum_length_of_repeated_subarray(vector<int>& nums1, vector<int>& nums2) {
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++){
            memo[i][j] = 0;
        }
    }

    for (int i = 0; i < nums1.size(); i++) {
        if (nums1[i] == nums2[0]) memo[i][0] = 1;
    }
    for (int i = 0; i < nums2.size(); i++) {
        if (nums2[i] == nums1[0]) memo[0][i] = 1;
    }
    //SHOW2D(memo, nums1.size(), nums2.size());

    int ans = 0;
    for (int i = 1; i < nums1.size(); i++) {
        for (int j = 1; j < nums2.size(); j++) {
            if (nums1[i] == nums2[j]) memo[i][j] = memo[i - 1][j - 1] + 1;
            else {
                memo[i][j] = 0;
            }
            if (ans < memo[i][j]) ans = memo[i][j];
        }
    }
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            if (ans < memo[i][j]) ans = memo[i][j];
        }
    }


    return ans;
    //return memo[nums1.size() - 1][nums2.size() - 1];
}

/*
int maximum_length_of_repeated_subarray(vector<int>& nums1, vector<int>& nums2) {
    bool flag = false;
    for (int i = 0; i <= nums1.size(); i++) {
        flag = false;
        for (int j = 0; j <= nums2.size(); j++){
            memo[i][j] = 0;
            if (i == 1) {
                if (flag) memo[i][j] = 1;
                else {
                    if (nums1[i] == nums2[j]) {
                        memo[i][j] = 1;
                        flag = true;
                    }
                }
            }
        }
    }
    flag = false;
    for (int j = 1; j <= nums2.size(); j++) {
        if (flag) {
            memo[1][j] = 1;
            continue;
        }
        if (nums2[j] == nums1[0]) {
            flag = true;
            memo[1][j] = 1;
        }
    }

}
*/

int findLength(vector<int>& nums1, vector<int>& nums2) {
    return  maximum_length_of_repeated_subarray(nums1, nums2);
}

TEST_CASE("DP with findLength", "[.][findLength]") {
    vector<int> nums1, nums2;
    {
        nums1 = createVector("[1,2,3,2,1]");
        nums2 = createVector("[3,2,1,4,7]");
        REQUIRE(findLength(nums1, nums2) == 3);
    }
    {
        nums1 = createVector("[0,0,0,0,0]");
        nums2 = createVector("[0,0,0,0,0]");
        REQUIRE(findLength(nums1, nums2) == 5);
    }
    {
        nums1 = createVector("[0,1,1,1,1]");
        nums2 = createVector("[1,0,1,0,1]");
        REQUIRE(findLength(nums1, nums2) == 2);
    }

    {
        nums1 = createVector("[1,2,3,2,8]");
        nums2 = createVector("[5,6,1,4,7]");
        REQUIRE(findLength(nums1, nums2) == 1);
    }
}

