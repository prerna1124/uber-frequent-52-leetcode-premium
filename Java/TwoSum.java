/*  
 *  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. 
 *  You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *  You can return the answer in any order.
 */

package Java;
import java.util.HashMap;

public class TwoSum {

    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(int i = 0; i < nums.length; i++) {
            if(map.containsKey(target - nums[i])) {
                return new int[]{map.get(target - nums[i]), i};
            }
            map.put(nums[i], i);
        }
        return new int[]{-1, -1};
    }

    public static void main(String[] args) {
        int[] res = twoSum(new int[] {2,7,11,15}, 9);
        System.out.println("{"+res[0] +" " + res[1]+"}");

        res = twoSum(new int[] {3, 2, 4}, 6);
        System.out.println("{"+res[0] +" " + res[1]+"}");

        res = twoSum(new int[] {3, 3}, 6);
        System.out.println("{"+res[0] +" " + res[1]+"}");

    }
}