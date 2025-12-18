#include<iostream>
#include<string>
using namespace std;

#define max 100

typedef struct {
	string data[max]; //luu chi muc
	int n; // so node
}Tree;

// khoi tao
void khoi_tao(Tree &T){
	T.n = 0;
}

// kiem tra cay rong
int is_empty(Tree T){
	return T.n == 0;
}

// xac dinh goc cay
int Root(Tree T){
	if(! is_empty(T)){
		return 0;
	}
	else return -1;
}

// con trai cua nut
int Left(int i, Tree T){
	int left = 2*i +1;
	if(left < T.n) return left;
	return -1;
}

// con phai
int Right(int i, Tree T){
	int right = 2*i +2;
	if(right < T.n) return right;
	return -1;
}

// them node
void add_root(Tree &T, string index){
	if(is_empty(T)){
		T.data[0] = index;
		T.n = 1;
	}
}

void add_left(Tree &T, int p, string index){
	int left = 2*p+1;
	if(left < max){
		T.data[left] = index;
		if(left >= T.n) T.n=left+1;
	}
}

void add_right(Tree &T, int p, string index){
	int right = 2*p +2;
	if(right < max){
		T.data[right] = index;
		if(right >= T.n) T.n=right+1;
	}
}

// phep duyet
void duyet_truoc(Tree T, int i){
	if(i==-1 || i>=T.n) return;
	cout << T.data[i] << "  ";
	duyet_truoc(T,Left(i,T));
	duyet_truoc(T, Right(i,T));
}

void duyet_giua(Tree T, int i){
	if (i == -1 || i >= T.n) return;
    duyet_giua(T, Left(i, T));
    cout << T.data[i] << "  ";
    duyet_giua(T, Right(i, T));
}

void duyet_sau(Tree T, int i){
	if (i == -1 || i >= T.n) return;
    duyet_sau(T, Left(i, T));
    duyet_sau(T, Right(i, T));
    cout << T.data[i] << "  ";
}

int main(){
	Tree T;
	khoi_tao(T);
	
	add_root(T,"A");
	add_left(T,0,"A.1");
	add_right(T, 0, "A.2");
	add_left(T,1,"A.1.1");
	add_right(T,1,"A.1.2");
	add_left(T,2,"A.2.1");
	add_right(T,2,"A.2.2");
	
	cout << "duyet truoc: ";
	duyet_truoc(T, Root(T));
	cout << endl;
	
	cout <<"duyet giua: ";
	duyet_giua(T, Root(T));
	cout << endl;
	
	cout <<"duyet sau: ";
	duyet_sau(T,Root(T));
	cout << endl;
}
