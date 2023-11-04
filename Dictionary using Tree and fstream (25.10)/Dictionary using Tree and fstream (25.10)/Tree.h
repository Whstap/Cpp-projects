#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class TKey, class TData>
class Tree {
	struct Node {
		TKey key{};
		TData data{};
		Node* left{}, * right{};
		Node() = default;
		Node(const TKey& key, const TData& data, Node* left = nullptr, Node* right = nullptr) :
			key{ key }, data{ data }, left{ left }, right{ right } {}
	};
	Node* root{};
	size_t length{};

	void add(Node*& snode, const TKey& key, const TData& data)
	{
		if (snode == nullptr)
		{
			snode = new Node(key, data);
			++length;
			return;
		}
		if (key < snode->key)
		{
			if (snode->left == nullptr)
			{
				snode->left = new Node(key, data);
				++length;
				return;
			}
			else
				add(snode->left, key, data);
		}
		if (key > snode->key)
		{
			if (snode->right == nullptr)
			{
				snode->right = new Node(key, data);
				++length;
				return;
			}
			else
				add(snode->right, key, data);
		}
	}

	void show(const Node* snode, ostream& out = cout, const string& key_data_delimiter = " : ", const string& pair_delimiter = "\n") const
	{
		if (snode == nullptr)
			return;
		show(snode->left, out, key_data_delimiter, pair_delimiter);
		out << snode->key << key_data_delimiter << snode->data << pair_delimiter;
		show(snode->right, out, key_data_delimiter, pair_delimiter);
	}

	const TData& find(const Node* snode, const TKey& key) const
	{
		return find(snode, key);
	}

	TData& find(Node* snode, const TKey& key)
	{
		if (snode == nullptr)
			throw exception("key is not found");
		if (snode->key == key)
			return snode->data;
		if (key < snode->key)
			return find(snode->left, key);
		if (key > snode->key)
			return find(snode->right, key);
	}

	void deep_copy(const Node* node)
	{
		if (node == nullptr)
			return;
		this->add(node->key, node->data);
		deep_copy(node->left);
		deep_copy(node->right);
	}

	void delete_subtree(Node*& node)
	{
		if (node == nullptr)
			return;

		delete_subtree(node->left);
		delete_subtree(node->right);
		delete node;
		node = nullptr;
		--length;
	}

public:
	Tree() = default;
	Tree(const Tree<TKey, TData>& other_tree)
	{
		deep_copy(other_tree.root);
	}
	Tree(Tree<TKey, TData>&& other_tree) noexcept :root{ other_tree.root }, length{ other_tree.length }
	{
		other_tree.length = 0;
		other_tree.root = nullptr;
	}
	Tree<TKey, TData>& operator=(const Tree<TKey, TData>& other_tree)
	{
		if (this == &other_tree)
			return*this;
		deep_copy(other_tree.root);
		return *this;
	}
	Tree<TKey, TData>& operator=(Tree<TKey, TData>&& other_tree) noexcept
	{
		this->root = other_tree.root;
		this->length = other_tree.length;
		other_tree.root = nullptr;
		other_tree.length = 0;
		return *this;
	}
	~Tree()
	{
		delete_subtree(root);
	}

	void add(const TKey& key, const TData& data)
	{
		add(root, key, data);
	}

	ostream& show(ostream& out = cout, const string& key_data_delimiter = " : ", const string& pair_delimiter = "\n") const
	{ 
		show(root, out, key_data_delimiter, pair_delimiter);
		return out;
	}

	TData& find(const TKey& key)
	{
		return find(root, key);
	}

	const TData& find(const TKey& key) const
	{
		return find(root, key);
	}

	size_t size() const
	{
		return length;
	}
};

template<class TKey, class TData>
void find_and_output(Tree<TKey, TData>& tree, const TKey& key)
{
	try {
		cout << tree.find(key) << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
};


template<class TKey, class TData>
void TreeInfo(const Tree<TKey, TData>& tree)
{
	cout << "Size: " << tree.size() << endl;
	cout << "Tree data \\/" << endl;
	tree.show();
}