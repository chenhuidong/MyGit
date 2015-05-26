#include <boost/thread.hpp>
#include <iostream>

void task1() { 
    // do stuff
    std::cout << "This is task1!" << std::endl;
}

void task2() { 
    // do stuff
    std::cout << "This is task2!" << std::endl;
}

int main (int argc, char ** argv) {
    boost::thread thread_1 = boost::thread(task1);
    boost::thread thread_2 = boost::thread(task2);

    // do other stuff
    thread_2.join();
    thread_1.join();
    return 0;
}

//g++ MulThreadWithBoost.cpp -omain -lboost_system -lboost_thread
//g++ MulThreadWithBoost.cpp -omain -lboost_system -lboost_filesystem -lboost_thread