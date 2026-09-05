class Solution:
    def isValid(self, s: str) -> bool:
        if not s:
            return True

        if s[0] == ")" or s[0] == "]" or s[0] == "}":
            return False

        st = []

        for temp in s:

            if temp == "(" or temp == "{" or temp == "[":
                st.append(temp)
            elif temp == ')' or temp == ']' or temp == '}':
                if not st:
                    return False

                top=st[-1]

                if(temp == ')' and top == '(' ) or \
                    (temp == '}' and top == '{' ) or \
                    (temp == ']' and top == '[' ) :
                        st.pop()
                else:
                    return False

        return not st
