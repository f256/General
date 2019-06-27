
template <class T>
BoundedLinkedBuffer<T>::BoundedLinkedBuffer(unsigned int maxNumElts,
                                          std::allocator &allocator) {
  this.maxNumElts = maxNumElts;
  this.allocator = allocator;

  unsigned bufsize = sizeof(LinkedBufferPosition<T>) * maxNumElts;
  buffer = (LinkedBufferPosition<T> *) allocator.allocate(bufsize);

  LinkedBufferPosition<T> *end = (LinkedBufferPosition<T> *) 
         ((unsigned char *) buffer + bufsize - sizeof(LinkedBufferPosition<T>));
  LinkedBufferPosition<T> *current = buffer;

  while (current < end) {
    LinkedBufferPosition<T> *next = (LinkedBufferPosition<T> *) 
                ((unsigned char *) buffer + sizeof(LinkedBufferPosition<T>));
    *current = LinkedBufferPosition(next);
    current = next;
  }
  *current = LinkedBufferPosition(nullptr);

  size = 0;
  freeList = buffer;
  head = nullptr;
}

template <class T>
BoundedLinkedBuffer<T>::BoundedLinkedBuffer(unsigned int maxNumElts) {
  this(maxNumElts, std::allocator());
}

template <class T>
BoundedLinkedBuffer<T>::BoundedLinkedBuffer(
                                  const BoundedLinkedBuffer<T> &copy_from) {
  //TODO
}

template <class T>
BoundedLinkedBuffer<T>& BoundedLinkedBuffer<T>::operator=(
                                  const BoundedLinkedBuffer<T> &copy_from) {
  //TODO
}

template <class T>
BoundedLinkedBuffer<T>::~BoundedLinkedBuffer() {
  //TODO
}

template <class T>
unsigned int BoundedLinkedBuffer<T>::size() {
  return size;
}

template <class T>
unsigned int BoundedLinkedBuffer<T>::getMaxNumElts() {
  return maxNumElts;
}

template <class T>
bool BoundedLinkedBuffer<T>::isEmpty() {
  return size == 0;
}

















