#ifndef BINARYHEAP_MPQ_H
#define BINARYHEAP_MPQ_H

#include "BinaryHeap.h"
#include <stdexcept>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a binary heap
 */
template <typename T>
class BinaryHeapMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // It is enough if the 4 methods in  BinaryHeapMPQ calls the corresponding implemented methods in BinaryHeap.h.
   // To hold the elements use BinaryHeap (from BinaryHeap.h)
   // For remove_min() and min() throw exception if the BinaryHeapMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
   private:
   BinaryHeap<T> elements;
   public:
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h

   virtual bool is_empty(){ return elements.is_empty(); }

   virtual T min(){ return (elements.is_empty()) ? throw std::invalid_argument("Queue is Empty") : elements.min(); }

   virtual void insert(const T& data){
      elements.insert(data);
   }

   virtual T remove_min(){
      return elements.remove_min();
   }


   
   std::vector<T> getHeap() const{ return elements; }
   // To hold the elements use std::vector
   // For remove_min() and min() just throw exception if the UnsortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
};
template <typename T>
std::ostream& operator<<(std::ostream& os, const BinaryHeapMPQ<T>& mpq){
      for(int i = 0; i < mpq.getHeap().size(); i++){
         os << mpq.getHeap().at(i) << " ";
      }
      return os;
}


#endif