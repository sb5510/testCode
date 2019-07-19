//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
class Solution {
public:
//动态规划
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int *dp = new int[nums.size()]();
        dp[0] = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            if(dp[i-1]<0)
                dp[i] = nums[i];
            else
                dp[i] = nums[i] + dp[i-1];
            result = max(result,dp[i]);
        }
        return result;
    }
	//贪心
	int maxSubArray2(vector<int>& nums) {
        int temp = 0;
        int result = INT_MIN;
        for(int i = 0;i<nums.size();i++)
        {
            if(temp<0)
            {
                temp = nums[i];
            }
            else
            {
                temp+=nums[i];
            }
            result = max(result,temp);
        }
        return result;
    }
};