class Solution {
public:
	int brokenCalc(int X, int Y) {
		// �ּұ��� Ž��. 
		// x�������� �ϸ� �ð��ʰ� y ��������.
		queue<pair<int, int>> cal;
		cal.push(make_pair(Y, 0));

		while (!cal.empty()) {
			int y = cal.front().first;
			int count = cal.front().second;
			cal.pop();
			if (y < X)
				return count + X - y;
			if (y == X)
				return count;
			if (y % 2 == 0)
				cal.push(make_pair(y / 2, count + 1));
			else
				cal.push(make_pair(y + 1, count + 1));
		}
		return 0;
	}
};