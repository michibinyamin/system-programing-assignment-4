// Email - michibinyamin@gmail.com
// Id - 208768978

#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Node.hpp"
#include <stdexcept>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <map>
#include "Complex.hpp"
#include <sstream>
#include <iomanip>


template <typename T, int k = 2>
class Tree {
private:
    Node<T>* root;

    static void pre_order(Node<T>* node, std::vector<Node<T>*>& nodes) {
        if (node == nullptr) return;
        nodes.push_back(node);
        for (auto child : node->get_children()) {
            pre_order(child, nodes);
        }
    }

    static void post_order(Node<T>* node, std::vector<Node<T>*>& nodes) {
        if (node == nullptr) return;
        for (auto child : node->get_children()) {
            post_order(child, nodes);
        }
        nodes.push_back(node);
    }

    static void in_order(Node<T>* node, std::vector<Node<T>*>& nodes) {
        if (node == nullptr) return;
        if (node->get_children().size() > 0) in_order(node->get_children()[0], nodes);
        nodes.push_back(node);
        for (size_t i = 1; i < node->get_children().size(); ++i) {
            in_order(node->get_children()[i], nodes);
        }
    }

    static void bfs(Node<T>* node, std::vector<Node<T>*>& nodes) {
        if (node == nullptr) return;
        std::queue<Node<T>*> q;
        q.push(node);
        while (!q.empty()) {
            Node<T>* current = q.front();
            q.pop();
            nodes.push_back(current);
            for (auto child : current->get_children()) {
                q.push(child);
            }
        }
    }

    static void dfs(Node<T>* node, std::vector<Node<T>*>& nodes) {
        if (node == nullptr) return;
        std::stack<Node<T>*> stack;
        stack.push(node);
        while (!stack.empty()) {
            Node<T>* current = stack.top();
            stack.pop();
            nodes.push_back(current);

            // Iterate over children in reverse order to maintain DFS order (optional)
            auto children = current->get_children();
            for (auto it = children.rbegin(); it != children.rend(); ++it) {
                stack.push(*it);
            }
        }
    }

    static void min_heapify(Node<T>* node) {
        if (node == nullptr) return;

        int smallest = node->get_value();  // Assuming `get_value()` returns the value that determines heap order
        int smallest_index = -1;           // set to minimum infinity

        // Check all children to find the smallest node
        for (int i = 0; i < node->children_amount(); ++i) {
            if (node->get_children()[i]->get_value() < smallest) {
                smallest = node->get_children()[i]->get_value();
                smallest_index = i;
            }
        }

        // If smallest child is smaller than parent, swap them
        if (smallest_index != -1 && smallest < node->get_value()) {
            // Swap values
            T temp = node->get_value();
            node->set_data(smallest);
            node->get_children()[smallest_index]->set_data(temp);

            // Recursively heapify the affected child
            min_heapify(node->get_children()[smallest_index]);
        }

    }
    bool is_binary(){
        if (k <= 2)
        {
            return true;
        }
        return false;
    }

    void delete_subtree(Node<T>* node) {
        if (node) {
            for (auto child : node->get_children()) {
                delete_subtree(child);
            }
            delete node;
        }
    }

public:
    Tree() : root(nullptr) {}
    // ~Tree() {
    //     if (root) {
    //         delete_subtree(root);
    //         root = nullptr;
    //     }
    // }

    void add_root(Node<T>& node) {
        root = &node;
    }

    void add_sub_node(Node<T>& parent, Node<T>& child) {
        if (parent.children_amount() < k) {
            parent.set_child(&child);
        } else {
            std::__throw_runtime_error("Node already has maximum number of children.\n");
        }
    }

    class PreOrderIterator {
    private:
        std::vector<Node<T>*> nodes;
        typename std::vector<Node<T>*>::iterator it;
    public:
        PreOrderIterator(Node<T>* root, bool binary) {
            if (root) {
                if (binary)
                {
                    Tree<T, k>::pre_order(root, nodes);
                }
                else
                {                
                    Tree<T, k>::dfs(root, nodes);
                }
                it = nodes.begin();
            }
        }

        Node<T>& operator*() {
            return **it;
        }

        Node<T>* operator->() {
            return *it;
        }

        PreOrderIterator& operator++() {
            ++it;
            nodes.pop_back();
            return *this;
        }

        bool operator!=(const PreOrderIterator& other) const {  // Compare the two lists
            if (nodes.size() != other.nodes.size())
            {
                return true;
            }
            for (size_t i = 0; i < nodes.size(); i++)
            {
                if (nodes[i] != other.nodes[i])
                {
                    return true;
                }
            }
            return false;
        }
    };

    class PostOrderIterator {
    private:
        std::vector<Node<T>*> nodes;
        typename std::vector<Node<T>*>::iterator it;
    public:
        PostOrderIterator(Node<T>* root, bool binary) {
            if (root) {
                if (binary)
                {
                    Tree<T, k>::post_order(root, nodes);
                }
                else
                {                
                    Tree<T, k>::dfs(root, nodes);
                }
                it = nodes.begin();
            }
        }

        Node<T>& operator*() {
            return **it;
        }

        Node<T>* operator->() {
            return *it;
        }

        PostOrderIterator& operator++() {
            ++it;
            nodes.pop_back();
            return *this;
        }

        bool operator!=(const PostOrderIterator& other) const {
            if (nodes.size() != other.nodes.size())
            {
                return true;
            }
            for (size_t i = 0; i < nodes.size(); i++)
            {
                if (nodes[i] != other.nodes[i])
                {
                    return true;
                }
            }
            return false;
        }
    };

    class InOrderIterator {
    private:
        std::vector<Node<T>*> nodes;
        typename std::vector<Node<T>*>::iterator it;
    public:
        InOrderIterator(Node<T>* root, bool binary) {
            if (root) {
                if (binary)
                {
                    Tree<T, k>::in_order(root, nodes);
                }
                else
                {                
                    Tree<T, k>::dfs(root, nodes);
                }
                it = nodes.begin();
            }
        }

        Node<T>& operator*() {
            return **it;
        }

        Node<T>* operator->() {
            return *it;
        }

        InOrderIterator& operator++() {
            ++it;
            nodes.pop_back();
            return *this;
        }

        bool operator!=(const InOrderIterator& other) const {
            if (nodes.size() != other.nodes.size())
            {
                return true;
            }
            for (size_t i = 0; i < nodes.size(); i++)
            {
                if (nodes[i] != other.nodes[i])
                {
                    return true;
                }
            }
            return false;
        }
    };

    class BFSIterator {
    private:
        std::vector<Node<T>*> nodes;
        typename std::vector<Node<T>*>::iterator it;
    public:
        BFSIterator(Node<T>* root) {
            if (root) {
                Tree<T, k>::bfs(root, nodes);
                it = nodes.begin();
            }
        }

        Node<T>& operator*() {
            return **it;
        }

        Node<T>* operator->() {
            return *it;
        }

        BFSIterator& operator++() {
            ++it;
            nodes.pop_back();
            return *this;
        }

        bool operator!=(const BFSIterator& other) const {
            if (nodes.size() != other.nodes.size())
            {
                return true;
            }
            for (size_t i = 0; i < nodes.size(); i++)
            {
                if (nodes[i] != other.nodes[i])
                {
                    return true;
                }
            }
            return false;
        }
    };

    class DFSIterator {
    private:
        std::vector<Node<T>*> nodes;
        typename std::vector<Node<T>*>::iterator it;
    public:
        DFSIterator(Node<T>* root) {
            if (root) {
                Tree<T, k>::dfs(root, nodes); // Use DFS traversal function
                it = nodes.begin();
            }
        }

        Node<T>& operator*() {
            return **it;
        }

        Node<T>* operator->() {
            return *it;
        }

        DFSIterator& operator++() {
            ++it;
            nodes.pop_back();
            return *this;
        }

        bool operator!=(const DFSIterator& other) const {
            if (nodes.size() != other.nodes.size())
                {
                    return true;
                }
                for (size_t i = 0; i < nodes.size(); i++)
                {
                    if (nodes[i] != other.nodes[i])
                    {
                        return true;
                    }
                }
            return false;
        }
    };

    class min_heap_iterator {
    private:
            std::vector<Node<T>*> nodes;
            typename std::vector<Node<T>*>::iterator it;

            struct nodes_comperator {
                bool operator()(Node<T>* a, Node<T>* b) {
                    return a->get_value() > b->get_value(); // Compare nodes
                }
            };

            void nodes_list(Node<T>* node) {
                if (node) {
                    nodes.push_back(node); // Collect the current node
                    for (auto child : node->get_children()) {
                        nodes_list(child); // Recursively collect children nodes
                    }
                }
            }
    public:
            min_heap_iterator(Node<T>* root){
                if (root) {
                    nodes_list(root);      // Collect all nodes for heap
                    std::make_heap(nodes.begin(), nodes.end(), nodes_comperator()); // Create heap
                    it = nodes.begin();
                }
            }
            std::vector<Node<T>*> get_list(){
                return nodes;
            }

            Node<T>& operator*() {
                return **it;
            }

            Node<T>* operator->() {
                return *it;
            }

            min_heap_iterator& operator++() {
                ++it;
                nodes.pop_back();
                return *this;
            }

            bool operator!=(const min_heap_iterator& other) const {
                if (nodes.size() != other.nodes.size())
                {
                    return true;
                }
                for (size_t i = 0; i < nodes.size(); i++)
                {
                    if (nodes[i] != other.nodes[i])
                    {
                        return true;
                    }
                }
                return false;
            }
        };




    PreOrderIterator begin_pre_order() {
        if (is_binary())
        {
            return PreOrderIterator(root, true);
        }
        return PreOrderIterator(root, false);
        
    }

    PreOrderIterator end_pre_order() {
        if (is_binary())
        {
            return PreOrderIterator(nullptr, true);
        }
        return PreOrderIterator(nullptr, false);
    }

    PostOrderIterator begin_post_order() {
        if (is_binary())
        {
            return PostOrderIterator(root, true);
        }
        return PostOrderIterator(root, false);
    }

    PostOrderIterator end_post_order() {
        if (is_binary())
        {
            return PostOrderIterator(nullptr, true);
        }
        return PostOrderIterator(nullptr, false);
    }

    InOrderIterator begin_in_order() {
        if (is_binary())
        {
            return InOrderIterator(root, true);
        }
        return InOrderIterator(root, false);
    }

    InOrderIterator end_in_order() {
        if (is_binary())
        {
            return InOrderIterator(nullptr, true);
        }
        return InOrderIterator(nullptr, false);
    }

    BFSIterator begin_bfs_scan() {
        return BFSIterator(root);
    }

    BFSIterator end_bfs_scan() {
        return BFSIterator(nullptr);
    }
    DFSIterator begin_dfs_scan() {
        return DFSIterator(root);
    }

    DFSIterator end_dfs_scan() {
        return DFSIterator(nullptr);
    }

    min_heap_iterator my_heap() {
        auto node = min_heap_iterator(root);
        std::vector<Node<T>*> list = node.get_list();
        add_root(*list.at(0));

        for (size_t i = 0; i < list.size(); i++)
        {
            list.at(i)->clear_children();
        }
        for (size_t i = 0; i < list.size()-i-2; i++)
        {
            list.at(i)->set_child(list.at(i+i+1));
            list.at(i)->set_child(list.at(i+i+2));
        }
    
        return node;
    }

    min_heap_iterator end_myheap() {
        return min_heap_iterator(nullptr);
    }


    BFSIterator begin() {
        return begin_bfs_scan();
    }

    BFSIterator end() {
        return end_bfs_scan();
    }

    friend std::ostream& operator<<(std::ostream& os, const Tree& tree) {
        if (!tree.root)
            return os;
    
        sf::RenderWindow window(sf::VideoMode(1000, 800), "Tree Visulising");
        sf::Font font;
        if (!font.loadFromFile("font.ttf")) {
            std::cerr << "Error loading font\n";
            return os;
        }

        const float node_radius = 25.f;
        const float vertical_spacing = 80.f;
        const float initial_horizontal_spacing = 200.f;

        std::map<Node<T>*, sf::Vector2f> positions;

        std::function<void(Node<T>*, float, float, float)> position_nodes = [&](Node<T>* node, float x, float y, float horizontal_spacing) {
            if (!node)
                return;

            positions[node] = sf::Vector2f(x, y);

            float child_x_offset = x - (node->get_children().size() - 1) * horizontal_spacing / 2.f;

            for (size_t i = 0; i < node->get_children().size(); ++i) {
                Node<T>* child = node->get_children()[i];
                if (child) {
                    position_nodes(child, child_x_offset + i * horizontal_spacing, y + vertical_spacing, horizontal_spacing / 2.f);
                }
            }
        };

        position_nodes(tree.root, window.getSize().x / 2.f, node_radius + 50.f, initial_horizontal_spacing);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);

            for (const auto& pair : positions) {
                Node<T>* node = pair.first;
                sf::Vector2f position = pair.second;

                for (Node<T>* child : node->get_children()) {
                    if (child) {
                        sf::Vector2f child_position = positions[child];

                        sf::Vertex line[] = {
                            sf::Vertex(position, sf::Color::Black),
                            sf::Vertex(child_position, sf::Color::Black)
                        };
                        window.draw(line, 2, sf::Lines);
                    }
                }

                sf::CircleShape circle(node_radius);
                circle.setFillColor(sf::Color::Red);
                circle.setPosition(position - sf::Vector2f(node_radius, node_radius));
                window.draw(circle);
                
            
                sf::Text text;
                text.setFont(font);
                text.setCharacterSize(16);
                text.setFillColor(sf::Color::Black);

                std::ostringstream oss;
                oss << node->get_value();
                text.setString(oss.str());

                sf::FloatRect text_bounds = text.getLocalBounds();
                text.setOrigin(text_bounds.left + text_bounds.width / 2.0f, text_bounds.top + text_bounds.height / 2.0f);
                text.setPosition(position);
                window.draw(text);
            }

            window.display();
        }
        return os;
    }
};

#endif