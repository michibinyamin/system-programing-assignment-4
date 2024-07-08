// Email - michibinyamin@gmail.com
// Id - 208768978

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"

TEST_CASE("Testing Binary Tree Operations") {
    // Create nodes with integer values
    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3);
    Node<int> node4(4);
    Node<int> node5(5);
    Node<int> node6(6);
    
    Tree<int> intTree;
    intTree.add_root(node1);

    // Add child nodes
    intTree.add_sub_node(node1, node2);
    intTree.add_sub_node(node1, node3);
    intTree.add_sub_node(node2, node4);
    intTree.add_sub_node(node2, node5);
    intTree.add_sub_node(node3, node6);

    // Try adding more then maximum nodes
    Node<int> test_node(7);
    CHECK_THROWS(intTree.add_sub_node(node1, node2));

    // Pre-order traversal check
    auto preOrderIt = intTree.begin_pre_order();
    CHECK(preOrderIt->get_value() == 1);
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == 2);
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == 4);
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == 5);
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == 3);
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == 6);

    // Post-order traversal check
    auto postOrderIt = intTree.begin_post_order();
    CHECK(postOrderIt->get_value() == 4);
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == 5);
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == 2);
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == 6);
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == 3);
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == 1);

    // In-order traversal check
    auto inOrderIt = intTree.begin_in_order();
    CHECK(inOrderIt->get_value() == 4);
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == 2);
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == 5);
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == 1);
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == 6);
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == 3);

    // BFS traversal check
    auto bfsIt = intTree.begin_bfs_scan();
    CHECK(bfsIt->get_value() == 1);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 2);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 3);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 4);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 5);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 6);

    // DFS traversal check
    auto dfsIt = intTree.begin_dfs_scan();
    CHECK(dfsIt->get_value() == 1);
    ++dfsIt;
    CHECK(dfsIt->get_value() == 2);
    ++dfsIt;
    CHECK(dfsIt->get_value() == 4);
    ++dfsIt;
    CHECK(dfsIt->get_value() == 5);
    ++dfsIt;
    CHECK(dfsIt->get_value() == 3);
    ++dfsIt;
    CHECK(dfsIt->get_value() == 6);
}

TEST_CASE("Testing Trees with complex numbers") {
    // Create nodes with integer values
    Node<Complex> node1(Complex(3.0, 5.0));
    Node<Complex> node2(Complex(4.0, 2.0));
    Node<Complex> node3(Complex(7.0, 5.0));
    Node<Complex> node4(Complex(1.0, 2.0));
    Node<Complex> node5(Complex(5.0, 5.0));
    Node<Complex> node6(Complex(1.0, 4.0));
    
    Tree<Complex> ComplexTree;
    ComplexTree.add_root(node1);

    // Add child nodes
    ComplexTree.add_sub_node(node1, node2);
    ComplexTree.add_sub_node(node1, node3);
    ComplexTree.add_sub_node(node2, node4);
    ComplexTree.add_sub_node(node4, node5);
    ComplexTree.add_sub_node(node4, node6);

    // Pre-order traversal check
    auto preOrderIt = ComplexTree.begin_pre_order();
    CHECK(preOrderIt->get_value() == Complex(3,5));
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == Complex(4,2));
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == Complex(1,2));
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == Complex(5,5));
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == Complex(1,4));
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == Complex(7,5));

    // Post-order traversal check
    auto postOrderIt = ComplexTree.begin_post_order();
    CHECK(postOrderIt->get_value() == Complex(5,5));
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == Complex(1,4));
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == Complex(1,2));
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == Complex(4,2));
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == Complex(7,5));
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == Complex(3,5));

    // In-order traversal check
    auto inOrderIt = ComplexTree.begin_in_order();
    CHECK(inOrderIt->get_value() == Complex(5,5));
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == Complex(1,2));
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == Complex(1,4));
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == Complex(4,2));
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == Complex(3,5));
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == Complex(7,5));

    // BFS traversal check
    auto bfsIt = ComplexTree.begin_bfs_scan();
    CHECK(bfsIt->get_value() == Complex(3,5));
    ++bfsIt;
    CHECK(bfsIt->get_value() == Complex(4,2));
    ++bfsIt;
    CHECK(bfsIt->get_value() == Complex(7,5));
    ++bfsIt;
    CHECK(bfsIt->get_value() == Complex(1,2));
    ++bfsIt;
    CHECK(bfsIt->get_value() == Complex(5,5));
    ++bfsIt;
    CHECK(bfsIt->get_value() == Complex(1,4));

    // DFS traversal check
    auto dfsIt = ComplexTree.begin_dfs_scan();
    CHECK(dfsIt->get_value() == Complex(3,5));
    ++dfsIt;
    CHECK(dfsIt->get_value() == Complex(4,2));
    ++dfsIt;
    CHECK(dfsIt->get_value() == Complex(1,2));
    ++dfsIt;
    CHECK(dfsIt->get_value() == Complex(5,5));
    ++dfsIt;
    CHECK(dfsIt->get_value() == Complex(1,4));
    ++dfsIt;
    CHECK(dfsIt->get_value() == Complex(7,5));
}

TEST_CASE("Testing 3-ary Trees") {
    // Create nodes with integer values
    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3);
    Node<int> node4(4);
    Node<int> node5(5);
    Node<int> node6(6);
    
    Tree<int,3> tree;
    tree.add_root(node1);

    // Add child nodes
    tree.add_sub_node(node1, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node1, node4);
    tree.add_sub_node(node2, node5);
    tree.add_sub_node(node2, node6);

     // Try adding more then maximum nodes
    Node<int> test_node(7);
    CHECK_THROWS(tree.add_sub_node(node1, node2));

    // Pre-order traversal check (DFS with 3-ary trees)
    auto preOrderIt = tree.begin_pre_order();
    CHECK(preOrderIt->get_value() == 1);
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == 2);
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == 5);
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == 6);
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == 3);
    ++preOrderIt;
    CHECK(preOrderIt->get_value() == 4);

    // Post-order traversal check (DFS with 3-ary trees)
    auto postOrderIt = tree.begin_post_order();
    CHECK(postOrderIt->get_value() == 1);
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == 2);
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == 5);
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == 6);
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == 3);
    ++postOrderIt;
    CHECK(postOrderIt->get_value() == 4);

    // In-order traversal check (DFS with 3-ary trees)
    auto inOrderIt = tree.begin_in_order();
    CHECK(inOrderIt->get_value() == 1);
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == 2);
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == 5);
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == 6);
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == 3);
    ++inOrderIt;
    CHECK(inOrderIt->get_value() == 4);

    // BFS traversal check
    auto bfsIt = tree.begin_bfs_scan();
    CHECK(bfsIt->get_value() == 1);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 2);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 3);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 4);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 5);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 6);

    // DFS traversal check
    auto dfsIt = tree.begin_dfs_scan();
    CHECK(dfsIt->get_value() == 1);
    ++dfsIt;
    CHECK(dfsIt->get_value() == 2);
    ++dfsIt;
    CHECK(dfsIt->get_value() == 5);
    ++dfsIt;
    CHECK(dfsIt->get_value() == 6);
    ++dfsIt;
    CHECK(dfsIt->get_value() == 3);
    ++dfsIt;
    CHECK(dfsIt->get_value() == 4);
}

TEST_CASE("Heap test") {
    Node<int> node1(10);
    Node<int> node2(9);
    Node<int> node3(8);
    Node<int> node4(7);
    Node<int> node5(6);
    Node<int> node6(5);
    Node<int> node7(4);
    Node<int> node8(3);
    Node<int> node9(2);
    Node<int> node10(1);
    
    Tree<int> tree;
    tree.add_root(node1);

    // Add child nodes
    tree.add_sub_node(node1, node2);
    tree.add_sub_node(node1, node3);
    tree.add_sub_node(node2, node4);
    tree.add_sub_node(node2, node5);
    tree.add_sub_node(node3, node6);
    tree.add_sub_node(node3, node7);
    tree.add_sub_node(node4, node8);
    tree.add_sub_node(node4, node9);
    tree.add_sub_node(node5, node10);

    
    // heap check
    auto heapIt = tree.my_heap();
    CHECK(heapIt->get_value() == 1);
    ++heapIt;
    CHECK(heapIt->get_value() == 2);
    ++heapIt;
    CHECK(heapIt->get_value() == 6);
    ++heapIt;
    CHECK(heapIt->get_value() == 3);
    ++heapIt;
    CHECK(heapIt->get_value() == 4);
    ++heapIt;
    CHECK(heapIt->get_value() == 10);
    ++heapIt;
    CHECK(heapIt->get_value() == 7);
    ++heapIt;
    CHECK(heapIt->get_value() == 8);
    ++heapIt;
    CHECK(heapIt->get_value() == 5);
    ++heapIt;
    CHECK(heapIt->get_value() == 9);

    // This has changed the tree structure ,i will prove by treversing but with bfs now :
    auto bfsIt = tree.begin_bfs_scan();
    CHECK(bfsIt->get_value() == 1);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 2);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 6);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 3);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 4);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 10);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 7);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 8);
    ++bfsIt;
    CHECK(bfsIt->get_value() == 5);
}