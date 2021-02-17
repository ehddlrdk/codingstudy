class Solution {
public:
	int maxArea(vector<int>& height) {
		int x1 = 0;
		int x2 = height.size() - 1;
		int max = 0;
		int area = 0;


		// ù �ε����� �������� ��� �� �� ���� ���� ū �� ���. ==> �ð��ʰ���.
		// for(int i = 0; i < area.size(); i++) {
		//     int y1 = area[i].first;
		//     int x1 = area[i].second;
		//     for(int j = i + 1; j < area.size(); j++ ) {
		//         int y2 = area[j].first;
		//         int x2 = area[j].second;
		//         int max = y1 * abs(x2 - x1);
		//         if (area_max < max ) {
		//             area_max = max;
		//         }
		//     }
		// }

		// ����⿡�� ��
		while (x1 < x2) {
			// x1���̰� x2 ���̺��� ������ x1 ���̸� ��������
			if (height[x1] < height[x2]) {
				area = abs(x2 - x1) * height[x1];
				if (max < area) {
					max = area;
				}
				// �����ʹ�������
				x1++;
			}
			else {
				// x1���̰� x2 ���̺��� ũ���� x2 ���̸� ��������
				area = abs(x2 - x1) * height[x2];
				if (max < area) {
					max = area;
				}
				// ���ʹ�������
				x2--;
			}
		}

		return max;
	}
};