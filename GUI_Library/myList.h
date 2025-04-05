#pragma once

#include <iostream>
#include <cstdlib>

template <typename T>
class MyList {
public:
	class iterator;
	class reverse_iterator;

	class Node {
	private:
		T data_;
		Node* next_;
		Node* pre_;
		friend class iterator;
		friend class reverse_iterator;
	public:
		Node() {}
		Node(T data, Node* pre, Node* next)
			: data_(data), pre_(pre), next_(next) {}
		void setPre(Node* pre) { pre_ = pre; }
		void setNext(Node* next) { next_ = next; }
		Node* getPre() const { return pre_; }
		Node* getNext() const { return next_; }
		T getData() { return data_; }
	};
private:
	Node* head_;
	Node* tail_;
public:
	MyList();
	~MyList();
	void push_front(T data);
	void push_back(T data);
	bool empty();
	T back();
	bool remove(T data); //���� data�� ��带 ��� ���� �ϳ��� ����� true ��ȯ
	T remove(iterator& i); // i ������ ��ĭ �̵�, ����Ű�� �ִ� ��带 �����ϰ� �׵����͸� ��ȯ
	T remove(reverse_iterator& ri);//ri �ڷ� ��ĭ �̵�

	class iterator {
	private:
		Node* ptr_;
	public:
		iterator() { ptr_ = nullptr; }
		iterator(Node* pp) { ptr_ = pp; }
		Node* getPtr() const { return ptr_; }
		void operator ++ () {
			ptr_ = ptr_->next_;
		}
		bool operator != (iterator x) const {
			return (ptr_ != x.ptr_);
		}
		T& operator * () const {
			return ptr_->data_;
		}
	};

	class reverse_iterator {
	private:
		Node* ptr_;
	public:
		reverse_iterator() { ptr_ = nullptr; }
		reverse_iterator(Node* pp) { ptr_ = pp; }
		Node* getPtr() const { return ptr_; }
		void operator ++ () {
			ptr_ = ptr_->pre_;
		}
		bool operator != (reverse_iterator x) {
			return (ptr_ != x.ptr_);
		}
		T& operator * () {
			return ptr_->data_;
		}
	};
public:
	iterator begin() {
		return iterator(head_->getNext());
	}
	iterator end() {
		return iterator(tail_);
	}

	reverse_iterator rbegin() {
		return reverse_iterator(tail_->getPre());
	}
	reverse_iterator rend() {
		return reverse_iterator(head_);
	}

};

template <typename T>
MyList<T>::MyList() {
	//head Dummy ����
	head_ = new Node();
	head_->setPre(nullptr);

	//tail Dummy����
	tail_ = new Node();
	tail_->setNext(nullptr);

	//���� ����
	head_->setNext(tail_);
	tail_->setPre(head_);
}

template <typename T>
MyList<T>::~MyList() {
	for (Node* temp = head_; temp != tail_; ) {
		Node* rNode = temp;
		temp = temp->getNext();
		delete rNode;
	}
	delete tail_;
}

template <typename T>
void MyList<T>::push_front(T data) {
	Node* temp = new Node(data, head_, head_->getNext());
	head_->getNext()->setPre(temp);
	head_->setNext(temp);
}

template <typename T>
void MyList<T>::push_back(T data) {
	Node* temp = new Node(data, tail_->getPre(), tail_);
	tail_->getPre()->setNext(temp);
	tail_->setPre(temp);
}

template <typename T>
bool MyList<T>::empty() {
	return (head_->getNext() == tail_);
}

template <typename T>
T MyList<T>::back() {
	if (empty()) {
		std::cout << "list is empty" << std::endl;
		exit(-1);
	}
	return tail_->getPre()->getData();
}

template <typename T>
bool MyList<T>::remove(T data) {
	bool rFlag = false;

	for (Node* temp = head_->getNext(); (temp != head_ && temp != tail_); temp = temp->getNext()) {
		if (temp->getData() == data) {
			temp->getPre()->setNext(temp->getNext());
			temp->getNext()->setPre(temp->getPre());
			Node* rNode = temp;//������ ���� ����
			temp = temp->getPre();
			delete rNode;
			rFlag = true;
		}
	}
	return rFlag;
}

template <typename T>
T MyList<T>::remove(iterator& i) {
	Node* rNode = i.getPtr();
	T rData = rNode->getData();

	rNode->getPre()->setNext(rNode->getNext());
	rNode->getNext()->setPre(rNode->getPre());

	i = iterator(rNode->getPre()); //������ ��ĭ ����

	delete rNode;

	return rData;
}

template <typename T>
T MyList<T>::remove(reverse_iterator& ri) {
	Node* rNode = ri.getPtr();
	T rData = rNode->getData();

	rNode->getPre()->setNext(rNode->getNext());
	rNode->getNext()->setPre(rNode->getPre());

	ri = reverse_iterator(rNode->getNext()); //�ڷ� ��ĭ ����

	delete rNode;

	return rData;
}


