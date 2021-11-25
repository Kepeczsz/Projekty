// zrobione na podstawie ksiazki wporowadzenie do algorytmow 2 Thomas H. Cormen
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
template<typename T>
class RBtree
{
private:
	struct Node
	{
		T data;
		Node* parent;
		Node* left;
		Node* right;
		int color;
		~Node()
		{
			delete data;
			delete left;
			delete right;
			delete color;
			delete parent;
		}
	};
	Node* root;
	Node* TNIL;

	void leftRotate(Node* x)
	{
		Node* y = x->right; // inicjalizacja y;
		x->right = y->left; // zamien lewe poddrzewo y na prawe poddrzewo x
		if (y->left != TNIL) // jezeli lewe poddrzewo jest tylko wskaznikiem na nic, to 
		{
			y->left->parent = x; // uczyn 
		}
		y->parent = x->parent; // ojcem y teraz jest ojciec x
		if (x->parent == nullptr) // tutaj zmienilem
		{
			this->root = y;
		}
		else if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
		y->left = x; // przylaczenie x jako lewego syna y
		x->parent = y;
	}
	void rightRotate(Node* x)
	{
		Node* y = x->left; // symetrycznie do lewej rotacji
		x->left = y->right;
		if (y->right != TNIL)
		{
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr)
		{
			this->root = y;
		}
		else if (x == x->parent->right)
		{
			x->parent->right = y;
		}
		else
		{
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}
	void fixInsert(Node* k) {
		Node* u;
		while (k->parent->color == 1) {
			if (k->parent == k->parent->parent->right) {
				u = k->parent->parent->left;
				if (u->color == 1) {

					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->left) {

						k = k->parent;
						rightRotate(k);
					}

					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			}
			else {
				u = k->parent->parent->right;

				if (u->color == 1) {

					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->right) {

						k = k->parent;
						leftRotate(k);
					}

					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root) {
				break;
			}
		}
		root->color = 0;
	}
	void printHelper(Node* root, string indent, bool last) {
		// print the tree structure on the screen
		if (root != TNIL) {
			cout << indent;
			if (last) {
				cout << "R----";
				indent += "     ";
			}
			else {
				cout << "L----";
				indent += "|    ";
			}

			string sColor = root->color ? "RED" : "BLACK";
			cout << root->data << "(" << sColor << ")" << endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}

	}
	void inOrderHelper(Node* node) {
		if (node != TNIL) {
			inOrderHelper(node->left);
			cout << node->data << " ";
			inOrderHelper(node->right);
		}
	}
	void preOrderHelper(Node* node) {
		if (node == TNIL)
			return;
		cout << node->data << " ";
		preOrderHelper(node->left);
		preOrderHelper(node->right);

	}
	int max(int x, int y) {
		if (x >= y) {
			return x;
		}
		else {
			return y;
		}
	}
	int Height(Node* start) {

		if (start == NULL)
		{
			return -1;
		}
		else
			return max(Height(start->left), Height(start->right)) + 1;
	}

public:

	RBtree()
	{
		TNIL = new Node;
		TNIL->color = 0;
		TNIL->left = nullptr;
		TNIL->right = nullptr;
		root = TNIL;
	}
	Node* GetRoot() {
		return root;
	}
	void inorder() {
		inOrderHelper(this->root);
	}
	void preOrder() {
		preOrderHelper(this->root);
	}
	void insert(T data)
	{
		Node* node = new Node;
		node->parent = nullptr;
		node->data = data;
		node->left = TNIL;
		node->right = TNIL;
		node->color = 1;

		Node* y = nullptr;
		Node* x = this->root;
		while (x != TNIL)
		{
			y = x;
			if (node->data < x->data) // wypadek w ktorym wartosc naszego nowo utworzonego noda jest mniejsza od roota
			{
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}
		// przypadek w ktorym y jest rodzicem x
		node->parent = y;
		if (y == nullptr)
		{
			root = node;
		}
		else if (node->data < y->data)
		{
			y->left = node;
		}
		else
		{
			y->right = node;
		}
		// if new node is a root node, simply return
		if (node->parent == nullptr) {
			node->color = 0;
			return;
		}

		// if the grandparent is null, simply return
		if (node->parent->parent == nullptr) {
			return;
		}

		// Fix the tree
		fixInsert(node);
	}
	void Print() {
		if (root) {
			printHelper(this->root, "", true);
		}
	}
	Node* searchElementHelper(T data) {
		auto start = GetRoot();
		if (start == nullptr) {
			return nullptr;
		}
		while (start) {
			if (data == start->data) {
				cout << "found " << start;
				return start;
			}
			else if (data < start->data) {
				start = start->left;
			}
			else {
				start = start->right;
			}
		}
		return nullptr;
	}
	int returnHeight1()
	{
		return Height(root);
	}
};


struct some_struct
{
	int val1;
	string val2;
	some_struct(int val1, string val2) {
		this->val1 = val1;
		this->val2 = val2;
	}
	int getVal1() {
		return val1;
	}
	string getVal2() {
		return val2;
	}
};
std::ostream& operator<<(std::ostream& out, const some_struct& obj)
{
	out << obj.val1 << ", " << obj.val2;
	return out;
}

bool operator<=(const some_struct& obj1, const some_struct& obj2)
{
	return obj1.val1 <= obj2.val1 && obj1.val2 <= obj2.val2;
}

bool operator>=(const some_struct& obj1, const some_struct& obj2)
{
	return obj1.val1 >= obj2.val1 && obj1.val2 >= obj2.val2;
}

bool operator==(const some_struct& obj1, const some_struct& obj2)
{
	return obj1.val1 == obj2.val1 && obj1.val2 == obj2.val2;
}


int main()
{
	//   
	//   RBtree<some_struct*>* rbt = new RBtree<some_struct*>();
	//   rbt->insert(new some_struct(123,"1gf"));
	//   rbt->insert(new some_struct(15, "1hf"));
	//   rbt->insert(new some_struct(51, "1qwe"));
	//   rbt->insert(new some_struct(71, "1ggr"));
	//   rbt->insert(new some_struct(61, "6ds"));
	//   rbt->insert(new some_struct(26, "fsa"));
	//   rbt->insert(new some_struct(15, "5"));
	  clock_t time_req;
	///*   RBtree<int>* rbt = new RBtree<int>;*/
	   time_req = clock();
	//  
	//  

	//   rbt->Print();
	//   cout << "\nInorder:\n";
	//   rbt->inorder();
	//   cout << "\nPreorder\n";
	//   rbt->preOrder();
	//   rbt->searchElementHelper(new some_struct(123,"1gf"));
	//   cout<< "\nHeight of RBT: " << rbt->returnHeight1();
	
	
	//   cout << "rbt has been deleted"; delete rbt;

	RBtree<int> rbt;
	for (int i = 0; i < 10000000; i++) {
		
		rbt.insert(i);
	}
	   time_req = clock() - time_req;
	      

	/*cout << "InOrder: "; rbt.inorder();
	cout << "preOrder";  rbt.preOrder();*/
	/*cout << "FindNode" << rbt.searchElementHelper(5);*/
	cout << "Height: " << rbt.returnHeight1();
	cout << "\nEverything took:  " << (float)time_req / CLOCKS_PER_SEC << " seconds" << endl;
	return 0;

}