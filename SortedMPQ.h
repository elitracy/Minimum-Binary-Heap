#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include <list>
#include <iostream>
#include "MPQ.h"
using namespace std;
/*
 * Minimum Priority Queue based on a linked list
 */
// template <typename T>
// struct Node{
//    T data = 0;
//    int priority = 0;
//    Node *prev,*next;
//    Node(int o=0,int p=0, Node *prev=nullptr, Node *next=nullptr) : data(o), priority(p), prev(prev), next(next){}
// };

template <typename T>
class SortedMPQ: MPQ<T> {
   private:
   // Node<T> head, tail;
   // int size = 0;
   list<T> q;
   public:

   virtual bool is_empty(){ return (q.size() == 0); }

   virtual T min() { return is_empty() ? throw invalid_argument("Queue is empty") : q.front(); }

   virtual T remove_min(){
      if(is_empty()) throw invalid_argument("Queue is Empty");
      T root = q.front();
      q.pop_front();
      return root;
   }

   virtual void insert(const T& data){
         if(is_empty() || data < q.front()) q.push_front(data);
         else{
            auto it = q.begin();
            while(*it < data && it != q.end()) it++;
            q.insert(it--,data);
         }
   }
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // To hold the elements use std::list
   // For remove_min() and min() throw exception if the SortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
};

#endif