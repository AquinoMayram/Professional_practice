#include <iostream>
#include "queue_itf.hpp"

void testqueue( void )
{
    Queue<int>* queue = new Queue<int>;

    std::cout << "Queue capacity: " << queue->capacity() << std::endl;
    std::cout << "  queue size: " << queue->size() << std::endl;
    std::cout << "Queue is empty: " << ( queue->isEmpty() ? "queue is empty" : "queue is not empty") << std::endl;
    std::cout << "Queue is full: " << ( queue->isFull() ? "queue is full" : "queue is not full") << std::endl;
    std::cout << std::endl;

    std::cout << "->> Push-ing queue ..." << std::endl;
    std::cout << " Push-ing item: " << "99 " << ( queue->enqueue( 99 ) ? "item not queueed " : "item not queueed" ) << std::endl;
    std::cout << " Push-ing item: " << "97 " << ( queue->enqueue( 97 ) ? "item not queueed " : "item not queueed" ) << std::endl;
    std::cout << " Push-ing item: " << "93 " << ( queue->enqueue( 93 ) ? "item not queueed " : "item not queueed" ) << std::endl;
    std::cout << "  queue size: " << queue->size() << std::endl;
    std::cout << " queue is empty: " << ( queue->isEmpty() ? "queue is empty" : "queue is not empty" ) << std::endl;
    std::cout << " queue is full: " << ( queue->isFull() ? "queue is full" : "queue is not full" ) << std::endl;
    std::cout << std::endl;

    std::cout << "->> Pop-ing queue ..." << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << "  queue size: " << queue->size() << std::endl;
    std::cout << " queue is empty: " << ( queue->isEmpty() ? "queue is empty" : "queue is not empty" ) << std::endl;
    std::cout << std::endl;

    std::cout << "->> Pop-ing queue ..." << std::endl;
    std::cout << queue->dequeue() << std::endl;
    std::cout << "  queue size: " << queue->size() << std::endl;
    std::cout << "queue is empty: " << ( queue->isEmpty() ? "queue is empty" : "queue is not empty" ) << std::endl;
    std::cout << std::endl;

    delete queue;
    //queue->~queue();

    //std::cout << "queue peek: " << queue->peek() << std::endl;

}

int main (int argc, const char* argv[])
{
    testqueue();
    return 0;
}
