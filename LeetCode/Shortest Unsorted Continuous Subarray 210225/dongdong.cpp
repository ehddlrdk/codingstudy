class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		// �����ѰŶ� nums�� ���ؼ� �� ó������ �ٸ��� start ���������� �ٸ��� end�ؼ� ���
		int start = -1;
		int end = -1;

		vector<int> sort_nums = nums;
		sort(sort_nums.begin(), sort_nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != sort_nums[i]) {
				if (start == -1)
					start = i;
				end = i;
			}
		}

		if (start == -1 && end == -1)
			return 0;

		return end - start + 1;
	}
};