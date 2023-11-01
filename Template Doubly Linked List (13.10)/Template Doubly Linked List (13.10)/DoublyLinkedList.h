#pragma once
#include <iostream>
using namespace std;

template <class T>
class DoublyLinkedList
{
	struct Node
	{
		T data{};
		Node* next{};
		Node* prev{};
		Node() = default;
		Node(const T& _data, Node* _prev, Node* _next) : data{ _data }, prev(_prev), next(_next) {};
	};
	Node* head{};
	Node* tail{};

public:
	//ctors

	DoublyLinkedList() = default;
	//copy ctor
	DoublyLinkedList(const DoublyLinkedList<T>& other) {
		head = nullptr;
		tail = nullptr;
		Node* current = other.head;
		while (current != nullptr)
		{
			AddToTail(current->data);
			current = current->next;
		}
	};
	//move ctor
	DoublyLinkedList(DoublyLinkedList<T>&& other) noexcept {
		head = other.head;
		tail = other.tail;
		other.head = other.tail = nullptr;
	};

	//dtor
	~DoublyLinkedList()
	{
		DeleteAll();
	};

	//methods

	T front() const 
	{
		if (head == nullptr)
			throw exception("List is empty");
		return head->data;
	}
	T back() const
	{
		if (tail == nullptr)
			throw exception("List is empty");
		return tail->data;
	}

	void AddToHead(const T& _data)
	{
		if (head == nullptr)
		{
			head = new Node(_data, nullptr, nullptr);
			tail = head;
			return;
		}
		Node* newHead = new Node(_data, nullptr, head);
		head->prev = newHead;
		head = newHead;
	};
	void AddToTail(const T& _data)
	{
		if (tail == nullptr)
		{
			tail = new Node(_data, nullptr, nullptr);
			head = tail;
			return;
		}
		Node* newTail = new Node(_data, tail, nullptr);
		tail->next = newTail;
		tail = newTail;
	};
	void DeleteFromHead()
	{
		if (head == nullptr)
			return;
		
		Node* temp = head;
		head = head->next;
		if (head)
			head->prev = nullptr;
		delete temp;
	};
	void DeleteFromTail()
	{ 
		if (tail == nullptr)
			return;
		Node* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
	};
	void DeleteAll()
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
		head = nullptr;

	};
	void AddToPosition(const int position, const T& _data)
	{

		if (position == 0)
			AddToHead(_data);
		else if (position == Count())
			AddToTail(_data);
		else if (position > Count())
			return;
		else
		{
			Node* current = head;
			for (int i = 0; i < position; i++)
			{
				current = current->next;
			}
			Node* newHead = new Node(_data, current->prev, current);
			current->prev->next = newHead;
			current->prev = newHead;
		}
	};
	void DeleteFromPosition(int position)
	{
		if (position == 0)
			DeleteFromHead();
		else if (position == Count())
			DeleteFromTail();
		else if (position > Count())
			return;
		else
		{
			Node* current = head;
			for (int i = 0; i < position; i++)
			{
				current = current->next;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
		}
	};
	int SearchElement(T _data)
	{
		if (head == nullptr)
			return NULL;
		Node* current = head;
		for (int i = 0; i < Count(); i++)
		{
			if (current->data == _data)
				return i;
			current = current->next;
		}
		return NULL;
	};
	int SwapElements(T _data1, T _data2)
	{
		if (head == nullptr)
			return -1;
		Node* current = head;
		int i{};
		while (current != nullptr)
		{
			if (current->data == _data1)
			{
				current->data = _data2;
			}
			current = current->next;
			i++;
		}
		if (i == 0)
			return -1;
		return i;
	};
	void Reverse() 
	{
		if (head == nullptr)
			return;
		Node* current = head;
		Node* prev = nullptr;
		Node* next = nullptr;
		while (current != nullptr)
		{
			next = current->next;
			current->next = prev;
			current->prev = next;
			prev = current;
			current = next;
		}
		head = prev;
	};
	ostream& Show(ostream& out = cout, const string& delimiter = " ") const
	{
		if (head == nullptr)
		{
			out << "List is empty.";
			return out;
		};
		for (int i = 0; i < Count(); i++)
		{
			out << (*this)[i] << " ";
		}
		return out;
	};

	size_t Count() const
	{
		size_t count = 0;
		Node* current = head;
		while (current != nullptr)
		{
			count++;
			current = current->next;
		}
		return count;
	};

	const T& operator[](int index) const
	{
		Node* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->data;
	};
	 T& operator[](int index) 
	{
		Node* current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->data;
	};
	
	 DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other)
	 {
		 if (this == &other)
			 return *this;
		 DeleteAll();
		 Node* current = other.head;
		 while (current != nullptr)
		 {
			 AddToTail(current->data);
			 current = current->next;
		 }
		 return *this;
	 }

	 DoublyLinkedList<T>& operator=(DoublyLinkedList<T>&& other) noexcept
	 {
		 DeleteAll();
		 head = other.head;
		 tail = other.tail;
		 other.head = other.tail = nullptr;
		 return *this;
	 }
	 DoublyLinkedList<T>& operator=(const T& other)
	 {
		 DeleteAll();
		 AddToTail(other);
		 return *this;
	 }
	 DoublyLinkedList<T>& operator=(const T&& other)
	 {
		 head = other.head;
		 tail = other.tail;
		 other.head = other.tail = nullptr;
		 return *this;
	 }

};

template <class T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& list)
{
	return list.Show(out);
};

template <class T>
istream& operator>>(istream& in, DoublyLinkedList<T>& list)
{
	int length{};
	cout << "\nenter length: ";
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		int value{};
		cout << '[' << i << "] =  ";
		cin >> value;
		list.AddToTail(value);
	}
	return in;

};


