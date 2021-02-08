/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	// ��ü������ �۷ι� ������ �ּ� üũ��.
	Iterator* a;
	int next_num = 0;
	int peek_num = 0;
	bool peek_check = false;

	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.


		Iterator* i = new Iterator(nums); // nums�� ���ڷ� ���ο� Iterator�ν��Ͻ��� ���� 
		a = i;

	}

	// Returns the next element in the iteration without advancing the iterator.
	// peek()�� ���� �ε����� ����Ű�µ� peek(), peek() �������� ������ �ڿ� peek()�� ���� ����Ű�� �ִ� �ε����� ��ȯ
	int peek() {

		if (!peek_check) {
			peek_num = a->next();
			peek_check = true;
		}
		return peek_num;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
  // next()�� peek()�� ������� ���� �ε����� �����Ѿ���. �׷��� next() peek() next()�� 1, 2, 2�� �� 
	int next() {
		if (!peek_check) {
			next_num = a->next();
			return next_num;
		}

		peek_check = false;
		next_num = peek_num;
		return next_num;
	}

	// nums�� ���� ���ڰ� �ִ��� ������ �Ǵ�. peek()���� ������ �ε����� ���͵� next()�� �Ҹ��� ������ �ε����� ����Ű�⿡   hasNext()�� true�� ���;��� 
	bool hasNext() const {
		return peek_check || a->hasNext();
	}
};