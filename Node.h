#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T> 
class Node {
    public:
        // miembros públicos
		T data;
		Node<T>* next;
		Node(T data, Node<T>*next=nullptr);
		friend std::ostream&operator<<(std::ostream &out, const Node<T> &node);
};

#endif
