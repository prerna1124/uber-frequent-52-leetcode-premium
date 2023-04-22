#include <iostream>
#include <vector>
using namespace std;

class FirstAndLastElement {
public:
    static vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirstOccurance(nums, target, 0, nums.size() - 1);
        int last = findLastOccurance(nums, target, 0, nums.size() - 1);
        
        return vector<int>{first, last};
    }
    
    static int findFirstOccurance(vector<int>& nums, int target, int start, int end) {
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
    
    static int findLastOccurance(vector<int>& nums, int target, int start, int end) {
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
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> res = FirstAndLastElement::searchRange(nums, 8);
    cout << "{" << res[0] << " " << res[1] << "}" << endl;
    res = FirstAndLastElement::searchRange(nums, 6);
    cout << "{" << res[0] << " " << res[1] << "}" << endl;
    nums = {};
    res = FirstAndLastElement::searchRange({nums}, 0);
    cout << "{" << res[0] << " " << res[1] << "}" << endl;
    return 0;
}
