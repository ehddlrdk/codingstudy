class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		// pushed�� �ִ°� ���ÿ� ������� �����鼭 popped���� ù index���� Ȯ���ذ��� pop�غ���. 
		// ������ ture �ٸ��� false
		stack<int> s;
		int push_index = 0;
		int pop_index = 0;

		// pushed�� ���Ҹ� ���ÿ� �� ���� ������
		while (push_index != pushed.size()) {

			if (!s.empty() && s.top() == popped[pop_index]) {
				// pop �� ���� pop_index�� �ش��ϴ°� ���ÿ� �־����ִ� �������� �Ǵ�.
				s.pop();
				pop_index++;
			}
			else if (pushed[push_index] == popped[pop_index]) {
				// pushed�� ���Ұ� pop�ؾ� �� �����̸� pop
				pop_index++;
				push_index++;
			}
			else if (pushed[push_index] != popped[pop_index]) {
				// pushed�� ���Ұ� pop�ؾ� �� ������ �ƴϸ� push
				s.push(pushed[push_index]);
				push_index++;
			}
		}

		while (!s.empty()) {
			// ���ÿ� �����ִ°� pop���� �� popped�� ���ҿ� ������ �Ǵ�. 
			int pop_num = s.top();
			if (pop_num != popped[pop_index]) {
				return false;
			}
			s.pop();
			pop_index++;
		}

		return true;


	}
};