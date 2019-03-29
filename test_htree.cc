



//NOTE: I chose to combine the test files for HTree and HForest into this file

#include "htree.hh"
#include "hforest.hh"
#include<iostream>
#include<cassert>

int general1(){ // basic test to make sure member fuunctions on one tree work correctly
    HTree t13 = {4, 0};

    assert(t13.get_key() == 4);
    assert(t13.get_value() == 0);

    assert(t13.get_child(HTree::Direction::LEFT) == nullptr);
    assert(t13.get_child(HTree::Direction::RIGHT) == nullptr);


    return 0;
}

int general2(){ // testing get_child()

    HTree::tree_ptr_t t13 = make_htree(4, 0);
    HTree::tree_ptr_t t12 = make_htree(7, 0, nullptr, t13);

    assert(t13->get_child(HTree::Direction::LEFT) == nullptr);
    assert(t13->get_child(HTree::Direction::RIGHT) == nullptr);
    assert(t12->get_child(HTree::Direction::LEFT) == nullptr);
    assert(t12->get_child(HTree::Direction::RIGHT) == t13);

    return 0;
}

int general3() // (roughly) copy of test from HW6 - testing full htree structure
{
    HTree::tree_ptr_t t13 = make_htree(4, 0);
    HTree::tree_ptr_t t12 = make_htree(7, 0);
    HTree::tree_ptr_t t11 = make_htree(-1, 0);
    HTree::tree_ptr_t t10 = make_htree(4, 0);
    HTree::tree_ptr_t t9 = make_htree(-1, 0);
    HTree::tree_ptr_t t8 = make_htree(5, 0);
    HTree::tree_ptr_t t7 = make_htree(0, 0, nullptr, t13);
    HTree::tree_ptr_t t6 = make_htree(0, 0, t11, t12);
    HTree::tree_ptr_t t5 = make_htree(5, 0, t9, t10);
    HTree::tree_ptr_t t4 = make_htree(5, 0, nullptr, t8);
    HTree::tree_ptr_t t3 = make_htree(2, 0, t6, t7);
    HTree::tree_ptr_t t2 = make_htree(5, 0, t4, t5);
    HTree::tree_ptr_t t1 = make_htree(1, 0, t2, t3);

    assert(t1->get_child(HTree::Direction::LEFT) == t2);
    assert(t1->get_child(HTree::Direction::RIGHT) == t3);
    assert(t1->get_key() == 1);
    assert(t1->get_value() == 0);

    assert(t2->get_child(HTree::Direction::LEFT) == t4);
    assert(t2->get_child(HTree::Direction::RIGHT) == t5);
    assert(!(t2->get_key() == 100));
    assert(!(t2->get_value() == 1000));

    assert(t6->get_child(HTree::Direction::LEFT) == t11);
    assert(t6->get_child(HTree::Direction::RIGHT) == t12);
    assert(t6->get_key() == 0);
    assert(t6->get_value() == 0);

    HTree::path_t the_path1 = t1->path_to(4);

    for (auto v : the_path1)
        std::cout << static_cast<int>(v) << "\n";


    std::cout << "\n" << "\n";


    HTree::path_t the_path2 = t1->path_to(7);

    for (auto v : the_path2)
        std::cout << static_cast<int>(v) << "\n";


    std::cout << "\n" << "\n";


    HTree::path_t the_path3 = t1->path_to(5);

    for (auto v : the_path3)
        std::cout << static_cast<int>(v) << "\n";


    return 0;

}

// Below are the functions I used for testing HForest

int general4() // general test to make sure all functions work individually
{
    HForest for1;

    std::cout << for1.size() << "\n";

    HTree::tree_ptr_t t13 = make_htree(4, 6);
    HTree::tree_ptr_t t12 = make_htree(7, 99);

    for1.add_tree(t13);

    std::cout << for1.size() << "\n";

    for1.add_tree(t12);

    std::cout << for1.size() << "\n";

    HTree::tree_ptr_t tex1 = for1.pop_tree();

    std::cout << for1.size() << "\n";

    std::cout << tex1->get_value() << "\n";

    HTree::tree_ptr_t tex2 = for1.pop_tree();

    std::cout << for1.size() << "\n";

    std::cout << tex2->get_value() << "\n";

    return 0;
}

int general5() // test I used for debugging error with popping same tree over and over
{
    HTree::tree_ptr_t t13 = make_htree(4, 1);
    HTree::tree_ptr_t t12 = make_htree(7, 3);
    HTree::tree_ptr_t t11 = make_htree(-1, 3);

    HForest for1;

    std::cout << for1.size() << "\n";

    for1.add_tree(t13);
    for1.add_tree(t12);
    for1.add_tree(t11);

    std::cout << for1.pop_tree()->get_value() << "\n";
    std::cout << for1.pop_tree()->get_value() << "\n";
    std::cout << for1.pop_tree()->get_value() << "\n";

    return 0;
}

int general6(){ // test forest with unigue values

    HTree::tree_ptr_t t13 = make_htree(4, 1);
    HTree::tree_ptr_t t12 = make_htree(7, 3);
    HTree::tree_ptr_t t11 = make_htree(-1, 3);
    HTree::tree_ptr_t t10 = make_htree(4, 4);
    HTree::tree_ptr_t t9 = make_htree(-1, 5);
    HTree::tree_ptr_t t8 = make_htree(5, 6);
    HTree::tree_ptr_t t7 = make_htree(0, 7);
    HTree::tree_ptr_t t6 = make_htree(0, 8);
    HTree::tree_ptr_t t5 = make_htree(5, 9);
    HTree::tree_ptr_t t4 = make_htree(5, 10);
    HTree::tree_ptr_t t3 = make_htree(2, 11);
    HTree::tree_ptr_t t2 = make_htree(5, 12);
    HTree::tree_ptr_t t1 = make_htree(1, 13);

    HForest for1;

    std::cout << for1.size() << "\n";

    for1.add_tree(t13);
    for1.add_tree(t12);
    for1.add_tree(t11);
    for1.add_tree(t10);
    for1.add_tree(t9);
    for1.add_tree(t8);
    for1.add_tree(t7);
    for1.add_tree(t6);
    for1.add_tree(t5);
    for1.add_tree(t4);
    for1.add_tree(t3);
    for1.add_tree(t2);
    for1.add_tree(t1);

    assert(for1.size() == 13);


    HTree::tree_ptr_t tex;
    int i = for1.size();

    while (i != 0){
        tex = for1.pop_tree();
        std::cout << "size after pop:" << for1.size() << "\n";
        std::cout << "value of popped tree:" << tex->get_value() << "\n";
        i = i -1;
    }
    return 0;
}

int general7() // test forest with recurring values
{
    HTree::tree_ptr_t t13 = make_htree(4, 4);
    HTree::tree_ptr_t t12 = make_htree(7, 7);
    HTree::tree_ptr_t t11 = make_htree(-1, 1);
    HTree::tree_ptr_t t10 = make_htree(4, 4);
    HTree::tree_ptr_t t9 = make_htree(-1, 1);
    HTree::tree_ptr_t t8 = make_htree(5, 5);
    HTree::tree_ptr_t t7 = make_htree(0, 0);
    HTree::tree_ptr_t t6 = make_htree(0, 0);
    HTree::tree_ptr_t t5 = make_htree(5, 5);
    HTree::tree_ptr_t t4 = make_htree(5, 5);
    HTree::tree_ptr_t t3 = make_htree(2, 2);
    HTree::tree_ptr_t t2 = make_htree(5, 5);
    HTree::tree_ptr_t t1 = make_htree(1, 1);

    HForest for1;

    std::cout << for1.size() << "\n";

    for1.add_tree(t13);
    for1.add_tree(t12);
    for1.add_tree(t11);
    for1.add_tree(t10);
    for1.add_tree(t9);
    for1.add_tree(t8);
    for1.add_tree(t7);
    for1.add_tree(t6);
    for1.add_tree(t5);
    for1.add_tree(t4);
    for1.add_tree(t3);
    for1.add_tree(t2);
    for1.add_tree(t1);

    assert(for1.size() == 13);


    HTree::tree_ptr_t tex;
    int i = for1.size();

    while (i != 0){
        tex = for1.pop_tree();
        std::cout << "size after pop:" << for1.size() << "\n";
        std::cout << "value of popped tree:" << tex->get_value() << "\n";
        i = i -1;
    }
    return 0;
}


int main(){

    general1();

    general2();

    general3();

    std::cout << ". . . " << "\n" << ". . ." << "\n";

    general4();

    std::cout << ". . . " << "\n" << ". . ." << "\n";

    general5();

    std::cout << ". . . " << "\n" << ". . ." << "\n";

    general6();

    std::cout << ". . . " << "\n" << ". . ." << "\n";

    general7();

    return 0;

}