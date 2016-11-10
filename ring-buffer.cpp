#include <iostream>
template <class t>
class CircularBuffer
{
public:

    CircularBuffer( int size )
    {
        head = tail = length = 0;
        bufferSize = size;
        arr = new t[bufferSize];
    }

    ~CircularBuffer()
    {
        delete[] arr;
    }

    // Добавить элемент
    void put( const t & value )
    {
        if ( tail == bufferSize )
        {
            tail = 0;
        }

        arr[tail] = value;
        ++tail;
        ++length;
    }


    // Извлечь последний элемент
    t & pop()
    {

        t & elem = arr[head];
        ++head;
        --length;
        if ( head == bufferSize ) {
            head = 0;
        }
        return elem;
    }

    // Кол-во элементов в буфере
    size_t size() const
    {
        return length;
    }

    // Ёмкость буфера
    size_t capacity() const
    {
        return bufferSize;
    }

    t operator [](const int &i)
    {
        return arr[i];
    }

    void printBuffer()
    {
        std::cout << head << " " << tail << " " ;
        for (int i = 0; i < length; i++)
        {
            std::cout << arr[i] << ";";
        }
        std::cout << std::endl;

    }


private:
    t * arr;             // массив-буфер
    int bufferSize;        // размер буфера
    int length;            // кол-во элементов в буффере
    int head;              // индекс первого элемента
    int tail;              // индекс последнего элемента
};


int main()
{
    CircularBuffer<int> buf(3);
    buf.printBuffer();

    for( int i = 0; i < 10; ++i )
    {
        buf.put( i * 2 );
        buf.printBuffer();
        if ( buf.size() == buf.capacity() ) {
            std::cout << "---------------" << std::endl;
            while( buf.size() ) {
                std::cout << buf.pop() << std::endl;
                buf.printBuffer();
            }
        }

    }

    std::cout << "---------------" << std::endl;
    while( buf.size() ) {
        std::cout << buf.pop() << std::endl;
        buf.printBuffer();
    }
    return 0;
}
