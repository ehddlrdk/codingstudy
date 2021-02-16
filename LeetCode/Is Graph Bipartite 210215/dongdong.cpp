class Solution {
public:

	bool isBipartite(vector<vector<int>>& graph) {
		// ��� ��忡 ���� �� �η��� �׷����� ������
		// ���������� ��ġ�°��� ������ true, ������ false
		// bfs�� ��� ������ �׷� ����, �������� ����� ���� ���� �׷����� ����
		// �湮üũ 
		bool check[101] = { false };
		bool group[101] = { false };
		bool cur_group = false;
		queue<int> q;

		for (int j = 0; j < graph.size(); j++) {
			// ����ȵ� ��嵵 ������ֱ� ����
			if (!check[j]) {
				q.push(j);
				check[j] = true;
				group[j] = cur_group;
			}

			while (!q.empty()) {
				int node = q.front();
				cur_group = !group[node];
				q.pop();
				for (int i = 0; i < graph[node].size(); i++) {
					//�湮���� ����
					if (check[graph[node][i]] == false) {
						q.push(graph[node][i]);
						check[graph[node][i]] = true;
						group[graph[node][i]] = cur_group;
					}
					//�湮�ߴ� ����
					else {
						// ������尡 ���� �׷쿡 �����ִ��� �Ǵ�
						if (group[graph[node][i]] == group[node]) {
							return false;
						}
					}

				}

			}
		}
		return true;
	}
};