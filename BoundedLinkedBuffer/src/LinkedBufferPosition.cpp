/**
* This class is the node type used by BoundedLinkedBuffer.
*/


#include "BoundedLinkedBuffer.h"

/**
* Basic constructor for LinkedBufferPosition.
* Sets the element and the pointer to the next LinkedBufferPosition.
*/
template <class T>
LinkedBufferPosition<T>::LinkedBufferPosition(T element, 
                      LinkedBufferPosition<T> *next) {
  this.element = element;
  this.next = next;
}

template <class T>
LinkedBufferPosition<T>::LinkedBufferPosition(T element) {
  this(element, nullptr);
}

template <class T>
LinkedBufferPosition<T>::LinkedBufferPosition(
                      const LinkedBufferPosition<T> &copy_from) {
  //TODO
}

template <class T>
LinkedBufferPosition<T>& LinkedBufferPosition<T>::operator=(
                      const LinkedBufferPosition<T> &copy_from) {
  //TODO
}

template <class T>
LinkedBufferPosition<T>::~LinkedBufferPosition() {
  //TODO
}

template <class T>
void LinkedBufferPosition<T>::setElement(T element) {
  this.element = element;
}

template <class T>
T LinkedBufferPositiona<T>::replaceElement(T element) {
  T temp = this.element;
  this.element = element;
  return temp;
}

template <class T>
void LinkedBufferPosition<T>::setNext(LinkedBufferPosition<T> *next) {
  this.next = next;
}

template <class T>
LinkedBufferPosition<T> *LinkedBufferPosition<T>::replaceNext(
                                  LinkedBufferPosition<T> *next) {
  LinkedBufferPosition<T> *temp = this.next;
  this.next = next;
  return temp;  
}
