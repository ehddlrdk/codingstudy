/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/

class Solution {
public:
	Node* copyRandomList(Node* head) {
		//���� ������ ���� ������ ��带 pair�� ����
		map<Node*, Node*> m;
		Node* first = head;

		while (first != NULL) {
			Node* new_node = new Node(first->val);
			m[first] = new_node;
			first = first->next;
		}

		first = head;
		//map���� ���� �� ��带 ���� ����� �Ȱ��� ����
		while (first != NULL) {
			m[first]->next = m[first->next];
			m[first]->random = m[first->random];
			first = first->next;
		}
		//ù ��带 ����
		return m[head];
	}
};