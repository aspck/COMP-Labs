/*
 * A linked implementation of a TEMPLATE stack that can be used to store objects
 *
 * File:   Stack.hpp
 * Author: dale
 *
 * Created on Oct. 22, 2018
 */

#ifndef STACK_HPP
#define	STACK_HPP

#include <cstdlib>
#include "StackException.hpp"

template <class T> class Stack {
 private:
  // The node that will be used for the Stack
  typedef struct stackNode {
    struct stackNode *next;
    T theItem;
  } StackNode;

  /** A pointer to the StackNode at the top of the stack */
  StackNode *topOfStack;
  /** The number of items currently on the stack */
  int count;
 public:
  /** Constructor initializes the data members */
  inline Stack () : topOfStack(NULL), count(0) {
  }

  /**
   * Push an item onto the stack
   *
   * @param the item to be stored
   */
  void push(T item) {
      // allocate a new stacknode that will remain after this function ends
      StackNode* temp = new StackNode({topOfStack, item});  
      
      // point the stack to the new node
      topOfStack = temp;
      
      // increment counter
      count++;
  }



  /**
   * Remove an item from the stack
   *
   * @throw A StackException if the stack is empty
   * @return the Item
   */
  T pop(void)  {
     T item;
    //get the item from the node at the top of the stack

     if (topOfStack == NULL)
     {
         throw StackException("stack exception: no items in stack!");
         return NULL;
     }
     
    item  = topOfStack->theItem;

    //save a reference to the stack node for deletion
    StackNode *temp = topOfStack;

    //point the top of the stack to the next node in the stack
    topOfStack = topOfStack->next;

    //delete the old/empty stacknode
    delete temp;

    count--;    

    return item;
  }



  /**
   * Peek at the item at the top of the stack
   *
   * @throw A StackException if the stack is empty
   * @return
   */
  T top(void)  {
    if (topOfStack == NULL)
    {
        throw StackException("stack exception: no items in stack!");
        return NULL;
    }
    
    return topOfStack->theItem;
  }


  /**
   * The number of items currently on the stack
   * @return That number
   */
  inline int size(void) {
    return count;
  }

  /**
   * Query if the stack is empty
   *
   * @return true if the stack is empty
   */
  inline bool isEmpty(void) {
    return count == 0;
  }
};


#endif	/* STACK_HPP */

