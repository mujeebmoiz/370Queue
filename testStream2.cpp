#include <iostream>
#include<random>
#include<string>
#include <fstream>
#include "dynamicMemoryQueue.h"
#include <queue>
#include "wrapperClass.h"
#include "linkedlistWrapper.h"

int testStream2(std::string fileName) {
    farmingdale::queue<std::string> queue1;
    farmingdale::queue<std::string> queue2;
    STLQueue::queue <std::string> queue3; //STL QUEUE 
    linkedListQueue::linkedList<std::string> queue4; //Linked List Queue

    std::string enq;

    int counter = 0;
    std::string theNumber1, theNumber2, theNumber3, theNumber4;
    std::string theNumber5, theNumber6, theNumber7, theNumber8;
    std::string theNumber9, theNumber10, theNumber11, theNumber12;
    bool theNumber13, theNumber14, theNumber15, theNumber16;

    std::ifstream infile;
    infile.open(fileName);

    //Enqueue 
    while (!infile.eof()) {
        getline(infile, enq);
        counter++;
        int pos = 2;

        std::string theNumber;
        if (enq.find("A") != std::string::npos) {
            theNumber = enq.substr(pos, enq.length());

            //If A is called in the instructional file then enqueue theNumber from the file
            farmingdale::statusCode reenq1 = queue1.enqueue(theNumber);
            farmingdale::statusCode reenq2 = queue2.enqueue(theNumber);
            STLQueue::statusCode reenq3 = queue3.enqueue(theNumber);
            linkedListQueue::statusCode reenq4 = queue4.enqueue(theNumber);


            if ((reenq1 != reenq2) || (reenq1 != reenq3) || (reenq1 != reenq4)) {
                std::cout << "the line number is " << counter << std::endl;
                return counter;
            }

        }





        //Dequeue

        if (enq.find("D") != std::string::npos) {
            //If D is called in the instructional file then dequeue theNumber

            // need to look at the  return values
            // need to compare the values passed back by reference


            farmingdale::statusCode redeq1 = queue1.dequeue(theNumber1);
            farmingdale::statusCode redeq2 = queue2.dequeue(theNumber2);
            STLQueue::statusCode redeq3 = queue3.dequeue(theNumber3);
            linkedListQueue::statusCode redeq4 = queue4.dequeue(theNumber4);

            if ((redeq1 != redeq2) || (redeq1 != redeq3) || (redeq1 != redeq4)) {
                std::cout << "the line number is " << counter << std::endl;
                return counter;
            }
            if (redeq1 == farmingdale::SUCCESS) {
                if ((theNumber1 != theNumber2) || (theNumber2 != theNumber3) || (theNumber3 != theNumber4)) {
                    std::cout << "the line number is " << counter << std::endl;
                    return counter;
                }
            }
        }


        //Peek

        if (enq.find("P") != std::string::npos) {


            //If P is called in the instructional file then peek theNumber 
            farmingdale::statusCode repeek1 = queue1.peek(theNumber5);
            farmingdale::statusCode repeek2 = queue2.peek(theNumber6);
            STLQueue::statusCode repeek3 = queue3.peek(theNumber7);
            linkedListQueue::statusCode repeek4 = queue4.peek(theNumber8);


            if ((repeek1 != repeek2) || (repeek1 != repeek3) || (repeek1 != repeek4)) {
                std::cout << "the line number is " << counter << std::endl;
                return counter;

            }
            if (repeek1==farmingdale::SUCCESS ) {
                if ((theNumber5 != theNumber6) || (theNumber6 != theNumber7) || (theNumber7 != theNumber8)) {
                    std::cout << "the line number is " << counter << std::endl;
                    return counter;
                }
            }
            



        }
        //IsEmpty

        if (enq.find("E") != std::string::npos) {
            //If E is called in the instructional file then Check if the queue is empty 
            theNumber13 = queue1.isEmpty();
            theNumber14 = queue2.isEmpty();
            theNumber15 = queue3.isEmpty();
            theNumber16 = queue4.isEmpty();

            if ((theNumber13 != theNumber14) || (theNumber14 != theNumber15) || (theNumber15 != theNumber16)) {
                std::cout << "the line number is " << counter << std::endl;
                return counter;
            }
        }

    }
    infile.close();

    std::cout << "testStream Done" << std::endl;
    return 0;
}


