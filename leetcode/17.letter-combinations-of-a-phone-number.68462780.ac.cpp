class Solution {
	public:
		char *a[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		string s;
		void dfs(char *c, vector<string> &v) {
			if(!*c) {
				if(s.size() > 0)
					v.push_back(s);
				return;
			}
			for(char *cc = a[*c - '0']; *cc; cc++) {
				s += *cc;
				dfs(c + 1, v);
				s.resize(s.length() - 1);
			}
		}
		vector<string> letterCombinations(string digits) {
			char *c = (char *)digits.c_str();
			vector<string> v;
			dfs(c, v);
			return v;
		}
	};
