#pragma once
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <queue>

namespace STLQueue {
    template <class MM> class queue;
    enum statusCode { SUCCESS, FAILURE };
}
template<class MM> class STLQueue::queue {
    std::queue <std::string> queue3;

public:

    inline bool isEmpty() const
    {
        return queue3.empty();
    }
    statusCode enqueue(MM addMe);
    statusCode dequeue(MM& returnedElement);
    statusCode peek(MM& returnedElement) const;

};


template<class MM> STLQueue::statusCode STLQueue::queue<MM>::enqueue(MM addMe)
{
    
    queue3.push(addMe);
    return SUCCESS;
}

template<class MM> STLQueue::statusCode STLQueue::queue<MM>::dequeue(MM& returnedElement) {
    if (queue3.empty()) {
        return FAILURE;
    }
    returnedElement = queue3.front();    
    queue3.pop();

    return SUCCESS;

}

template<class MM> STLQueue::statusCode STLQueue::queue<MM>::peek(MM& returnedElement) const {
    if (queue3.empty()) {
        return FAILURE;
    }

    returnedElement = queue3.front();

    return SUCCESS;

}