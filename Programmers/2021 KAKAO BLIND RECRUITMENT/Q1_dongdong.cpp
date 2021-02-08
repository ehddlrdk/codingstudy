#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";

	int id_leng = new_id.size();
	int flag_dot = 0;

	//1�ܰ� �빮�� -> �ҹ��ڷ� ġȯ
	//2�ܰ� -, _, . ������ ���� ����
	//3�ܰ� ��ħǥ 2�� �̻� ���ӵ� �κ� ��ħǥ �ϳ��� ġȯ
	for (int i = 0; i < id_leng; i++) {
		if (isdigit(new_id[i]) || isalpha(new_id[i]) || new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_') {
			if (new_id[i] == '.') {
				if (flag_dot == 0) {
					answer += new_id[i];
					flag_dot = 1;
				}
			}
			else {
				answer += tolower(new_id[i]);
				flag_dot = 0;
			}
		}
	}
	//4�ܰ� ��ħǥ ó��, �� ����
	if (answer[0] == '.') {
		answer = answer.erase(0, 1);
	}
	if (answer[answer.size() - 1] == '.') {
		answer = answer.erase(answer.size() - 1, 1);
	}

	//5�ܰ� �� ���ڿ��̶�� new_id�� a�� ����?
	if (answer.size() == 0) {
		answer += "a";
	}
	//6�ܰ� 16�� �̻� , 15���� ���� ������ ������ ����. ���� �� ��ħǥ�� ���� �����ϸ� ��ħǥ ����
	if (answer.size() >= 16) {
		answer = answer.substr(0, 15);
	}
	if (answer[answer.size() - 1] == '.') {
		answer = answer.erase(answer.size() - 1, 1);
	}
	//7�ܰ� 2�� ����, ������ ���ڸ� ���� 3�� ��  ���� �ݺ�.
	if (answer.size() <= 2) {
		while (answer.size() != 3) {
			answer += answer[answer.size() - 1];
		}
	}

	return answer;
}