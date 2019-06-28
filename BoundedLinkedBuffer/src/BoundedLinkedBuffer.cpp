
template <class T>
BoundedLinkedBuffer<T>::BoundedLinkedBuffer(unsigned int maxNumElts,
                                          std::allocator &allocator) {
  this.maxNumElts = maxNumElts;
  this.allocator = allocator;

  unsigned int bufsize = sizeof(LinkedBufferPosition<T>) * maxNumElts;
  buffer = (LinkedBufferPosition<T> *) allocator.allocate(bufsize);

  LinkedBufferPosition<T> *end = (LinkedBufferPosition<T> *)
        ((unsigned char *) buffer + bufsize - sizeof(LinkedBufferPosition<T>));
  LinkedBufferPosition<T> *current = buffer;

  while (current < end) {
    LinkedBufferPosition<T> *next = (LinkedBufferPosition<T> *) 
                ((unsigned char *) current + sizeof(LinkedBufferPosition<T>));
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


template <class T>
void BoundedLinkedBuffer<T>::changeBufferSize(unsigned int maxNumElts) {
  if (this.maxNumElts == maxNumElts)
    return;

  assert(maxNumElts >= size && "May not change buffer size to be less than the "
                               "current number of elements.");

  unsigned int oldBufsize = sizeof(LinkedBufferPosition<T>) * this.maxNumElts;
  unsigned int newBufsize = sizeof(LinkedBufferPosition<T>) * maxNumElts;
  LinkedBufferPosition<T> *newBuffer = (LinkedBufferPosition<T> *)
          allocator.allocate(newBufsize);

  LinkedBufferPosition<T> *current = newBuffer;
  LinkedBufferPosition<T> *oldCurrentPosition = head;

  while (oldCurrentPosition) {
    LinkedBufferPosition<T> *next = (LinkedBufferPosition<T> *) 
                ((unsigned char *) next + sizeof(LinkedBufferPosition<T>));
    *current = LinkedBufferPosition(oldCurrentPosition->getElement(), next);
    oldCurrentPosition = oldCurrentPosition->getNext();
    current = next;
  }

  //set the end of the list to null.
  current.setNext(nullptr);

  if (maxNumElts == size) {
    freeList = nullptr;
    buffer = newBuffer;
    head = newBuffer;
    return;
  }

  freeList = current;
  LinkedBufferPosition<T> *end = (LinkedBufferPosition<T> *)
        ((unsigned char *) newBuffer + newBufsize -
                sizeof(LinkedBufferPosition<T>));

  while (current < end) {
    LinkedBufferPosition<T> *next = (LinkedBufferPosition<T> *) 
                ((unsigned char *) current + sizeof(LinkedBufferPosition<T>));
    *current = LinkedBufferPosition(next);
    current = next;
  }

  *current = LinkedBufferPosition(nullptr);
  buffer = newBuffer;
  head = newBuffer;
}

template <class T>
void BoundedLinkedBuffer<T>::truncateBuffer(unsigned int maxNumElts) {
  //TODO
}

template <class T>
void BoundedLinkedBuffer<T>::truncateBufferFirstElts(unsigned int maxNumElts) {
  //TODO
}

template <class T>
void BoundedLinkedBuffer<T>::empty() {
  //TODO
}

template <class T>
T BoundedLinkedBuffer<T>::get(unsigned int index) {
  return getPosition(index).getElement();
}

template <class T>
const LinkedBufferPosition<T> &getPosition(unsigned int index) {
  assert(index <= size && "Index specified was out of bounds.");

  LinkedBufferPosition<T> *current = buffer;
  while (index--)
    current = current.getNext();
  return current;
}

template <class T>
void BoundedLinkedBuffer<T>::

template <class T>
void BoundedLinkedBuffer<T>::
