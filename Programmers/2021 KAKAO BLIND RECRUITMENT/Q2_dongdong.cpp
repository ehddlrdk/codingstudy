#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//course num�� ���� ������ map �ʿ�. map<string, int> m ; course�޴�, ����
// course_num�� ���� max���� ���� �迭 �ʿ� max_num[11];
map<string, int> m[11];
int max_num[11];
string order; // order
vector<char> menu; // course�޴�
int course_num;

void combination(int depth, int next) {
	//Ż������
	if (depth == course_num) {
		// map�� ����
		string course_menu = "";
		for (char c : menu) {
			course_menu += c;
		}
		m[course_num][course_menu]++;
		if (max_num[course_num] < m[course_num][course_menu]) {
			max_num[course_num] = m[course_num][course_menu];
		}
	}
	else {
		//depth�� �������� next�� ���� Ȯ���س���.
		for (int i = next; i < order.size(); i++) {
			menu[depth] = order[i];
			combination(depth + 1, i + 1);
		}
	}
}


vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	//orders�� ���� course_num�� ���� ���� ���ϱ� ���� combination�� �ֱ�
	for (int num : course) {
		course_num = num;
		for (string str : orders) {
			order = str;
			sort(order.begin(), order.end());
			menu.resize(course_num);
			combination(0, 0);
		}
	}

	//map�� ����Ǿ� �ִ°͵� �� ���� ���� �ֹ��� �͵� �̾Ƴ�
	for (int num : course) {
		for (auto course_menu : m[num]) {
			if (course_menu.second >= 2 && course_menu.second == max_num[num]) {
				answer.push_back(course_menu.first);
			}
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}