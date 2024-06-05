class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        return reduce(and_, map(Counter, words)).elements()
        