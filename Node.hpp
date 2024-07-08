// Email - michibinyamin@gmail.com
// Id - 208768978

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>

using namespace std;

// Geters and seters

template <typename T>
class Node {
private:
    T data;
    vector<Node<T>*> children;
public:
    Node(const T& value) : data(value){}
    ~Node(){}
    const T get_value() const{return data;}
    void set_data(const T& value) {data = value;}
    void set_child(Node<T>* child) {children.push_back(child);}
    //void set_children(vector<Node<T>*>& new_children) {children = new_children;}
    const vector<Node<T>*>& get_children() const {return children;} // returns the children of the current node
    int children_amount() const{return children.size();}
    void clear_children(){children.clear();} // Clear the list of children
};

#endif // NODE_HPP

