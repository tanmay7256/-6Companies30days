bool cmp(vector<string> a, vector<string> b)
{
    if (a[0] < b[0] || (a[0] == b[0] && stoi(a[1]) < stoi(b[1])))
        return 1;
    return 0;
}
class Solution
{
public:
    vector<string> form(string s)
    {
        vector<string> ans;
        string t = "";
        int pos = -1, pre = 0;
        while (pre != s.size())
        {
            pos = s.find(',', pos + 1);
            ans.push_back(s.substr(pre, pos - pre));
            pre = pos + 1;
        }
        return ans;
    }
    vector<string> invalidTransactions(vector<string> &transactions)
    {
        int n = transactions.size();
        vector<string> ans;
        vector<vector<string>> v;
        for (int i = 0; i < n; i++)
        {
            vector<string> t;
            t = form(transactions[i] + ",");
            t.push_back(to_string(i));
            v.push_back(t);
        }
        sort(v.begin(), v.end(), cmp);
        string d = "tanmay", c = "no";
        int time;
        stack<pair<int, pair<string, string>>> st;
        // unordered_map<string,vector<int>> umap;
        unordered_map<string, int> umap;
        for (int i = 0; i < n; i++)
        {
            vector<string> temp = v[i];
            // umap[temp[4]].push_back(i);
            umap[temp[4]] = i;
            if (temp[0] != d)
            {
                d = temp[0];
                while (!st.empty())
                {

                    if (stoi(v[umap[st.top().second.second]][2]) > 1000)
                    {
                        ans.push_back(st.top().second.second);
                    }
                    st.pop();
                }
            }
            int flag = 0;
            while (!st.empty())
            {

                if ((st.top().second.first != temp[3] && stoi(temp[1]) - st.top().first <= 60))
                {

                    ans.push_back(st.top().second.second);
                    st.pop();
                    flag = 1;
                }
                else
                    break;
            }
            if (flag && (((i != n - 1) && v[i + 1][0] != temp[0]) || (i == n - 1)))
                ans.push_back(temp[4]);
            else if (!flag && ((((i != (n - 1)) && v[i + 1][0] != temp[0]) || i == (n - 1)) && stoi(temp[2]) > 1000))
            {
                cout << temp[4] << endl;
                ans.push_back(temp[4]);
                ans.push_back(temp[4]);
            }
            else
            {
                st.push({stoi(temp[1]), {temp[3], temp[4]}});
            }
        }
        while (!st.empty())
        {

            if (stoi(v[umap[st.top().second.second]][2]) > 1000)
            {
                ans.push_back(st.top().second.second);
            }
            st.pop();
        }
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] = transactions[stoi(ans[i])];
        }
        return ans;
    }
};
}
;