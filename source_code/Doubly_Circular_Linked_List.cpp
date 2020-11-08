#include<iostream>

using namespace std;

struct Node{
  char data;
  Node* next;
  Node* prev;
};


// Thêm Node vào đầu List
void PushFront(Node* &head, char c){
  // Tạo Node mới
  Node* new_node = new Node();
  new_node->data = c;

  // Nếu List rỗng, gán bằng new_node và tạo vòng
  if (head == NULL){
    head = new_node;
    head->next = head;
    head->prev = head;
    return;
  }

  Node* last = head->prev;

  new_node->next = head;
  new_node->prev = last;
  last->next = new_node;
  head->prev = new_node;
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
    head->next = head;
    head->prev = head;
    return;
  }

  Node* last = head->prev;

  // Liên kết Node mới vào cuối List
  last->next = new_node;
  new_node->next = head;
  new_node->prev = last;
  head->prev = new_node;
}

// Thêm Node vào sau Node đầu tiên trong List có giá trị bằng x
void PushNodeAfterNode(Node* &head, char x, char c){
  // Tìm Node đầu tiên trong List có giá trị bằng x
  Node* curr = head;
  while(curr->data != x){
    curr = curr->next;
    if (curr == head){
      curr = NULL;
      break;
    }
  }

  // Nếu tìm thấy thì thực hiện chèn
  if (curr != NULL){
    // Tạo Node mới
    Node* new_node = new Node();
    new_node->data = c;

    // Liên kết Node mới vào
    Node* tmp = curr->next;

    curr->next = new_node;
    new_node->prev = curr;

    new_node->next = tmp;
    tmp->prev = new_node;
  }
}

// Xóa Node đầu List
void PopFront(Node* &head){
  // Nếu List không rỗng
  if (head != NULL){
    // Nếu List có 1 phần tử
    if (head->next == head && head->prev == head){
      head = NULL;
      return;
    }

    // Nếu có nhiều phần tử
    Node* tmp = head; // Giữ lại vị trí head cũ
    Node* last = head->prev;
    head = head->next; // Cập nhật lại vị trí head
    head->prev = last;
    last->next = head;

    delete tmp; // Xóa head cũ
  }
}

// Xóa Node cuối List
void PopBack(Node* &head){
  // Nếu List không rỗng
  if (head != NULL){

    // Nếu List chỉ có một phần tử
    if (head->next == head && head->prev == head){
      head = NULL;
      return;
    }

    Node* Last = head->prev;
    Node* BeforeLast = Last->prev;

    BeforeLast->next = head;
    head->prev = BeforeLast;

    delete Last;
  }
}

// Xóa Node đầu tiên có giá trị bằng x trong List
void Delete(Node* &head, char x){
	// Nếu List không rỗng
	if (head != NULL){
		// Nếu head->data có giá trị bằng x => thực hiện PopFront()
		if (head->data == x){
			PopFront(head);
			return;
		}

		// Tìm Node
		Node* curr = head;
		while(curr->data != x){
			curr = curr->next;
			if (curr == head){
        curr = NULL;
        break;
			}
		}

		// Nếu tìm thấy Node
		if (curr != NULL){
      if (curr->prev == head && curr->next == head){ // List có 1 phần tử
          head = NULL;
      }else{
        if (curr->next == head){ // Phần tử tìm được ở cuối List
            PopBack(head);
            return;
        }else if (curr->prev == head->prev){ // Phần tử tìm được ở đầu List
            PopFront(head);
            return;
        }else{
            Node* CurrPrev = curr->prev; // Node trước của Node cần xóa
            Node* CurrNext = curr->next; // Node sau của Node cần xóa

            CurrPrev->next = CurrNext;
            CurrNext->prev = CurrPrev;

            delete curr;
        }
      }
		}
	}
}

// In List
void PrintList(Node* head){

  // Nếu List rỗng
  if (head == NULL){
    return;
  }
  Node* curr = head;
  while(curr->next){
    cout << curr->data << " ";
    curr = curr->next;
    if (curr == head) break;
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
  // Thêm Node vào đầu List
  PushBack(head,'D');
  PushBack(head,'F');
  PushBack(head,'G');
  PrintList(head);

  cout << "Push After Node D: \n";
  // Thêm Node vào cuối List
  PushNodeAfterNode(head,'D','E');
  PrintList(head);

  cout << "After Remove First Node: \n";
  // Xóa Node đầu list
  PopFront(head);
  PrintList(head);

  cout << "After Remove Last Node: \n";
  // Xóa Node cuối list
  PopBack(head);
  PrintList(head);

  cout << "After Remove Node 'D': \n";
  // Xóa Node cuối list
  Delete(head,'D');
  PrintList(head);

  return 0;
}
