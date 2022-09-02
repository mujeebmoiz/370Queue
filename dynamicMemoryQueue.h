#pragma once
namespace farmingdale {

	template <class MM> class queue;
	enum statusCode { SUCCESS, FAILURE };
}
template<class MM> class farmingdale::queue {
private:
	static const int INITIAL_QUEUE_SIZE = 16;
	MM* data;

	int oldestIndex;
	int nextInsertIndex;
	int currentCapacity;


	inline int nextIndexOf(int index) const { return((index + 1) % (currentQueueCapacity() + 1)); }
public:
	queue();
	//queue(const queue& copyMe);



	inline int initialQueueCapacity() const { return INITIAL_QUEUE_SIZE - 1; }
	inline int currentQueueCapacity() const { return currentCapacity - 1; }
	inline bool isEmpty() const { return (oldestIndex == nextInsertIndex); }
	inline bool isFull() { return (nextIndexOf(nextInsertIndex) == oldestIndex); }
	statusCode enqueue(MM addMe);
	statusCode dequeue(MM& returnedElement);
	statusCode peek(MM& returnedElement) const;
	//bool operator==(const queue<MM>&) const;

};



//Df constr
template<class MM> farmingdale::queue<MM>::queue()
//set oldest and nextInsert to 0
//Initialization list
	:
	oldestIndex(0),
	nextInsertIndex(0),
	currentCapacity(INITIAL_QUEUE_SIZE)

{
	data = new MM[currentCapacity];
}



template<class MM> farmingdale::statusCode farmingdale::queue<MM>::enqueue(MM addMe) {
	//Step 1: Check if queue is full if so Grow the queue as follows 
	if (isFull()) {
		//Step 1a: Alloacte new Memory, size 2x capacity
		int newCapacity = currentCapacity * 2;

		MM* theNewDataMemory;
		try {
			theNewDataMemory = new MM[newCapacity];
		}
		catch (std::bad_alloc) {
			return farmingdale::FAILURE;
		}
		//Step 1b: Copy the data, 
		int firstIndex = 0;
		int ArrayIndex = 0;
		for (int i = oldestIndex; i != nextInsertIndex; i = nextIndexOf(i)) {
			theNewDataMemory[firstIndex] = data[i];
			firstIndex++;
		}
		//Step 1c: fix the indexs. 
		nextInsertIndex = firstIndex;
		oldestIndex = ArrayIndex;
		//Step 1d: Call Delete on the old memory
		delete[]data;
		//Step 1e: Set data to new memory
		data = theNewDataMemory;
		//Step 1f: Set the new capacity
		currentCapacity = newCapacity;
	}
	//Step 2: if not, we'll add the item in slot [nextInsert]
	data[nextInsertIndex] = addMe;
	//Step 3: Advance nextInsert to the next slot
	nextInsertIndex = nextIndexOf(nextInsertIndex);
	//Step 4: Return Sucess
	return farmingdale::SUCCESS;

}
template<class MM> farmingdale::statusCode farmingdale::queue<MM>::peek(MM& returnedElement) const {

	//Step 1: check if empty if so return failure
	if (isEmpty())
	{
		return farmingdale::FAILURE;
	}
	//Step 2: put item [oldestIndex] into returnedElement
	returnedElement = data[oldestIndex];
	//Step 3: Return Success
	return farmingdale::SUCCESS;
}

template<class MM> farmingdale::statusCode farmingdale::queue<MM>::dequeue(MM& returnedElement) {
	//Step 1: check if empty if so return failure
	if (isEmpty())
	{
		return farmingdale::FAILURE;
	}
	//Step 2: put item [oldestIndex] into returnedElement
	returnedElement = data[oldestIndex];

	//Step 3: Move index up
	oldestIndex = nextIndexOf(oldestIndex);
	//Step 4: Return Success
	return farmingdale::SUCCESS;
}

