#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

struct SinglyLinkList {
	Node* head = NULL; 
	Node* tail = NULL;

	void Add(int v) { // Thêm phần tử
		if (!head) { // Nếu ko có giá trị đầu
			Node* newHead = new Node; // Ta tạo đầu mới
			newHead->value = v; // Gán giá trị vô
			newHead->next = NULL; // Thắt cái nút lại
			// Vì đây là phần tử đầu tiên nên head đại diện phần tử đầu tiên và tail cũng là phần tử nên trỏ đến newHead
			head = newHead; 
			tail = newHead;
		}
		else { // Nếu đã có giá trị đầu
			Node* newNode = new Node; // Ta tạo 1 nút mới
			newNode->value = v; // Gán giá trị vô
			newNode->next = NULL; // Thắt cái nút lại
			tail->next = newNode; // Chỉ định nút mới là nút cuối cùng
			tail = newNode; // Trỏ phần tử cuối cùng tới newNode
		}
	}

	void Insert(int v, int index) { // Chèn phần tử
		Node* curNode = head; // Ta tạo nút hiện tại
		int curInd = 0; // TRạo vị trí hiện tại
		Node* prevNode = NULL; 

		if (index == 0) { // Insert ở vị trí đầu
			Node* newNode = new Node;
			newNode->value = v;
			newNode->next = curNode;
			head = newNode;
			if (!tail) {
				tail = newNode;
			}
			return;
		}

		while (curNode) { // Vòng lặp tiếp tục cho đến khi curNode là NULL
			if (curInd == index - 1) { // Nếu vị trí hiện tại bằng vị trí - 1
				prevNode = curNode; // nứt trước đó bằng nút hiện tại
			}
			else if (curInd == index) { // Nếu vị trí hiện tại bằng vị trí
				Node* newNode = new Node; // Ta tại 1 nút mới
				newNode->value = v; // Chèn giá trị vào
				newNode->next = curNode; // Liên kết với nút hiện tại
				// A -> newNode -> B
				// Trong trường hợp này prevNode là A còn curNode là B
				if (prevNode) { // Nếu prevNode ko phải là NULL có nghĩa là vị trí chèn ko phải đầu danh sách
					prevNode->next = newNode; // Liên kết với nút trước đó có nghĩa là gắn kết nút mới vào vị trí chính xác
				}
				break;
			}
			curNode = curNode->next; // Di chuyển nút tiếp theo
			curInd++; // Tăng chỉ số hiện tại
		}

		if (index == curInd) { // Insert ở vị trí cuối
			Node* newNode = new Node;
			newNode->value = v;
			newNode->next = NULL;
			if (!head) {
				head = newNode;
			}
			return;
		}
	}

	void Print() {
		Node* curNode = head; // Bắt đầu từ đầu
		while (curNode) { // Vòng lặp cho đến khi gặp NULL
			cout << curNode->value << " "; // In ra giá trị
			curNode = curNode->next; // Di chuyển nút tiếp theo
		}
		cout << endl;
	}
};