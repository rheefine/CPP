#ifndef NODE_HPP
#define NODE_HPP

#include <cstddef>

class Node {
private:
	int min;
	int max;
	Node* min_node;
	Node* max_node;

public:
	Node();
	Node(int val);
	Node(Node* node1, Node* node2);
	Node(const Node& other);
	~Node();
	Node& operator=(const Node& other);

	// getter/setter
	int getMin() const;
	int getMax() const;
	Node* getMinNode() const;
	Node* getMaxNode() const;

	bool operator>(const Node& other) const;
	bool operator<(const Node& other) const;
	bool operator>=(const Node& other) const;
	bool operator<=(const Node& other) const;
};

#endif
