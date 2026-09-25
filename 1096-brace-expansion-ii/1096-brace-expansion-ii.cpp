class Solution {
public:

    set<string> dfs(string& s, int& i) {

        set<string> result;
        set<string> current = {""};

        while(i < s.size() && s[i] != '}') {

            if(s[i] == ',') {
                // Union
                for(string str : current)
                    result.insert(str);

                current = {""};
                i++;
            }

            else if(s[i] == '{') {
                i++; // skip '{'

                set<string> inside = dfs(s, i);

                // Skip '}'
                i++;

                // Concatenate current × inside
                set<string> next;

                for(string a : current) {
                    for(string b : inside) {
                        next.insert(a + b);
                    }
                }

                current = next;
            }

            else {
                // Normal character
                char c = s[i];

                set<string> next;

                for(string str : current) {
                    next.insert(str + c);
                }

                current = next;

                i++;
            }
        }

        // Add final part
        for(string str : current)
            result.insert(str);

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = dfs(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};