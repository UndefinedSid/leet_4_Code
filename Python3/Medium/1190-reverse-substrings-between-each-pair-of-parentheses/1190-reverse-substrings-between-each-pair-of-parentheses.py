class Solution:
    def reverseParentheses(self, s: str) -> str:
        n=len(s)
        st=[]
        for ch in s:
            if ch== ")":
                parts=[]
                while st and st[-1] != "(" :
                    parts.append(st.pop())

                st.pop()

                st.extend(parts)
            else:
                st.append(ch)

        print(st)

        return "".join(st)

