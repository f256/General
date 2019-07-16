/****
* 
* TODO: Thread safety.
*/

//TODO: For true positionalList properties, use double linking.
template <class T>
class LinkedBufferPosition {
  public:
    LinkedBufferPosition(T element, LinkedBufferPosition<T> *next);
    LinkedBufferPosition(LinkedBufferPosition<T> *next);
    LinkedBufferPosition(T element);
    LinkedBufferPosition();
    LinkedBufferPosition(const LinkedBufferPosition<T> &copy_from);
    LinkedBufferPosition<T>& operator=
                        (const LinkedBufferPosition<T> &copy_from);
    ~LinkedBufferPosition();

    T getElement();
    LinkedBufferPosition<T> *getNext();
    bool allocated();

    void setElement(T element);
    T replaceElement(T element);

    void setNext(LinkedBufferPosition<T> *next);
    LinkedBufferPosition<T> *replaceNext(LinkedBufferPosition<T> *next);

    void setAllocated();
  private:
    bool allocated;
    T element;
    LinkedBufferPosition<T> *next;
}

template <class T>
class BoundedLinkedBuffer {
  public:
    BoundedLinkedBuffer(unsigned int maxNumElts, std::allocator &allocator);
    BoundedLinkedBuffer(unsigned int maxNumElts);
    BoundedLinkedBuffer(const BoundedLinkedBuffer<T> &copy_from);
    BoundedLinkedBuffer<T>& operator=(const BoundedLinkedBuffer<T> &copy_from);
    ~BoundedLinkedBuffer()

//Informative functions.

    unsigned int size();
    unsigned int getMaxNumElts();
    
    bool isEmpty();

//Control functions.

    void changeBufferSize(unsigned int maxNumElts);
    void truncateBuffer(unsigned int maxNumElts);
    void truncateBufferFirstElts(unsigned int maxNumElts);
    void clear();

//Core Linked List functionality.

    T get(unsigned int index);
    void add(T element, unsigned int index);
    T remove(T element, unsigned int index);
    T set(T element, unsigned int index);

//Stack and Queue behavior hooks.
//This behavior may be omitted to
//create a lighter weight class.

#ifdef DS_ADAPTATION

    T peek(); //=T front
    void push(T element);
    T pop();
    void enqueue(T element);
    T dequeue(T element);
  private:
    std::allocator &allocator;
    unsigned int size;
    unsigned int maxNumElts;
    LinkedBufferPosition<T> *freeList;
    LinkedBufferPosition<T> *buffer;
    LinkedBufferPosition<T> *head;
    LinkedBufferPosition<T> *tail;

    reallocateBuffer(unsigned int numElts);

#endif
};
