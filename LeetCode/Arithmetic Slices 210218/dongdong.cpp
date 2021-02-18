class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {

		vector<pair<int, int>> a; // (ù index, �� index ���)
		vector<int> diff; // A ���Ϳ��� ���� ���� �� ����ֱ�
		int answer = 0;

		// ���ӵ� 3���̻��� �����϶�,
		if (A.size() >= 3) {
			// ���̸� ���ؼ� ���ο� ���Ϳ� �ְ�
			for (int i = 0; i < A.size() - 1; i++) {
				diff.push_back(A[i + 1] - A[i]);
			}

			// �ű⼭ ���ӵ� ���� ������ �� �ε����� �������� ���� ��
			int diff_num = diff[0];
			int start = 0;
			int check = 0;
			for (int i = 1; i < diff.size(); i++) {
				if (diff[i] == diff_num) {
					check++;
					if (i == diff.size() - 1) {
						if (check >= 1) {
							a.push_back(make_pair(start, i));
							check = 0;
						}
					}
				}
				else {
					if (check >= 1) {
						a.push_back(make_pair(start, i - 1));
					}
					start = i;
					check = 0;
					diff_num = diff[i];
				}
			}

			// ����� �� ���ϱ�. ���ӵȼ� 5 ���� 3��¥�� 3�� 4��¥�� 2�� 5��¥�� 1�� �̷� ���¸� ��.
			for (int i = 0; i < a.size(); i++) {
				int x1 = a[i].first;  // ������ �迭�� ù �ε���
				int x2 = a[i].second + 1; // ������ �迭�� ������ �ε���

				for (int j = 3; j <= x2 - x1 + 1; j++) {
					answer += (x2 - x1 + 1) - j + 1;
				}
			}
		}
		else {
			// �迭 3�� �̸��Ͻ� ������ �迭�� ���� �� ����.
			return 0;
		}

		return answer;
	}
};