/**
 * Created by loccs on 6/12/17.
 */
public class Solution {
    public static int searchInsert(int[] nums, int target) {
       if (0==nums.length) {
           return 0;
       }

       int lo = 0, hi = nums.length-1;
       int mid;
       while (lo<=hi) {
           mid = (lo+hi)/2;
           if (nums[mid]<target) {
               lo = mid+1;
           }else if (nums[mid]>target) {
               hi = mid-1;
           }else {
               lo = mid;
               break;
           }
       }

       return lo;
    }

    public static void main(String[] args) {
       int[] nums = {1,3,5,6};

        System.out.println(searchInsert(nums,5));
        System.out.println(searchInsert(nums,2));
        System.out.println(searchInsert(nums,7));
        System.out.println(searchInsert(nums,0));
    }
}
