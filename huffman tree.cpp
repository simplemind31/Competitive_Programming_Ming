// C++ code for the above approach:
#include <bits/stdc++.h>
using namespace std;

// Class to represent huffman tree 
class Node {
public:
	int data;
	Node *left, *right;
	Node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
};

// Custom min heap for Node class.
class Compare {
public:
	bool operator() (Node* a, Node* b) {
		return a->data > b->data;
	}
};

// Function to traverse tree in preorder 
// manner and push the huffman representation 
// of each character.
void preOrder(Node* root, vector<string> &ans, string curr) {
	if (root == nullptr) return;

    // Leaf node represents a character.
	if (root->left == nullptr && root->right==nullptr) {
		ans.push_back(curr);
		return;
	}

	preOrder(root->left, ans, curr + '0');
	preOrder(root->right, ans, curr + '1');
}

vector<string> huffmanCodes(string s,vector<int> freq) {
	
	int n = s.length();
    
    // Min heap for node class.
	priority_queue<Node*, vector<Node*>, Compare> pq;
	for (int i=0; i<n; i++) {
		Node* tmp = new Node(freq[i]);
		pq.push(tmp);
	}

    // Construct huffman tree.
	while (pq.size()>=2) {
	    
	    // Left node 
		Node* l = pq.top();
		pq.pop();
        
        // Right node 
		Node* r = pq.top();
		pq.pop();

		Node* newNode = new Node(l->data + r->data);
		newNode->left = l;
		newNode->right = r;

		pq.push(newNode);
	}

	Node* root = pq.top();
	vector<string> ans;
	preOrder(root, ans, "");
	return ans;
}

int main() {
    string original="hello, how are you?";
    string s="";
    vector<int> freq;
    vector<int> cont(300);
    for(int i=0;i<original.size();i++){
        cont[original[i]]++;
    }
    vector<pair<int,int>> ordenado;
    for(int i=0;i<300;i++){
        if(cont[i]){
            ordenado.push_back({cont[i],i});
        }
    }
    sort(ordenado.begin(),ordenado.end());
    for(int i=0;i<ordenado.size();i++){
        s.push_back(char(ordenado[i].second));
        freq.push_back(ordenado[i].first);
    }
	vector<string> ans = huffmanCodes(s, freq);
    vector<string> finall;
	for(int i=0;i<original.size();i++){
        for(int j=0;j<s.size();j++){
            if(original[i]==s[j]){
                finall.push_back(ans[j]);
                break;
            }
        }
    }
    for(auto u:finall){
        cout << u << ' ';
    }
	return 0;
}