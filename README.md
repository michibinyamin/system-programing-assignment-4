// Name - Michael Binyamin
// Email - michibinyamin@gmail.com
// Id - 208768978

**Files** : 
- Node
- Tree
- Complex
- main
- test
- makefile

**Node** :
variables :
- data - a T type containing the data
- children - a vector list containing the current nodes children

**methods** :
- get_value - returns the value
- set_data - sets the value
- set_child - sets a child to the current node
- get_children - returns the list of children
- children_amount - returns the amount of children
- clear_children - clears all of the children nodes

**Tree** :
variables :
- root - a node which is the root of the tree
methods : 
- add_root - adds the given root
- add_sub_node - adds the given node to the given father node's children
- is_binary - returns true if this tree is binary
- Begginings of all the iterators - they return the given iterator's beggining
- Endings of iterators - they return the given iterator's end
- operator<< - overload for outputting a Tree to ostream, it visualizes the tree structure using SFML graphics library
- static methods for editing lists according to a given order : pre_order, post_order, in_order, bfs, dfs, min_heapify (these are used in the nested classes)

**Nested classes inside Tree :** 
they all have a list of nodes and an iterator
and they all have operators for -  * -> ++ !=
- PreOrderIterator - if tree is binary then sets the list of nodes to pre_order else to dfs
- PostOrderIterator - if tree is binary then sets the list of nodes to pre_order else to dfs
- InOrderIterator - if tree is binary then sets the list of nodes to pre_order else to dfs
- BFSIterator - sets list with bfs
- DFSIterator - sets list with dfs
- min_heap_iterator - changes the tree to be a min_heap and returns a bfs iterator of it

**Complex :**
variables:
- real - the real part
- imagine - the imaginary part
methods:
- getReal
- getImag
- setReal
- setImag
- magnitude
- operator<
- operator==
- operator<<

**Main :**
- Runs binary tree with doubles
- Runs binary tree with complex numbers
- Runs 3-ary tree with doubles

**Test :**
- Tests binary tree with integers
- Tests binary tree with complex numbers
- Tests 3-ary tree with doubles
- Tests all of the diffarent itaraters
- Tests specificly the heap, checks if it changes the tree 

**makefile :**
- make tree - makes the program to run
- make test - makes the test
- ./tree
- ./test