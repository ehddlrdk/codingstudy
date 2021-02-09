/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

	TreeNode* convertBST(TreeNode* root) {
		//������ �� Ž�� �� ���� �־ Ž��. dfs���� 
		int sum = 0;
		map<int, int> check_node; //�湮�ߴ��� üũ
		stack<TreeNode*> s;

		if (root != nullptr) {
			s.push(root);
		}

		while (!s.empty()) {
			TreeNode* cur = s.top();
			// �����ʺ��� Ž��
			if (cur->right != nullptr && check_node[cur->val] != 1) {
				s.push(cur->right);
				check_node[cur->val] = 1;
			}
			else {
				sum += cur->val;
				cur->val = sum;
				cout << cur->val << endl;
				s.pop();
				// pop���� �� ���� Ž���ؾ��� ���� ������ push
				if (cur->left != nullptr) {
					s.push(cur->left);
				}
			}
		}
		// ������ TreeNode* root�� ��ȯ.
		return root;
	}
};