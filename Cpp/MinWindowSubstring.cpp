#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class MinWindowSubstring {
public:
    static string minWindow(string s, string t) {
        unordered_map<char, int> tFreq;
        for (char ch : t) {
            tFreq[ch]++;
        }

        int start = 0, matched = 0, length = INT_MAX;
        string result = "";
        for (int end = 0; end < s.length(); end++) {
            char ch = s[end];
            if (tFreq.count(ch)) {
                tFreq[ch]--;
                if (tFreq[ch] >= 0) {
                    matched++;
                }
            }

            while (matched == t.length()) {
                if (length > end - start + 1) {
                    result = s.substr(start, end - start + 1);
                    length = end - start + 1;
                }
                char startChar = s[start++];
                if (tFreq.count(startChar)) {
                    if (tFreq[startChar] == 0) {
                        matched--;
                    }
                    tFreq[startChar]++;
                }
            }
        }

        return result;
    }
};

int main() {
    cout << MinWindowSubstring::minWindow("abcddabca", "acba") << endl;
    cout << MinWindowSubstring::minWindow("aabedc", "abc") << endl;
    return 0;
}
