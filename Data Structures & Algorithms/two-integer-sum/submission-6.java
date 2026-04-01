class Solution 
{
    public int[] twoSum(int[] nums, int target)
    {
        int[] result = new int[2];
        for(int i = 0; i < nums.length; i++)
        {
                    // System.out.println("i is " + i +" and len "+nums.length);
            for(int j = i+1; j < nums.length; j++)
            {
                // System.out.println("j is " + j +" and len "+nums.length);
                if(nums[i] + nums[j] == target)
                {
                    result[0] = i;
                    result[1] = j;
                }
            }
        }
        return result;
    }
}
/*
5,5,5,5,3,4,5,6
4,5

*/