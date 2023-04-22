#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class GroupAnagrams {
public:
    static string generateKey(string str) {
        unordered_map<char, int> frequency;
        
        for(char ch = 'a'; ch <= 'z'; ch += 1) {
            frequency[ch] = 0;
        }
        
        for(int i = 0; i < str.length(); i++) {
            frequency[str[i]] += 1;
        }
        
        string key = "#";
        for(char ch = 'a'; ch <= 'z'; ch += 1) {
            key += to_string(frequency[ch]) + "#";
        }
       
        return key;
    }
    
    static vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        
        for(int i = 0; i < strs.size(); i++) {
            string key = generateKey(strs[i]);
            if(map.find(key) == map.end()) {
                map[key] = vector<string>();
            }
            
            map[key].push_back(strs[i]);
        }
        
        for(auto& entry : map) {
            result.push_back(entry.second);
        }
        
        return result;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = GroupAnagrams::groupAnagrams(strs);
    
    for(auto& group : result) {
        cout << "[";
        for(auto& str : group) {
            cout << str << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
