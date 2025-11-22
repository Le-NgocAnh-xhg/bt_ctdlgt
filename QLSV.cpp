#include <iostream>
#include <string>
using namespace std;

struct SinhVien{
    string name;
    string mssv;
    int namSinh;
    float gpa;
    SinhVien* next;
};

void init(SinhVien*& head){
    head = NULL;
}

void addBack (SinhVien*& head, string name, string mssv, int namSinh, float gpa){
    SinhVien* Sv = new SinhVien{name, mssv, namSinh, gpa, NULL};
    if(head == NULL){
        head = Sv;
        return;
    }
    SinhVien* p = head;
    while(p->next != NULL) p=p->next;
    p->next = Sv;
}

void inDS(SinhVien* head){
    while(head != NULL){
        cout << head->name<<" - "<<head->mssv 
             << " - " << head->namSinh <<" - "<<head->gpa << endl;
        head=head->next;
    }
}

int chieudaiDS(SinhVien* head){
    int dem = 0;
    while (head != NULL){
        dem ++;
        head = head->next;
    }
    return dem;
}

int Gpa (SinhVien* head){
    int c = 0;
    while (head != NULL){
        if(head->gpa > 3.2) c++;
        head=head->next;
    }
    return c;
}

void sxGPA(SinhVien*& head){
    for(SinhVien* i = head; i != NULL; i = i->next) {
        SinhVien* min = i;

        for (SinhVien* j = i->next; j != NULL; j = j->next) {
            if (j->gpa < min->gpa)
                min = j;
        }
        swap(i->name, min->name);
        swap(i->mssv, min->mssv);
        swap(i->namSinh, min->namSinh);
        swap(i->gpa, min->gpa);
    }
}

void chensv(SinhVien*& head, string name, string mssv, int namSinh, float gpa) {
    SinhVien* Sv = new SinhVien{name, mssv, namSinh, gpa, NULL};

    if (head == NULL || gpa < head->gpa) {
        Sv->next = head;
        head = Sv;
        return;
    }

    SinhVien* p = head;
    while (p->next != NULL && p->next->gpa < gpa)
        p = p->next;

    Sv->next = p->next;
    p->next = Sv;
}

int main(){
    SinhVien* head;
    init(head);
    
    int n;
    cout << "So luong sinh vien: ";
    cin >> n;
    
    string name;
    string mssv;
    int namSinh;
    float gpa;
    
    cout <<"\nNhap danh sach sinh vien:\n";
    for(int i=0;i<n;i++){
        cin.ignore();
        cout<< "Ho ten: ";
        getline(cin, name);

        cout<< "MSSV: ";
        cin >> mssv;

        cout << "Nam sinh: ";
        cin >> namSinh;

        cout << "GPA: ";
        cin >> gpa;

        addBack (head, name, mssv, namSinh, gpa);
    }
    
    cout << "\nDanh sach:\n";
    inDS(head);
    
    cout << "\nChieu dai ds la: " << chieudaiDS(head);
    cout << "\nSo sv co gpa > 3.2: "<< Gpa(head);
    
    cout << "\n\nSap xep theo GPA tang dan:\n";
    sxGPA(head);
    inDS(head);

    cout << "\nChen sinh vien GPA = 2.4 vao dung vi tri:\n";
    chensv(head, "new sv", "000", 2006, 2.4);
    inDS(head);
    
    return 0;
}

