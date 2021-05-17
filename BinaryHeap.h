#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>

/*
 * Binary Heap class
 */
template <typename T>
class BinaryHeap {
    public:
        //Implement the below 4 methods. Please note these methods are not from MPQ.h
        //BinaryHeap class does not inherit MPQ class 
        //Implement BinaryHeap insert operation
        //Also implement upheap and downheap operations (functions provided below) and call them from wherever necessary
        void insert(const T& data){
            elements.push_back(data); // put data in back

            int i = elements.size()-1; // index = data's index
            // cout << *this << endl;
            while(i != 0 && elements[i] < elements[parent(i)]){ // while parent is greater than child
                swap(i,parent(i)); // swap parent and child
                i = parent(i); // index is now the parent index
            }
        }
        // Return true if BinaryHeap is empty otherwise false
        bool is_empty() {return (elements.size() == 0); }
        // Return minimum element in the BinaryHeap
        T min(){ return (is_empty()) ? throw std::invalid_argument("Queue is Empty") : elements[0]; }

        // Remove minimum element in the BinaryHeap and return it
        T remove_min(){
            if(elements.size() <= 0) throw std::invalid_argument("Queue is Empty");
            if(elements.size() == 1){
                T root = elements[0];
                elements.pop_back();
                return root;
            }
            T root = elements[0];
            elements[0] = elements[elements.size()-1];
            elements.pop_back();
            down_heap(0);
            return root;
        }
    private:
        //
        std::vector<T> elements;
        int size = 0;
        //Implement down heap operation
        void down_heap(int i);
        //Implement up heap operation
        void up_heap(int i);

        //Pre-implemented helper functions
        //swaps two elements at positions a and b
        void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}
        //Binary tree (Complete Binary tree) can be represented in vector form and hence, stored in a vector. 
        //Returns the right child index of current index
        int right_child(int i) {return 2*i + 2;}
        //Returns the left child index of current index
        int left_child(int i) {return 2*i + 1;}
        //Returns the parent index of current index
        int parent(int i) {return floor((i-1)/2);}
        //Checks if current index is an internal node
        bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}
        //Checks if current index is a leaf
        bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

/*
 * Restores the binary heap property starting from a node that is smaller than its parent
 */
template <typename T>
void BinaryHeap<T>::up_heap(int i){
    int parent_index = parent(i);

    if(elements[i] < elements[parent_index] && i != 0){
        swap(i,parent_index);
        up_heap(parent_index);
    }
}

/*
 * Restores the binary heap property starting from an node that is larger than its children
 */
template <typename T>
void BinaryHeap<T>::down_heap(int i){
    int right = right_child(i);
    int left = left_child(i);
    int min = i;
    if(left < elements.size() && elements[left] < elements[i]) min = left;
    if(right < elements.size() && elements[right] < elements[min]) min = right;
    if(min != i){
        swap(i,min);
        down_heap(min);
    }
}

#endif