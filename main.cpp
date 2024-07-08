// Email - michibinyamin@gmail.com
// Id - 208768978

#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"

using namespace std;

int main()
{
    Node<double> root_node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */
    cout << "normal numbers tree: \n";
    cout << "pre-order list: \n";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << "\n";
    cout << "post-order list: \n";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << "\n";
    cout << "in-order list: \n";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << "\n";
    cout << "bfs list: \n";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    
    cout << "\n";
    cout << "another bfs list: \n";
    for (auto node : tree)
    {
        cout << node.get_value() << endl;
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "\n";
    cout << "dfs list: \n";
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } // same as BFS: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << "\n";

    cout << "Testing heap iterator\n";
    // The following chenges the tree structure
    for (auto node = tree.my_heap(); node != tree.end_myheap(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 
    cout << "\n";

    cout << "bfs after heap\n";
    for (auto node : tree)
    {
        cout << node.get_value() << endl;
    }
    cout << "\n";
    cout << tree;


    // Clear the nodes
    root_node.clear_children();
    n1.clear_children();
    n2.clear_children();
    n3.clear_children();
    n4.clear_children();
    n5.clear_children();

    // Complex numbers : 
    Node<Complex> complex_root_node(Complex(1.0, 1.0));
    Tree<Complex> complex_tree; // Binary tree that contains Complex numbers.
    complex_tree.add_root(complex_root_node);
    Node<Complex> complex_n1(Complex(3.0, 5.0));
    Node<Complex> complex_n2(Complex(4.0, 2.0));
    Node<Complex> complex_n3(Complex(7.0, 5.0));
    Node<Complex> complex_n4(Complex(1.0, 2.0));
    Node<Complex> complex_n5(Complex(5.0, 5.0));

    complex_tree.add_sub_node(complex_root_node, complex_n1);
    complex_tree.add_sub_node(complex_root_node, complex_n2);
    complex_tree.add_sub_node(complex_n1, complex_n3);
    complex_tree.add_sub_node(complex_n1, complex_n4);
    complex_tree.add_sub_node(complex_n4, complex_n5);

   
    // The complex_tree should look like:
    /**
     *    root = 1+1i
     *     /       \
     *   3+5i     4+2i
     *   /  \      
     * 7+5i 1+2i  
     *       /
     *     5+5i
     */
    cout << "Complex numbers tree: \n";
    cout << "pre-order list: \n";
    for (auto node = complex_tree.begin_pre_order(); node != complex_tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 1+1i, 3+5i, 7+5i, 1+2i, 5+5i, 4+2i
    cout << "\n";
    cout << "post-order list: \n";
    for (auto node = complex_tree.begin_post_order(); node != complex_tree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    }
    cout << "\n";
    cout << "in-order list: \n";
    for (auto node = complex_tree.begin_in_order(); node != complex_tree.end_in_order(); ++node)
    {
        cout << node->get_value() << endl;
    } 
    cout << "\n";
    cout << "bfs list: \n";
    for (auto node = complex_tree.begin_bfs_scan(); node != complex_tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    }
    cout << "\n";
    cout << "another bfs list: \n";
    for (auto node : complex_tree)
    {
        cout << node.get_value() << endl;
    } 
    cout << "\n";
    cout << complex_tree;


    // Clear the nodes
    root_node.clear_children();
    n1.clear_children();
    n2.clear_children();
    n3.clear_children();
    n4.clear_children();
    n5.clear_children();

    Tree<double,3> three_ary_tree; // 3-ary tree.
    three_ary_tree.add_root(root_node);
    three_ary_tree.add_sub_node(root_node, n1);
    three_ary_tree.add_sub_node(root_node, n2);
    three_ary_tree.add_sub_node(root_node, n3);
    three_ary_tree.add_sub_node(n1, n4);
    three_ary_tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    cout << three_ary_tree;
    cout << "3-ary tree numbers: \n";
    cout << "trying in-order but should print dfs: \n";
    for (auto node = three_ary_tree.begin_pre_order(); node != three_ary_tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints dfs: 1.1  1.2  1.5  1.3  1.6  1.4
    cout << "\n";
    cout << "\n";
    cout << "bfs list: \n";
    for (auto node : three_ary_tree)
    {
        cout << node.get_value() << endl;
    } // prints bfs: 1.1  1.2  1.3  1.4  1.5  1.6
    cout << "\n";
    
}
