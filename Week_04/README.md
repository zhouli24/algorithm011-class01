学习笔记

使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方

思路：
按照常规二分查找的算法，不同点是不比较中间值与目标值。找无序的地方，就是用nums[mid]与两边的值比较，
半有序数组，前后两部分都是非递减，只有中间开始的位置有变化。满足条件：nums[mid]<nums[mid-1]，mid为
无序开始的位置；nums[mid ]>nums[mid+1], mid+1为无序开始的位置。

左右边界变化规则，中间值与nums[right]比较，当nums[mid] > nums[right],说明mid位于左有序部分，left=mid+1;
否则，位于右有序部分，right=mid-1.
class Solution {
    public int findMin(int[] nums) {
        int left, mid, right;
        if (nums.length == 0)
            return -1;

        left = 0;
        right = nums.length - 1;
        
        if (nums[right] >= nums[0])
            return 0;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if ((mid - 1 >= 0) && (nums[mid - 1] > nums[mid])) {
                return mid;
            }

            if (((mid + 1) <= nums.length - 1) && (nums[mid] > nums[mid + 1])) {
                return mid + 1;
            }

            if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}

看到还有如下方法，理解比较模糊，不是很明白，为什么能想到这种解法：
public class Solution {
    public int findMin(int[] nums) {

        int left, mid, right;

        left = 0;
        right = nums.length - 1;

        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
		
		return left;
    }
}