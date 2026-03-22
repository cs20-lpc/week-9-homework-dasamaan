#include <iostream>
#include <cstdlib>
#include <ctime>

#include "QueueFactory.hpp"

using namespace std;

int main() {
    srand(time(0));

    cout << "=== Simulation 1: Ticket Counter (Array-Based Queue) ===\n";

    // fixed size → use circular array
    Queue<int>* ticketQueue = QueueFactory<int>::GetQueue(10);

    for (int i = 0; i < 100; i++) {
        int r = rand() % 3 - 1; // -1, 0, 1

        if (r < 0) {
            // serve customer
            if (!ticketQueue->isEmpty()) {
                ticketQueue->dequeue();
                cout << "Customer served\n";
            } else {
                cout << "No customers to serve\n";
            }
        } else {
            // new arrival
            try {
                ticketQueue->enqueue(1);
                cout << "Customer arrived\n";
            } catch (...) {
                cout << "Line full, customer turned away\n";
            }
        }
    }

    cout << "Final length: " << ticketQueue->getLength() << "\n\n";

    delete ticketQueue;

    // ------------------------------------------------------

    cout << "=== Simulation 2: Bank Line (Linked Queue) ===\n";

    // no size → use linked list
    Queue<int>* bankQueue = QueueFactory<int>::GetQueue();

    for (int i = 0; i < 100; i++) {
        int r = rand() % 4 - 1; // -1, 0, 1, 2

        if (r < 0) {
            // customer leaves
            if (!bankQueue->isEmpty()) {
                bankQueue->dequeue();
                cout << "Customer served\n";
            } else {
                cout << "No customers to serve\n";
            }
        } else {
            // customer arrives
            bankQueue->enqueue(1);
            cout << "Customer arrived\n";
        }
    }

    cout << "Final length: " << bankQueue->getLength() << endl;

    delete bankQueue;

    return 0;
}