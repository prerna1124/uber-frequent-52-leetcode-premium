from typing import List

class TextJustification:
    @staticmethod
    def processLineWithKWords(currLine: List[str], currWidth: int, maxWidth: int, result: List[str]) -> None:
        whiteSpaces = maxWidth - currWidth
        evenSpaces = whiteSpaces // (len(currLine) - 1)
        unevenSpaces = whiteSpaces % (len(currLine) - 1)

        word = 0

        #Distribute spaces evenly
        while(word < len(currLine) - 1):
            spaces = 0
            while(spaces < evenSpaces):
                currLine[word] = currLine[word] + " "
                spaces += 1
            word += 1

        #left must have extra spaces
        word = 0
        while(unevenSpaces > 0):
            currLine[word] = currLine[word] + " "
            word += 1
            unevenSpaces -= 1

        tempRes = ""
        for k in range(len(currLine)):
            if(k == 0):
                tempRes += currLine[k]
            else:
                tempRes = tempRes + " " + currLine[k]

        result.append(tempRes)

    @staticmethod
    def processLineWithOneWord(currLine: List[str], currWidth: int, maxWidth: int, result: List[str]) -> None:
        whiteSpaces = maxWidth - currWidth
        tempRes = currLine[0]
        while(whiteSpaces > 0):
            tempRes += " "
            whiteSpaces -= 1
        result.append(tempRes)

    @staticmethod
    def processLastLine(currLine: List[str], currWidth: int, maxWidth: int, result: List[str]) -> None:
        whiteSpaces = maxWidth - currWidth
        tempRes = currLine[0]

        if(len(currLine) > 1):
            for i in range(1, len(currLine)):
                tempRes += " " + currLine[i]

        while(whiteSpaces > 0):
            tempRes += " "
            whiteSpaces -= 1

        result.append(tempRes)


    @staticmethod
    def fullJustify(words: List[str], maxWidth: int) -> List[str]:
        result = []
        currLine = []
        currWidth = 0
        for i in range(len(words)):

            #calculate currWidth and see if this line can accomodate currWord
            value = len(words[i]) if not currLine else (currWidth + len(words[i]) + 1)

            if(value <= maxWidth):
                currLine.append(words[i])
                currWidth = value
            else:

                if(len(currLine) > 1):
                    TextJustification.processLineWithKWords(currLine, currWidth, maxWidth, result)
                else:
                    TextJustification.processLineWithOneWord(currLine, currWidth, maxWidth, result)

                currLine = []
                currLine.append(words[i])
                currWidth = len(words[i])

        TextJustification.processLastLine(currLine, currWidth, maxWidth, result)

        return result

print(TextJustification.fullJustify(["This", "is", "an", "example", "of", "text", "justification."], 16))
print(TextJustification.fullJustify(["What","must","be","acknowledgment","shall","be"], 16))
print(TextJustification.fullJustify(["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], 20))
