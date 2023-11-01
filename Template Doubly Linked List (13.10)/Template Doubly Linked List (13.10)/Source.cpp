#include "DoublyLinkedList.h"

int main() {

	DoublyLinkedList<int> list;

	cin >> list;
	cout << list << endl;

	DoublyLinkedList<int> list2(move(list));
	
	cout << list << endl;
	cout << list2 << endl;
	list = move(list2);
	cout << list << endl;
	cout << list2 << endl;
	return 0;
}
