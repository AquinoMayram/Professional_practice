
#include <stdio.h>
#define interface struct

template< class Type>
interface IQueue
{
    virtual bool enqueue( const Type& item ) = 0;
    virtual Type dequeue( void ) = 0;
    virtual Type peek( void ) = 0;

    virtual bool isEmpty( void ) = 0;
    virtual bool isFull( void ) = 0;
    virtual unsigned long size( void ) = 0;
    virtual unsigned long capacity( void ) = 0;

};

template< class Type >
class Queue :public IQueue<Type>
{
    enum {DEFAULT_QUEUE_CAPACITY = 30};
public:
    Queue( unsigned long itsCapacity = DEFAULT_QUEUE_CAPACITY )
    : rep( nullptr ), queueCapacity( itsCapacity ), in (0), out(0), count( 0 )
    {
        rep = new Type[queueCapacity];
    }

    virtual ~Queue( void )
    {
        if( rep )
            delete [] rep;
    }

    bool enqueue( const Type& item)
    {
        rep[ in ] = item;
        if( in == queueCapacity)
        {
            in=0;
        } else{
        in++;}
        count++;
        return true;
    }

    Type dequeue( void )
    {
        Type retvalue=rep[out];
        if (out == queueCapacity)
        {
            out=0;
        } else{
            out++;}
        count--;
        return retvalue;
    }

    Type peek( void )
    {
        return rep[ out ];
    }

    bool isEmpty( void )
    {
        return ( count == 0);
    }

    bool isFull( void )
    {
        return ( count == queueCapacity );
    }

    unsigned long size( void )
    {
        return count;
    }

    unsigned long capacity( void )
    {
        return queueCapacity;
    }

private:
    Type* rep;
    unsigned long in;
    unsigned long out;
    unsigned long queueCapacity;
    unsigned long count;

    Queue( const Queue<Type>& otherStack );
    Queue<Type>& operator =( const Queue<Type>& rhs);
};
