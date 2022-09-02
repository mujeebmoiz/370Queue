#include <iostream>
#include<random>
#include<string>
#include <fstream>
#include "dynamicMemoryQueue.h"
#include "testStream2.h"



void randomStream(std::string fileName, int num) {
    //Ask if the names of the variables matter
    //Random number and letter functions 

    std::random_device ztf;
    std::mt19937 gen1(ztf());
    std::uniform_int_distribution<> distrib1(0, 5);

    std::string zerotFive[] = { "A", "D", "P", "E", "C", "S" };


    //random integers
    std::random_device minmax;
    std::mt19937 gen2(minmax());
    std::uniform_int_distribution<> distrib2(INT_MIN, INT_MAX);

    std::ofstream outputFile;
    outputFile.open(fileName);

    for (int i = 0; i < num; i++) {
        int rand = distrib1(gen1);
        if (rand == 0) {
            int randomInt = distrib2(gen2);
            outputFile << zerotFive[rand] << " " << randomInt << "\n";
            //Random letters and if the rand is 0 / "A" it will print a random set of numbers after it 
        }
        else {
            outputFile << zerotFive[rand] << "\n";
            //if the output file doesnt have "A" then it will just print the random letters
        }

    }

    //File close
    outputFile.close();
    std::cout << "randomStream done" << std::endl;

}
void menu() {
    std::string fileName;
    int num;
    int choice = 0;

    while (choice != 1) {
        std::cout << "Option 1: Exit\n";
        std::cout << "Option 2: Run randomStream\n";
        std::cout << "Option 3: Run testStream\n";
        std::cout << "Option 4: Run randomStream && testStream\n";
        std::cout << "Choose an option (1-4): ";
        std::cin >> choice;

        //if the choice is 1 it exits the program 
        if (choice == 1) {
            exit(0);
        }

        //if the choice is 2 it runs randomStream

        if (choice == 2) {
            // input statments 
            std::cout << "Please input a filename: ";
            std::cin >> fileName;
            std::cout << "How many iterations: ";
            std::cin >> num;
            randomStream(fileName, num);
        }
        //If the choice is 3 it runs testStream
        if (choice == 3) {

            // input statments 
            std::cout << "Please input a filename: ";
            std::cin >> fileName;


            testStream2(fileName);
        }
        //if choice is 4 it runs randomStream and testStream
        if (choice == 4) {
            // input statments 
            std::cout << "Please input a filename: ";
            std::cin >> fileName;

            std::cout << "How many iterations: ";
            std::cin >> num;
            randomStream(fileName, num);
            testStream2(fileName);
        }
    }
}



int main()
{
    menu();
}


