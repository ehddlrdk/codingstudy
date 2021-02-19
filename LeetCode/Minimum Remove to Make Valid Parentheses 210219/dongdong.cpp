class Solution {
public:
	string minRemoveToMakeValid(string s) {
		// stack��( ( or ), index)�� pair�� �ϳ��� �ְ�, ���������� �����ִ¾� �����ϰ� string�����ϸ� ��.  
		stack<pair<char, int>> c;
		string answer;

		// ������ ����. stirng������ ������, 
		for (int i = 0; i < s.size(); i++) {
			if (!c.empty()) {
				if (s[i] == ')') {
					if (c.top().first == '(') {
						c.pop();
					}
					else {
						c.push(make_pair(s[i], i));
					}
				}
				else if (s[i] == '(') {
					c.push(make_pair(s[i], i));
				}
			}
			else {
				if (s[i] == '(' || s[i] == ')')
					c.push(make_pair(s[i], i));
			}
		}

		// ���ÿ� �����ִ� ( or ) �� �����ϱ� ���ؼ�. 
		while (!c.empty()) {
			s.replace(c.top().second, 1, "");
			c.pop();
		}

		return s;
	}
};