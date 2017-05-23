class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        str_list = s.strip().split(' ')
        if len(str_list) == 0:
            return 0
        return len(str_list[len(str_list) - 1])