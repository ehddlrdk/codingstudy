class Solution {
public:
	vector<string> answer;
	string str;

	void Combination(vector<pair<char, int>> alpha, vector<pair<char, int>> com, int depth, int next) {

		// Ż������. index�� ���� ������ ������ 
		if (depth == com.size()) {
			string permutation = str;
			for (int i = 0; i < com.size(); i++) {
				// cout << com[i].first << " ";
				// �빮�ڴ� �ҹ��ڷ�, �ҹ��ڴ� �빮�ڷ� ����.
				if (isupper(com[i].first))
					permutation[com[i].second] = tolower(com[i].first);
				if (islower(com[i].first))
					permutation[com[i].second] = toupper(com[i].first);
			}
			answer.push_back(permutation);
			// cout << endl;
			return;
		}
		else {
			// ��� �������� ����ã��. 
			for (int i = next; i < alpha.size(); i++) {
				com[depth].first = alpha[i].first;
				com[depth].second = alpha[i].second;
				Combination(alpha, com, depth + 1, i + 1);
			}
		}
	}

	vector<string> letterCasePermutation(string S) {
		vector<pair<char, int>> alpha; // S���� �̾Ƴ� ���ĺ� ����
		vector<pair<char, int>> com; // alpha���� �̾Ƴ� ���� ����
		str = S;
		// S���� ���ĺ��� ��� index�� ���ĺ� ����.
		for (int i = 0; i < S.size(); i++) {
			if (isalpha(S[i])) {
				alpha.push_back(make_pair(S[i], i));
			}
		}

		// 0 ~ S���� �̾Ƴ� ���ĺ� �������� ���յ�����.
		for (int i = 0; i <= alpha.size(); i++) {
			com.resize(i);
			Combination(alpha, com, 0, 0);
		}


		// Combination(alpha, com, 0, 0);

		return answer;
	}
};