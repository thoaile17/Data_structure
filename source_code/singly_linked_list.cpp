#include<iostream>

using namespace std;

struct Node{
  char data;
  Node* next;
};

// Thêm Node vào đầu List
void PushFront(Node* &head, char c){
  // Tạo Node mới
  Node* new_node = new Node();
  new_node->data = c;

  // Nếu List rỗng
  if (head == NULL){
    head = new_node;
    return;
  }

  // Liên kết Head vào sau Node mới,
  // lúc này Node mới ở vị trí đầu List,
  // Ta gán Head = vị trí Node mới
  new_node->next = head;
  head = new_node;
}

// Thêm Node vào cuối List
void PushBack(Node* &head, char c){
  // Tạo Node mới
  Node* new_node = new Node();
  new_node->data = c;

  // Nếu List rỗng
  if (head == NULL){
    head = new_node;
    return;
  }

  // Tìm Node ở cuối list
  Node* last = head;
  while(last->next != NULL){
    last = last->next;
  }

  // Liên kết Node mới vào cuối List
  last->next = new_node;
}

// Thêm Node vào sau Node đầu tiên trong List có giá trị bằng x
void PushNodeAfterNode(Node* &head, char x, char c){
  // Tìm Node đầu tiên trong List có giá trị bằng x
  Node* curr = head;
  while(curr != NULL && curr->data != x){
    curr = curr->next;
  }

  // Nếu tìm thấy thì thực hiện chèn
  if (curr != NULL){
    // Tạo Node mới
    Node* new_node = new Node();
    new_node->data = c;

    // Liên kết Node mới vào
    Node* tmp = curr->next;
    curr->next = new_node;
    new_node->next = tmp;
  }
}

// Xóa Node đầu List
void PopFront(Node* &head){
  // Nếu List không rỗng
  if (head != NULL){
    Node* tmp = head; // Giữ lại vị trí head cũ
    head = head->next; // Cập nhật lại vị trí head
    delete tmp; // Xóa head cũ
  }
}

// Xóa Node cuối List
void PopBack(Node* &head){
  // Nếu List không rỗng
  if (head != NULL){
    // Nếu List chỉ có một phần tử
    if (head->next == NULL){
      PopFront(head);
      return;
    }
    
    // Tìm Node cuối List và Node trước nó
    Node* last = head;
    Node* prev = head; // Node này để lưu vị trí phía trước của Node cuối
    while(last->next != NULL){
      prev = last;
      last = last->next;
    }

    prev->next = NULL;
    delete last;
  }
}

// Xóa Node đầu tiên có giá trị bằng x trong List
void Delete(Node* &head, char x){
	// Nếu List rỗng
	if (head != NULL){
		// Nếu head->data có giá trị bằng x => thực hiện PopFront()
		if (head->data == x){
			PopFront(head);
			return;
		}

		// Tìm Node
		Node* curr = head;
		Node* prev = NULL; // Để lưu vị trí Node phía trước Node cần xóa
		while(curr != NULL && curr->data != x){
			prev = curr;
			curr = curr->next;
		}

		// Nếu tìm thấy Node
		if (curr != NULL){
			// Nếu prev = NULL => List chỉ có một Node
			if (prev == NULL){
				head = NULL;
			}else{
				prev->next = curr->next;
				delete curr;
			}
		}
	}
}

// In List
void PrintList(Node* head){
  Node* curr = head;
  while(curr != NULL){
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}


int main(){
  Node* head = new Node();
  // Khởi tạo List rỗng
  head = NULL;

  cout << "Push in front List: \n";
  // Thêm Node vào đầu List
  PushFront(head,'C');
  PushFront(head,'B');
  PushFront(head,'A');
  PrintList(head);

  cout << "Push in back List: \n";
  // Thêm Node vào cuối List
  PushBack(head,'X');
  PushBack(head,'Y');
  PushBack(head,'Z');
  PrintList(head);

  cout << "Push Node D after node C: \n";
  // Thêm Node vào sau Node "C"
  PushNodeAfterNode(head,'C','D');
  PrintList(head);

  cout << "Remove first node: \n";
  // Xóa Node đầu tiên
  PopFront(head);
  PrintList(head);

  cout << "Remove last node: \n";
  // Xóa Node cuối
  PopBack(head);
  PrintList(head);

  // Xóa Node bất kỳ
  cout << "Remove node D: \n";
  Delete(head,'D');
  PrintList(head);

  return 0;
}
