Reilly Cannon - Can't See the Forest Through the Trees

    The HTree class is an implementation of a binary tree, where each tree holds and integer key_, an unsigned, 64-bit integer value_, and pointers to the left and right child of that node. The class has member functions that allow a user to read the value_ and the key_ of a node, as well as get pointers to the left and right child of the node and determine the path, from the tree rooted at the current node, to a node with a desired key, if that key exists in the tree. 

    There is also a function that returns a shared pointer to a new instance of constant HTree object with the desired inputs. One cannot modify the inputs of the tree after it is created, at least not without extreme trickery. 

    The HForest class describes a forest of HTrees. It has a size attribute .sz_, and it stores constant, shared pointers to the roots of HTrees in a max-heap (ordered in terms of the value_ attribute of the roots of the htrees), implemented inside a vector container. I chose a vector as the constainer because it seemed to be the safest method in the opinion of the creator of C++. 

    The HForest class has various functions. The first is a size() function that returns the number of trees in the forest. Another is add_tree() which allows the user to add a new tree to the forest, adjusting the order of the htrees in the vector is necessary to maintain the heap. Finally, pop_tree() removes the tree with the root that has the largest value_ attribute and returns it to the user. It then updates an maintains the heap.