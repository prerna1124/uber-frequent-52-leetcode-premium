package Java;

class FirstAndLastElement {
    public static int[] searchRange(int[] nums, int target) {
        int first = findFirstOccurance(nums, target, 0, nums.length - 1);
        int last = findLastOccurance(nums, target, 0, nums.length - 1);
        
        return new int[]{first, last};
    }
    
    public static int findFirstOccurance(int[] nums, int target, int start, int end) {
        int index = -1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) {
                end = mid - 1;
                index = mid;
            } else if(nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return index;
    }
    
    public static int findLastOccurance(int[] nums, int target, int start, int end) {
        int index = -1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] == target) {
                start = mid + 1;
                index = mid;
            }else if(nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return index;
    }

    public static void main(String[] args) {
        int[] res = searchRange(new int[] {5,7,7,8,8,10}, 8);
        System.out.println("{"+res[0] +" " + res[1]+"}");
        res = searchRange(new int[] {5,7,7,8,8,10}, 6);
        System.out.println("{"+res[0] +" " + res[1]+"}");
        res = searchRange(new int[] {}, 0);
        System.out.println("{"+res[0] +" " + res[1]+"}");
    }
}
