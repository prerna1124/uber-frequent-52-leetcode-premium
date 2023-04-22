#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(target - nums[i])) {
                return {mp[target - nums[i]], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main() {
    TwoSum obj;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = obj.twoSum(nums, target);
    cout << "{" << res[0] << " " << res[1] << "}" << endl;
    
    nums = {3, 2, 4};
    target = 6;
    res = obj.twoSum(nums, target);
    cout << "{" << res[0] << " " << res[1] << "}" << endl;
    
    nums = {3, 3};
    target = 6;
    res = obj.twoSum(nums, target);
    cout << "{" << res[0] << " " << res[1] << "}" << endl;
    return 0;
}
