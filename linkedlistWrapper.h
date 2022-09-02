#pragma once
#include <iostream>
#include <random>
#include <string>
#include <fstream>

namespace linkedListQueue {
	
	template <class CL> struct llNode;
	template <class CL> class linkedList;
	enum statusCode { SUCCESS, FAILURE };
}



template <class MM> struct linkedListQueue::llNode {
	MM data;
	llNode<MM>* next = 0;
};



template <class MM> class linkedListQueue::linkedList {

	llNode<MM>* head;
	llNode<MM>* tail;

public:

	inline bool isEmpty() const
	{
		return tail == 0 || head == 0; 
	}
	linkedList();
	statusCode enqueue(MM addMe);
	statusCode dequeue(MM& returnedElement);
	statusCode peek(MM& returnedElement) const;


};

template <class MM> linkedListQueue::linkedList<MM>::linkedList()
	:
	head(0),
	tail(0)
{
}
template<class MM> linkedListQueue::statusCode linkedListQueue::linkedList<MM>::enqueue(MM addMe) {
	 
	 llNode<MM>* temp;
	 try {
		 temp = new llNode<MM>;
	 }
	 catch (std::bad_alloc) {
		 return FAILURE;
	 }
	 temp->data = addMe; 
	
	 temp->next = 0; 
	 if (0 != tail) {
		 tail->next = temp;
	 }
	 else { 
		 head = temp;
	 }
	
	 tail = temp;

	return SUCCESS;
	
	
}
template<class MM> linkedListQueue::statusCode linkedListQueue::linkedList<MM>::peek(MM& returnedElement) const {
	if (isEmpty()) {
		return FAILURE;
	}
	
	returnedElement = head->data;
	
	return SUCCESS;
	
}

template<class MM> linkedListQueue::statusCode linkedListQueue::linkedList<MM>::dequeue(MM& returnedElement) {
	if (isEmpty()) {
		return FAILURE;
	}
	returnedElement = head->data; 
	llNode<MM>* oldHead = head;
	
	head = head->next;
	
	if (0 == head) {
		tail = 0;
	
	}
	delete oldHead;

	return SUCCESS;
}
