// bai tap tuan 14
#include<iostream>
#include<string>
using namespace std;

typedef struct Node {
	string index;    
	Node* left;
	Node* right;
	Node (string i){
	index = i;
	left = NULL;
	right = NULL;
}
}Node;

typedef Node* Tree;

void init(Tree& T){   // ham khoi tao cay
	T=NULL;
}  

bool is_empty(Tree T){
	return T == NULL;
}

void add_root(Tree& T, string i){
	if(is_empty(T)) T = new Node(i);
}

void add_left(Tree T, string i){
	if(T != NULL && T->left == NULL){
		T -> left = new Node(i);
	}
}

void add_right(Tree T, string i){
	if(T != NULL && T->right == NULL){
		T -> right = new Node (i);
	}
}

void Visit(Tree T){
	if(T!=NULL) cout << T->index << "  ";
}

void duyet_truoc(Tree T){
	if(T == NULL) return;
	Visit(T);
	duyet_truoc(T->left);
	duyet_truoc(T->right);
}

void duyet_giua(Tree T){
	if(T==NULL) return;
	duyet_giua(T->left);
	Visit(T);
	duyet_giua(T->right);
}

void duyet_sau(Tree T){
	if(T==NULL) return;
	duyet_sau(T->left);
	duyet_sau(T->right);
	Visit(T);
}

int main(){
	Tree T;
	init(T);
	
	add_root(T,"A");
	add_left(T,"A.1");
	add_right(T,"A.2");
	add_left(T->left,"A.1.1");
	add_right(T->left,"A.1.2");
	add_left(T->right,"A.2.1");
	add_right(T->right,"A.2.2");
	
	cout <<"duyet truoc: ";
	duyet_truoc(T);
	cout << endl;
	
	cout<<"duyet giua: ";
	duyet_giua(T);
	cout << endl;
	
	cout << "duyet sau: ";
	duyet_sau(T);
	
	return 0;
}

