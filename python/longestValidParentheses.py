# Problem Statement:- https://leetcode.com/problems/longest-valid-parentheses/



def longestValidParentheses(self, s):
  
        if len(s) == 1 or len(s) == 0:
            return 0
        else:
            n = len(s)
            l = [0]*n
            for i in range(0,len(s)):
            
                if s[i] == '(':
                    l[i] = 0
                else:
                    if i-1>=0 and s[i-1] == '(':
                        if i-2>=0:
                            l[i] = l[i-2]+2
                        elif i-2<0:
                            l[i] = 2
                    elif i-1>=0 and s[i-1] == ')':
                        if i-l[i-1] >0 and s[i-l[i-1]-1] == '(':
                            l[i] = l[i-1]+2+l[i-l[i-1]-2]
                        

                    else:
                        l[i] = 0
            return max(l)
