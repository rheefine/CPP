#include "Node.hpp"

Node::Node() : min(0), max(0), min_node(NULL), max_node(NULL) {}

Node::Node(int val) : min(0), max(val), min_node(NULL), max_node(NULL) {}

Node::Node(Node* node1, Node* node2) {
	if (node1->getMax() < node2->getMax()) {
		min = node1->getMax();
		max = node2->getMax();
		min_node = node1;
		max_node = node2;
	} else {
		min = node2->getMax();
		max = node1->getMax();
		min_node = node2;
		max_node = node1;
	}
}

Node::Node(const Node& other)
	: min(other.min), max(other.max),
	min_node(other.min_node), max_node(other.max_node) {}

Node::~Node() {}

Node& Node::operator=(const Node& other) {
	if (this != &other) {
		min = other.min;
		max = other.max;
		min_node = other.min_node;
		max_node = other.max_node;
	}
	return *this;
}

bool Node::operator>(const Node& other) const {
	return max > other.max;
}

bool Node::operator<(const Node& other) const {
	return max < other.max;
}

bool Node::operator>=(const Node& other) const {
	return max >= other.max;
}

bool Node::operator<=(const Node& other) const {
	return max <= other.max;
}

int Node::getMin() const { return min; }
int Node::getMax() const { return max; }
Node* Node::getMinNode() const { return min_node; }
Node* Node::getMaxNode() const { return max_node; }
