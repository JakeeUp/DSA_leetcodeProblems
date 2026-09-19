class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i,r = 0,0
        word = []
        while i < len(word1) and r < len(word2):
            word.append(word1[i]) 
            word.append(word2[r])
            i += 1
            r += 1

        word.append(word1[i:]) 
        word.append(word2[r:]) 
        return "".join(word)
         

      
       
      




        

        