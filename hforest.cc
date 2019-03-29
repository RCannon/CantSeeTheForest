#include "hforest.hh"
#include <memory>
#include <vector>
#include <algorithm>
#include <cassert>

// this is the comparison function to be used int std::make_heap to make a heap of tree_ptr_t
bool HForest::compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2) 
{
    return t1->get_value() < t2->get_value();
}

// member function for getting size of forest
HForest::HForest() : sz_(0) {}

// adds a tree to the current forest, then adjusts vector container to retain heap structure
void HForest::add_tree(HTree::tree_ptr_t htree)
{
    vec_.push_back(htree);
    sz_ = sz_ + 1;
    std::make_heap(vec_.begin(), vec_.end(), &HForest::compare_trees);
    return;
}

// returns the tree_ptr_t with the largest value, and removes it from the heap
HTree::tree_ptr_t HForest::pop_tree()
{
    assert(sz_ >= 0);
    sz_ = sz_ - 1;
    HTree::tree_ptr_t largest = vec_.front();
    pop_heap(vec_.begin(), vec_.end(), &HForest::compare_trees); //move first elt. in heap to back of vector
    vec_.pop_back(); // remove back elt. of vector and decrease vector size by 1
    return largest;
}

