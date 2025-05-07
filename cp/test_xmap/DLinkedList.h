/*
 * File:   DLinkedList.h
 */

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "IList.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <type_traits>
using namespace std;

template <class T> class DLinkedList : public IList<T> {
public:
  class Node;        // Forward declaration
  class Iterator;    // Forward declaration
  class BWDIterator; // Forward declaration
  
protected:
  Node *head; // this node does not contain user's data
  Node *tail; // this node does not contain user's data
  int count;
  bool (*itemEqual)(T &lhs, T &rhs); // function pointer: test if two items
                                     // (type: T&) are equal or not
  void (*deleteUserData)(
      DLinkedList<T> *); // function pointer: be called to remove items (if they
                         // are pointer type)

public:
  DLinkedList(void (*deleteUserData)(DLinkedList<T> *) = 0,
              bool (*itemEqual)(T &, T &) = 0);
  DLinkedList(const DLinkedList<T> &list);
  DLinkedList<T> &operator=(const DLinkedList<T> &list);
  ~DLinkedList();
  
  // Inherit from IList: BEGIN
  void add(T e);
  void add(int index, T e);
  T removeAt(int index);
  bool removeItem(T item, void (*removeItemData)(T) = 0);
  bool empty();
  int size();
  void clear();
  T &get(int index);
  int indexOf(T item);
  bool contains(T item);
  string toString(string (*item2str)(T &) = 0);
  void initEmptyList();
  // Inherit from IList: END

  void println(string (*item2str)(T &) = 0) {
    cout << toString(item2str) << endl;
  }
  void setDeleteUserDataPtr(void (*deleteUserData)(DLinkedList<T> *) = 0) {
    this->deleteUserData = deleteUserData;
  }

  bool contains(T array[], int size) {
    int idx = 0;
    for (DLinkedList<T>::Iterator it = begin(); it != end(); it++) {
      if (!equals(*it, array[idx++], this->itemEqual))
        return false;
    }
    return true;
  }

  /*
   * free(DLinkedList<T> *list):
   *  + to remove user's data (type T, must be a pointer type, e.g.: int*,
   * Point*)
   *  + if users want a DLinkedList removing their data,
   *      he/she must pass "free" to constructor of DLinkedList
   *      Example:
   *      DLinkedList<T> list(&DLinkedList<T>::free);
   */
  static void free(DLinkedList<T> *list) {
    typename DLinkedList<T>::Iterator it = list->begin();
    while (it != list->end()) {
      delete *it;
      it++;
    }
  }

  /* begin, end and Iterator helps user to traverse a list forwardly
   * Example: assume "list" is object of DLinkedList

   DLinkedList<char>::Iterator it;
   for(it = list.begin(); it != list.end(); it++){
          char item = *it;
          std::cout << item; //print the item
   }
   */
  Iterator begin() { return Iterator(this, true); }
  Iterator end() { return Iterator(this, false); }

  /* last, beforeFirst and BWDIterator helps user to traverse a list backwardly
   * Example: assume "list" is object of DLinkedList

   DLinkedList<char>::BWDIterator it;
   for(it = list.last(); it != list.beforeFirst(); it--){
          char item = *it;
          std::cout << item; //print the item
   }
   */
  BWDIterator bbegin() { return BWDIterator(this, true); }
  BWDIterator bend() { return BWDIterator(this, false); }

protected:
  bool constructorCheck = false;
  void checkIndex(int index);

  static bool equals(T &lhs, T &rhs, bool (*itemEqual)(T &, T &)) {
    if (itemEqual == 0) {
      return lhs == rhs;
    }
    else {
      return itemEqual(lhs, rhs);
    }
  }
  void copyFrom(const DLinkedList<T> &list);
  void removeInternalData();
  Node *getPreviousNodeOf(int index);

  //////////////////////////////////////////////////////////////////////
  ////////////////////////  INNER CLASSES DEFNITION ////////////////////
  //////////////////////////////////////////////////////////////////////
public:
  class Node {
  public:
    T data;
    Node *next;
    Node *prev;
    friend class DLinkedList<T>;

  public:
    Node(Node *next = 0, Node *prev = 0) {
      this->next = next;
      this->prev = prev;
    }
    Node(T data, Node *next = 0, Node *prev = 0) {
      this->data = data;
      this->next = next;
      this->prev = prev;
    }
  };

  //////////////////////////////////////////////////////////////////////
  class Iterator {
  private:
    DLinkedList<T> *pList;
    Node *pNode;

  public:
    Iterator(DLinkedList<T> *pList = 0, bool begin = true) {
      if (begin) {
        if (pList != 0)
          this->pNode = pList->head->next;
        else
          pNode = 0;
      } else {
        if (pList != 0)
          this->pNode = pList->tail;
        else
          pNode = 0;
      }
      this->pList = pList;
    }

    Iterator &operator=(const Iterator &iterator) {
      this->pNode = iterator.pNode;
      this->pList = iterator.pList;
      return *this;
    }
    void remove(void (*removeItemData)(T) = 0) {
      pNode->prev->next = pNode->next;
      pNode->next->prev = pNode->prev;
      Node *pNext = pNode->prev; // MUST prev, so iterator++ will go to end
      if (removeItemData != 0)
        removeItemData(pNode->data);
      delete pNode;
      pNode = pNext;
      pList->count -= 1;
    }

    T &operator*() { return pNode->data; }
    bool operator!=(const Iterator &iterator) {
      return pNode != iterator.pNode;
    }
    // Prefix ++ overload
    Iterator &operator++() {
      pNode = pNode->next;
      return *this;
    }
    // Postfix ++ overload
    Iterator operator++(int) {
      Iterator iterator = *this;
      ++*this;
      return iterator;
    }
    friend class BWDIterator;
  };

  class BWDIterator {
  public:
    Iterator it;
  
  public:
    BWDIterator(DLinkedList<T> *pList = 0, bool begin = true) {
      it = Iterator(pList);
      if (begin) {
        if (pList != 0)
          it.pNode = pList->tail->prev;
        else
          it.pNode = 0;
      } else {
        if (pList != 0)
          it.pNode = pList->head;
        else
          it.pNode = 0;
      }
    }
    
    BWDIterator &operator=(const BWDIterator &iterator) {
      this->it = iterator.it;
    }
    bool operator!=(const Iterator &iterator) {
      return this->it != iterator.it;
    }
    void remove(void (*removeItemData)(T) = 0) {
      it.pNode->prev->next = it.pNode->next;
      it.pNode->next->prev = it.pNode->prev;
      Node *pPext = it.pNode->next; // MUST next, so iterator++ will go to end
      if (removeItemData != 0)
        removeItemData(it.pNode->data);
      delete it.pNode;
      it.pNode = pPext;
      it.pList->count -= 1;
    }
    
    T &operator*() { return this->it.pNode->data; }

    bool operator!=(const BWDIterator &iterator) {
      return this->it.pNode != iterator.it.pNode;
    }
    // Prefix ++ overload
    BWDIterator &operator++() {
      it.pNode = it.pNode->prev;
      return *this;
    }
    // Postfix ++ overload
    BWDIterator operator++(int) {
      BWDIterator iterator = *this;
      ++*this;
      return iterator;
    }
  };
};
//////////////////////////////////////////////////////////////////////
// Define a shorter name for DLinkedList:

template <class T> using List = DLinkedList<T>;

//////////////////////////////////////////////////////////////////////
////////////////////////     METHOD DEFNITION      ///////////////////
//////////////////////////////////////////////////////////////////////

template<class T> void DLinkedList<T>::initEmptyList() {
  this->tail = new Node();
  this->head = new Node(tail, nullptr);
  this->tail->prev = head;
}

template <class T>
DLinkedList<T>::DLinkedList(void (*deleteUserData)(DLinkedList<T> *),
                            bool (*itemEqual)(T &, T &)) {
  
  constructorCheck = true;
  initEmptyList();
  setDeleteUserDataPtr(deleteUserData);
  this->itemEqual = itemEqual;
  this->count = 0;
}

template <class T> DLinkedList<T>::DLinkedList(const DLinkedList<T> &list) {
  copyFrom(list);
}

template <class T>
DLinkedList<T> &DLinkedList<T>::operator=(const DLinkedList<T> &list) {
  copyFrom(list);
  // return DLinkedList<T>(list);
  return *this;
}

template <class T> DLinkedList<T>::~DLinkedList() {
  removeInternalData();
}

template <class T> void DLinkedList<T>::add(T e) {
  
  Node *element = new Node(e, tail, tail->prev);
  tail->prev->next = element;
  tail->prev = element;
  count += 1;
}
template <class T> void DLinkedList<T>::add(int index, T e) {
  
  if (index < 0 || index > count) {
    throw out_of_range("Index is out of range!");
  }
  Node *current = getPreviousNodeOf(index);
  Node *add = new Node(e, current->next, current);
  current->next->prev = add;
  current->next = add;
  count += 1;
}

template <class T>
typename DLinkedList<T>::Node *DLinkedList<T>::getPreviousNodeOf(int index) {
  if (index < 0 || index > count) {
    throw out_of_range("Index is out of range!");
  }
  if (index * 2 <= count) {
    Node *current = head;
    for (int i = 0; i < index; i++) {
      current = current->next;
    }
    return current;
  } else {
    Node *current = tail;
    for (int i = count - 1; i >= index - 1; i--) {
      current = current->prev;
    }
    return current;
  }
}

template <class T> T DLinkedList<T>::removeAt(int index) {
  // TODO
  checkIndex(index);
  Node *current = getPreviousNodeOf(index);
  Node *to_be_deleted = current->next;
  T ret = to_be_deleted->data;
  current->next->next->prev = current;
  current->next = current->next->next;
  delete to_be_deleted;
  count -= 1;
  return ret;
}

template <class T> bool DLinkedList<T>::empty() {
  // TODO
  return count == 0;
}

template <class T> int DLinkedList<T>::size() {
  // TODO
  return count;
}

template <class T> void DLinkedList<T>::clear() {
  // TODO
  removeInternalData();
  initEmptyList();
}

template <class T> T &DLinkedList<T>::get(int index) {
  
  checkIndex(index);
  return getPreviousNodeOf(index)->next->data;
}

template <class T> int DLinkedList<T>::indexOf(T item) {
  Node *current = head;
  for (int i = 0; i < count && current->next != tail; i++) {
    current = current->next;
    if (equals(current->data, item, itemEqual)) {
      return i;
    }
  }
  return -1;
}

template <class T>
bool DLinkedList<T>::removeItem(T item, void (*removeItemData)(T)) {
  if (empty()) {
    return false;
  }
  Node *current = head;
  int index = 0;
  while (current->next != tail) {
    current = current->next;
    if (equals(current->data, item, itemEqual)) {
      if (removeItemData != nullptr) {
        removeItemData(current->data);
      }   
      break;  
    }
    index += 1;
  }
  if (index == count) {
    return false;
  }
  current->prev->next = current->next;
  current->next->prev = current->prev;
  count -= 1;
  delete current;
  return true;
}

template <class T> bool DLinkedList<T>::contains(T item) {
  return indexOf(item) != -1;
}

template <class T> string DLinkedList<T>::toString(string (*item2str)(T &)) {
  Node *current = head;
  stringstream oss;
  oss << "[";
  for (int i = 0; i < count; i++) {
    current = current->next;
    if (item2str != nullptr) {
      oss << item2str(current->data);
    } else {
      oss << current->data;
    }
    if (i < count - 1) {
      oss << ", ";
    }
  }
  oss << "]";
  return oss.str();
}

template <class T> void DLinkedList<T>::copyFrom(const DLinkedList<T> &list) {
  if (constructorCheck == false) {
    initEmptyList();
  }
  removeInternalData();
  setDeleteUserDataPtr(list.deleteUserData);
  this->itemEqual = list.itemEqual;
  if (list.head == nullptr) {
    return;
  }
  initEmptyList();
  Node *current = list.head;
  int i = 0;
  while (current->next != list.tail) {
    current = current->next;
    add(current->data);
  }
}

template <class T> void DLinkedList<T>::removeInternalData() {
  if (deleteUserData != nullptr) {
    deleteUserData(this);
  } else {
    Node *current = head;
    if (current == nullptr) {
        return;
    }
    Node *prev = current;
    current = current->next;
    while (current != nullptr) {
      delete prev;
      prev = current;
      current = current->next;
    }
  }
  count = 0;
}

template <class T> void DLinkedList<T>::checkIndex(int index) {
  if (index < 0 || index >= count) {
    throw out_of_range("Index is out of range!");
  }
}
#endif /* DLINKEDLIST_H */
