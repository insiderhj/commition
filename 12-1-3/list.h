#include <iostream>

using namespace std;

template <class T>
class Node
{
	public:
		T data;
		Node<T>* next;
};

template <class T>
class List {
private:
	Node<T> *head;
public:
	List() : head(NULL) {};
	~List();//free resources
	List(T* arr, int n_nodes);//create a list with n_nodes
	void insert_at(int idx, const T& data);
	void remove_at(int idx);
	void pop_back();
	void push_back(const T& val);
	void pop_front();
	void push_front(const T& val);
	friend ostream& operator<<(ostream& out, List& rhs)//print out nodes
	{
		if (!rhs.head)
			return out;
		Node<T> *cur = rhs.head;
		while (cur->next) {
			out << cur->data << ',';
			cur = cur->next;
		}
		out << cur->data;
		return out;
	}
};

template <class T>
List<T>::~List()
{
	Node<T> *cur = head;
	Node<T> *next;
	while (cur)
	{
		next = cur->next;
		delete cur;
		cur = next;
	}
}

template <class T>
List<T>::List(T *arr, int n_nodes)
{
	if (n_nodes < 1)
		return;
	head = new Node<T>;
	Node<T> *cur = head;
	head->data = arr[0];
	head->next = NULL;
	for (int i = 1; i < n_nodes; i++) {
		cur->next = new Node<T>;
		cur = cur->next;
		cur->data = arr[i];
		cur->next = NULL;
	}
}

template <class T>
void List<T>::insert_at(int idx, const T &data)
{
	if (idx == 0) {
		push_front(data);
		return;
	}
	Node<T> *new_node = new Node<T>;
	new_node->data = data;

	Node<T> *cur = head;
	for (int i = 1; i < idx; i++)
		cur = cur->next;
	new_node->next = cur->next;
	cur->next = new_node;
}

template <class T>
void List<T>::remove_at(int idx)
{
	if (idx < 0)
		return;
	Node<T> *prev = NULL;
	Node<T> *cur = head;
	for (int i = 1; i < idx; i++) {
		prev = cur;
		cur = cur->next;
	}
	if (!prev)
		head = cur->next;
	else
		prev->next = cur->next;
	free(cur);
}

template <class T>
void List<T>::pop_back()
{
	Node<T> *prev = NULL;
	Node<T> *cur = head;
	if (!cur)
		return;
	while (cur->next) {
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	free(cur);
}

template <class T>
void List<T>::push_back(const T& val)
{
	Node<T> *new_node = new Node<T>;
	new_node->data = val;
	new_node->next = NULL;

	Node<T> *cur = head;
	if (!cur)
		head = new_node;
	else {
		while (cur->next)
			cur = cur->next;
		cur->next = new_node;
	}
}

template <class T>
void List<T>::pop_front()
{
	if (!head)
		return;
	Node<T> *next = head->next;
	delete head;
	head = next;
}

template <class T>
void List<T>::push_front(const T& val)
{
	Node<T> *new_node = new Node<T>;
	new_node->data = val;
	new_node->next = head;

	head = new_node;
}
