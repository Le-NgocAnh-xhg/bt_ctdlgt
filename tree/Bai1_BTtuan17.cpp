#include<iostream>
#include<string>
using namespace std;

struct Node{
	int index;   // so thu tu muc
	string name;  // ten muc
	int pages;    // so trang
	
	Node* first_child;  // con dau tien
	Node* next_sib;  // anh em ke tiep (cay tong quat)
	
	Node(int i, string n, int p){   // ham tao
		index = i;
		name = n;
		pages = p;
		
		first_child = NULL;
		next_sib = NULL;
	}
};
// Xac dinh so chuong cuon sach
int Count(Node* root){
	int count = 0;
	Node* p = root -> first_child;
	while(p!=NULL){
		count ++;
		p = p->next_sib;
	}
	return count;
}

// Tim chuong dai nhat
int Sum(Node* node){
	if(!node) return 0;
	
	int sum = node->pages;
	Node* child = node->first_child;
	while(child){
		sum += Sum(child);
		child = child->next_sib;
	}
	return sum;
}

Node* Longest(Node* root){
	Node* longest = NULL;
	int max_page = 0;
	Node* chapter = root->first_child;
	while(chapter){
		int pages = Sum(chapter);
		if(pages > max_page){
			max_page = pages;
			longest = chapter;
		}
		chapter = chapter->next_sib;
	}
	return longest;
}

int main(){
	Node* book = new Node(0,"book", 0);
	Node* chap1 = new Node(1,"chapter 1", 10);
	Node* chap2 = new Node(2, "chapter 2", 15);
	
	Node* sec11 = new Node(11,"secton 1.1", 6);
	Node* sec12 = new Node(12,"section 1.2", 9);
	
	book->first_child = chap1;
	chap1->next_sib = chap2;
	
	chap1->first_child = sec11;
	sec11->next_sib = sec12;
	
	cout<<"So chuong: " << Count(book) << endl;
	Node* longest = Longest(book);
	cout<<"Chuong dai nhat: " << longest->name << endl;
}


















