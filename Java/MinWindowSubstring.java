package Java;
import java.util.*;

class MinWindowSubstring {
    public static String minWindow(String s, String t) {
        HashMap<Character, Integer> tFreq = new HashMap<>();
        for(char ch : t.toCharArray()) {
            tFreq.put(ch, tFreq.getOrDefault(ch, 0) + 1);
        }

        int start = 0, matched = 0, length = Integer.MAX_VALUE;
        String result = "";
        for(int end = 0; end < s.length(); end++) {
            char ch = s.charAt(end);
            if(tFreq.containsKey(ch)) {
                tFreq.put(ch, tFreq.get(ch) - 1);
                if(tFreq.get(ch) >= 0) {
                    matched++;
                }
            }

            while(matched == t.length()) {
                if(length > end - start + 1) {
                    result = s.substring(start, end + 1);
                    length = end - start + 1;
                }
                char startChar = s.charAt(start++);
                if(tFreq.containsKey(startChar)) {
                    if(tFreq.get(startChar) == 0)
                        matched--;
                    tFreq.put(startChar, tFreq.get(startChar) + 1);
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        System.out.println(minWindow("abcddabca", "acba"));
        System.out.println(minWindow("aabedc", "abc"));
    }
}
