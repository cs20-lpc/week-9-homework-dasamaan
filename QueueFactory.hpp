#ifndef QUEUE_FACTORY_HPP
#define QUEUE_FACTORY_HPP

#include "Queue.hpp"
#include "LinkedQueue.hpp"
#include "CircleArrayQueue.hpp"

template <typename T>
class QueueFactory {
public:
    static Queue<T>* GetQueue(int size = -1) {
        if (size <= 0) {
            // dynamic size → linked list
            return new LinkedQueue<T>();
        } else {
            // fixed size → circular array
            return new ArrayQueue<T>(size);
        }
    }
};

#endif