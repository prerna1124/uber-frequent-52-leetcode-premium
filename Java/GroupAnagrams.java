package Java;
import java.util.*;

public class GroupAnagrams {
    
    public static String generateKey(String str) {
        HashMap<Character, Integer> frequency = new HashMap<>();
        
        for(char ch = 'a'; ch <= 'z'; ch += 1) {
            frequency.put(ch, 0);
        }
        
        for(int i = 0; i < str.length(); i++) {
            frequency.put(str.charAt(i), frequency.get(str.charAt(i)) + 1);
        }
        
        String key = "#";
        for(char ch = 'a'; ch <= 'z'; ch += 1) {
            key += frequency.get(ch) + "#";
        }
       
        return key;
    }
    
    public static List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> result = new ArrayList<>();
        Map<String, ArrayList<String>> map = new HashMap<>();
        
        for(int i = 0; i < strs.length; i++) {
            String key = generateKey(strs[i]);
            if(!map.containsKey(key)) {
                map.put(key, new ArrayList<>());
            }
            
            map.get(key).add(strs[i]);
        }
        
        for(Map.Entry<String, ArrayList<String>> entry : map.entrySet()) {
            result.add(entry.getValue());
        }
        
        return result;
    }

    public static void main(String[] args) {
        System.out.println(groupAnagrams(new String[]{"eat","tea","tan","ate","nat","bat"}));
        System.out.println(groupAnagrams(new String[]{}));
        System.out.println(groupAnagrams(new String[]{"a"}));
    }
}
