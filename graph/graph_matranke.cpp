#include<iostream>
using namespace std;

#define n 11
int mt[100][100];

void Matran(){
	int i, j;
	for(i=1;i<=n;i++){
		for(j=1; j<=n; j++){
			mt[i][j]=0;
		}
	}
}

void Add_mt(int x, int y){
	mt[x][y] = 1;
	mt[y][x] = 1;
}

void display(){
	int i, j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cout << mt[i][j] << " ";
		}
		cout << endl;
	}	
}

int main(){
	Matran();
	
	Add_mt(1,2);
	Add_mt(2,11);
	Add_mt(11,10);
	Add_mt(1,10);
	Add_mt(1,9);
	Add_mt(1,8);
	Add_mt(1,7);
	Add_mt(1,6);
	Add_mt(6,5);
	Add_mt(5,4);
	Add_mt(6,4);
	Add_mt(4,3);
	Add_mt(2,3);
	
	display();
}
