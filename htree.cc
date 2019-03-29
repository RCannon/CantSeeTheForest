#include "htree.hh"
#include <memory>
#include <list>
#include <cassert>

// constructor for HTree
HTree::HTree(int key,
            uint64_t value,
            HTree::tree_ptr_t left,
            HTree::tree_ptr_t right) 
            : key_(key), value_(value), left_(left), right_(right) {}


// returns the child of the current node in the direction specified
HTree::tree_ptr_t HTree::get_child(HTree::Direction dir) const
{
    if (dir == Direction::LEFT)
        return left_;
    else return right_;
}


// helper function for path_to: determines if the desired key exists in the tree
bool HTree::exist_key(int key) const
{
    return (get_key() == key
            || (left_ && left_->exist_key(key))
            || (right_ && right_->exist_key(key)));
}


// returns a path (in the form of a linked-list) to the mode 
// in the tree with the desired key, if it exists. It
// prioritizes the top, leftmost node of the tree with the desired key, and it
// uses the linked-list.push_back() function to append directions to returned linked-list
HTree::path_t HTree::path_to(int key) const
{
    assert(exist_key(key));
    std::list<HTree::Direction> dir = {};
    HTree::tree_ptr_t current = this->left_;

    if (get_key() == key)
        return dir;

    else if (current && current->exist_key(key)){
        dir.push_back(HTree::Direction::LEFT);
    }
    else {
        dir.push_back(HTree::Direction::RIGHT);
        current = this->right_;
    }

    while (current->get_key() != key){

        if (current->left_ && current->left_->exist_key(key)){
            dir.push_back(HTree::Direction::LEFT);
            current = current->left_;
        }

        else {
            dir.push_back(HTree::Direction::RIGHT);
            current = current->right_;
        }
    }

    return dir;
}


// non-member function, used to create a shared pointer that points to an 
// instance of an HTree
HTree::tree_ptr_t make_htree(int key, 
                            uint64_t value, 
                            HTree::tree_ptr_t left,
                            HTree::tree_ptr_t right)
{
    return std::make_shared<const HTree>(key, value, left, right);
}


