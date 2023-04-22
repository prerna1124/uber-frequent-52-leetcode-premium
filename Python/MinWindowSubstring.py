class MinWindowSubstring:
    @staticmethod
    def minWindow(s: str, t: str) -> str:
        tFreq = {}
        for ch in t:
            tFreq[ch] = tFreq.get(ch, 0) + 1

        start, matched, length = 0, 0, float('inf')
        result = ""
        for end in range(len(s)):
            ch = s[end]
            if ch in tFreq:
                tFreq[ch] -= 1
                if tFreq[ch] >= 0:
                    matched += 1

            while matched == len(t):
                if length > end - start + 1:
                    result = s[start:end + 1]
                    length = end - start + 1
                startChar = s[start]
                start += 1
                if startChar in tFreq:
                    if tFreq[startChar] == 0:
                        matched -= 1
                    tFreq[startChar] += 1

        return result


print(MinWindowSubstring.minWindow("abcddabca", "acba"))
print(MinWindowSubstring.minWindow("aabedc", "abc"))
