class Node {
	private:
		Node *leftChild, *rightChild, *parent;
		int *state;
	public:
		Node(int start, int finale, int pivot) {
			state = new int[3];
			state[0] = start;
			state[1] = finale;
			state[2] = pivot;
			parent = leftChild = rightChild = nullptr;
		}

		void setLeftChild(Node& n) { leftChild = &n; n.setParent(*this); }
		void setRightChild(Node& n) { rightChild = &n; n.setParent(*this); }
		void setParent(Node& n) { parent = &n; }	
		Node *getParent() const { return parent; }
		int *getState() const { return state; }
		bool hasLeftChild() { return leftChild != nullptr; }
		bool hasRightChild() { return rightChild != nullptr; }

};
