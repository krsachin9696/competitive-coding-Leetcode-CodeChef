class Solution
{
public:
    string removeStars(string s)
    {
        int n = s.length();
        if (n == 0)
        {
            return s;
        }

        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
                continue;
            }

            if (s[i] == '*')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};