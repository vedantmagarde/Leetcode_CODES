class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open_st;
        stack<int> star_st;
        int i = 0;
        int n = s.length();
        while (i < n) {
            if (s[i] == ')') {
                if (!open_st.empty()) {
                    open_st.pop();
                } else {
                    if (!star_st.empty())
                        star_st.pop();
                    else
                        return false;
                }
            } else if (s[i] == '(') {
                open_st.push(i);
            } else {

                star_st.push(i);
            }
            i++;
        }

        while (!star_st.empty() && !open_st.empty()&&open_st.top()<star_st.top()) {
            open_st.pop();
            star_st.pop();
        }

        return open_st.empty();
    }
};