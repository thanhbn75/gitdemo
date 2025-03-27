#include<iostream>
#include<string>

using namespace std;

struct HocVien
{
	int maHocVien;
	string tenHocVien;
	string Lop;
	string ChuyenNganh;
	float tongDiem;
};

typedef HocVien Data;

struct Node{
	Data data;
	struct Node *next;
	struct Node *prev;
};
typedef struct Node *NodePtr;

struct List{
	NodePtr head;
	NodePtr Tail;
};

Data inputData(){
	Data hocvien;
	
	cout<<" - Ma hoc vien: ";
	cin >> hocvien.maHocVien;
	
	cout<<" - Ten hoc vien: ";
	fflush(stdin);
	getline(cin, hocvien.tenHocVien);
	
	cout<<" - Lop: ";
	fflush(stdin);
	getline(cin, hocvien.Lop);
	
	cout<<" - Chuyen nganh: ";
	fflush(stdin);
	getline(cin,hocvien.ChuyenNganh);
	
	cout<<" - Tong diem: ";
	cin >> hocvien.tongDiem;
	
	return hocvien;
}

void printNodeInfo(NodePtr pnode){
	cout << " - Ma hoc vien: " << pnode->data.maHocVien
		 << " - Ten hoc vien: " << pnode->data.tenHocVien
		 << " - Lop: " << pnode->data.Lop
		 << " - Chuyen nganh: "	<< pnode->data.ChuyenNganh
		 << " - Tong diem: " << pnode->data.tongDiem
		 << endl;
}

void initialize(List &L){
	L.head = NULL;
	L.Tail = NULL;
}

bool isEmty(List L){
	return L.head == NULL || L.Tail == NULL;
}

NodePtr CreateNode(Data data){
	NodePtr newNode = new Node;
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->data = data;
	return newNode;
}

void insertHead(List &L, Data data){
	NodePtr newNode = CreateNode(data);
	if (isEmty(L)){
		L.head = newNode;
		L.Tail = newNode;
	}
	else {
		L.head->prev = newNode;
		newNode->next = L.head;
		L.head = newNode;
	}
}

void traverseFromHead(List L)
{
	if (L.head == NULL)
		cout << "Danh sach rong!" << endl;
	else{
		NodePtr q = L.head;
		while (q != NULL){
			printNodeInfo(q);
			q = q->next;
		}
	}
}

void LietKeTuDauTheoChuyenNganh(string chuyennganh,List L){
	if(isEmty(L)) cout << "Danh sach rong!" << endl;
	else
	{
		NodePtr q = L.head;
		while(q != NULL){
			if (q->data.ChuyenNganh.compare(chuyennganh) == 0)
				printNodeInfo(q);
			q = q->next;
		}
	}
}

void deleteTail(List &L){
	if (isEmty(L))
		cout << "Danh sach rong!" << endl;
	else{
		NodePtr p = L.Tail;
		if(L.head == L.Tail) {
			L.head = NULL;
			L.Tail = NULL;
		}
		else{
			L.Tail = L.Tail->prev;
			L.Tail->next = NULL;
			p->prev = NULL;
		}
		delete p;
	}
}
int main(){
	int n;
	cout <<  "Nhap so luong hoc vien: ";
	cin >> n;
	
	List L;
	initialize(L);
	
	for(int i=0;i<n;i++){
		cout<< "Nhap thong tin hoc vien" << i+1 << ": "<< endl;
		Data hocvien = inputData();
		insertHead(L, hocvien);
	}
	cout << "Danh sach vua nhap:" << endl;
	traverseFromHead(L);
	string nganh="Thuong Mai Dien Tu";
	cout << "Danh sach theo chuyen nganh "<< nganh << ":"<<endl;
	LietKeTuDauTheoChuyenNganh(nganh,L);
	deleteTail(L);
	cout<< "Danh sach sau khi xoa cuoi:"<< endl;
	traverseFromHead(L);
	}
