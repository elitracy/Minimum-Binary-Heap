#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <vector>
#include "MPQ.h"
#include <iostream>

using namespace std;

/**
 * Minimum Priority Queue based on a vector
 */

template <typename T>
class UnsortedMPQ: MPQ<T> {

   private:
   vector<T> q;
   public:

    virtual T remove_min(){
      if(is_empty()) throw invalid_argument("Queue is Empty");
      T min = q[0];
      int minIndex = 0;
      for(int i = 0; i < q.size(); i++){
         if(q[i] < min){
            min = q[i];
            minIndex = i;
         }
      }
      q.erase(q.begin()+minIndex);
      return min;
    }
    // Get the minimum from MPQ
    virtual T min(){
      if(is_empty()) throw invalid_argument("Queue is Empty");

      T min = q[0];
      for(int i = 0; i < q.size(); i++){
         if(q[i] < min){
            min = q[i];
         }
      }
      return min;
    }
    // Check if MPQ is empty
    virtual bool is_empty() { return q.size() == 0; }
    // Insert into MPQ
    virtual void insert(const T& data) { q.push_back(data); };
};
#endif