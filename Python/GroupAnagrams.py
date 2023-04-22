from typing import List
from collections import defaultdict

class GroupAnagrams:
    
    @staticmethod
    def generateKey(s: str) -> str:
        frequency = defaultdict(int)
        
        for c in s:
            frequency[c] += 1
            
        key = '#'.join([f"{c}{frequency[c]}" for c in sorted(frequency)])
       
        return key
    
    @staticmethod
    def groupAnagrams(strs: List[str]) -> List[List[str]]:
        result = []
        map = defaultdict(list)
        
        for s in strs:
            key = GroupAnagrams.generateKey(s)
            map[key].append(s)
            
        for k in map:
            result.append(map[k])
            
        return result
    
    @staticmethod
    def main():
        print(GroupAnagrams.groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
        print(GroupAnagrams.groupAnagrams([]))
        print(GroupAnagrams.groupAnagrams(["a"]))

GroupAnagrams.main()
