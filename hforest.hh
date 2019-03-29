#pragma once

#include <memory>
#include <vector>
#include <algorithm>
#include "htree.hh"


class HForest {
  public:

    HForest();

    ~HForest() = default;

    int size() { return sz_; } 

    void add_tree(HTree::tree_ptr_t htree);

    HTree::tree_ptr_t pop_tree();

  private:
    int sz_; // integer that stores the number of trees in the heap

    // vecotr of tree_ptr_t: vecotr elements are pointers to the roots of the trees
    std::vector<HTree::tree_ptr_t> vec_;

    // this is the declaration of the comparison function for building the heap
    static bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2);

};