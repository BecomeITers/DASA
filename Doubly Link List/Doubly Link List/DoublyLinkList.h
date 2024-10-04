#pragma once
#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;
namespace DoublyNameSpace {
	struct Node {
		int data;
		Node* next;
		Node* prev;
	};

	struct DoublyLinkList {
		Node* head = nullptr;
		Node* tail = nullptr;

		int GetValue(int index) {
			if (head == nullptr) {
				return -1;
			}
			else {
				int curInd = 0;
				Node* curNode = head;
				while (curNode) {
					if (curInd == index) {
						return curNode->data;
					}
					curInd++;
					curNode = curNode->next;
				}
			}
			return -1;
		}

		int GetSize() {
			int size = 0;
			Node* curNode = head;
			while (curNode) {
				size++;
				curNode = curNode->next;
			}
			return size;
		}

		void Add(int v) {
			if (head == nullptr) {
				Node* newNode = new Node;
				newNode->data = v;
				newNode->next = nullptr;
				newNode->prev = nullptr;
				head = newNode;
				tail = newNode;
			}
			else {
				Node* newNode = new Node;
				newNode->data = v;
				newNode->next = nullptr;
				newNode->prev = tail;
				tail->next = newNode;
				tail = newNode;
			}
		}

		void Print() {
			Node* curNode = head;
			while (curNode) {
				cout << curNode->data << " ";
				curNode = curNode->next;
			}
			cout << endl;
		}

		void Insert(int v, int index) {
			Node* curNode = head;
			Node* prevNode = nullptr;
			int curInd = 0;

			if (index == 0) {
				Node* newNode = new Node;
				newNode->data = v;
				newNode->next = curNode;
				newNode->prev = nullptr;
				head = newNode;
				if (!tail) {
					tail = newNode;
				}
				return;
			}

			while (curNode) {
				if (curInd == index - 1) {
					prevNode = curNode;
				}
				else if (index == curInd) {
					Node* newNode = new Node;
					newNode->data = v;
					newNode->next = curNode;
					newNode->prev = prevNode;
					if (prevNode) {
						prevNode->next = newNode;
					}
					if (curNode) {
						curNode->prev = newNode;
					}
					return;
				}
				curNode = curNode->next;
				curInd++;
			}

			if (index == curInd) {
				Node* newNode = new Node;
				newNode->data = v;
				newNode->next = nullptr;
				newNode->prev = prevNode;
				if (prevNode) {
					prevNode->next = newNode;
				}
				tail = newNode;
				if (!head) {
					head = newNode;
				}
				return;
			}
		}

		void RemoveAt(int index) {
			Node* curNode = head;
			int curInd = 0;

			if (index == 0) {
				head = head->next;
				if (head != nullptr) {
					head->prev = nullptr;
				}
				else {
					tail = nullptr;
				}
				return;
			}

			while (curNode && curInd < index) {
				curNode = curNode->next;
				curInd++;
			}

			if (curNode) {
				Node* prevNode = curNode->prev;
				Node* nextNode = curNode->next;

				if (prevNode) {
					prevNode->next = nextNode;
				}
				if (nextNode) {
					nextNode->prev = prevNode;
				}

				else {
					tail = prevNode;
				}
			}
		}

		void Clear() {
			Node* curNode = head;
			while (curNode) {
				head = head->next;
				curNode = curNode->next;
			}
			head = nullptr;
			tail = nullptr;
		}

		void RemoveAll(int v) {
			Node* curNode = head;
			int curInd = 0;
			while (curNode) {
				if (curNode->data == v) {
					RemoveAt(curInd);
				}
				else {
					curInd++;
				}
				curNode = curNode->next;
			}
		}

		void AddRange(vector<int>& vs) {
			for (int i = 0; i < vs.size(); i++) {
				Add(vs[i]);
			}
		}

		Node* GetNode(int index) {
			Node* curNode = head;
			int curInd = 0;
			while (curNode && curInd < index) {
				curNode = curNode->next;
				curInd++;
			}
			return curNode;
		}

		void InsertAtNode(int v, Node* node) {
			Node* newNode = new Node;
			newNode->data = v;
			newNode->next = node->next;
			newNode->prev = node;

			if (node->next != nullptr) {
				node->next->prev = newNode;
			}
			node->next = newNode;
		}

		void Remove(Node* node) {
			Node* prevNode = node->prev;
			Node* nextNode = node->next;
			if (prevNode) {
				prevNode->next = nextNode;
			}
			if (nextNode) {
				nextNode->prev = prevNode;
			}
		}

		void InsertHead(int v) {
			Node* curNode = head;
			Node* newNode = new Node;
			newNode->data = v;
			newNode->next = curNode;
			newNode->prev = nullptr;
			if (curNode != nullptr) {
				curNode->prev = newNode;
			}
			head = newNode;
			if (curNode == nullptr) {
				tail = newNode;
			}
		}

		void InsertTail(int v) {
			Node* curNode = tail;
			Node* newNode = new Node;
			newNode->data = v;
			newNode->next = nullptr;
			newNode->prev = curNode;
			if (curNode != nullptr) {
				curNode->next = newNode;
			}
			tail = newNode;
			if (curNode == nullptr) {
				head = newNode;
			}
		}
	};

	void MainDoublyLinkedList() {
		DoublyLinkList* list = new DoublyLinkList();
		int choice, value, index;
		vector<int> values;
		do {
			cout << "\nMenu:\n";
			cout << "1. Get value\n";
			cout << "2. Get size\n";
			cout << "3. Add value\n";
			cout << "4. Print\n";
			cout << "5. Insert value at index\n";
			cout << "6. Remove at index\n";
			cout << "7. Clear\n";
			cout << "8. Remove all at value\n";
			cout << "9. Add range of nodes\n";
			cout << "10. Get node\n";
			cout << "11. Insert head\n";
			cout << "12. Insert tail\n";
			cout << "13. Insert value at node\n";
			cout << "14. Remove node\n";
			cout << "0. Exit\n";
			cout << "Choose: ";
			cin >> choice;

			switch (choice) {
			case 1:
				cout << "Enter index: ";
				cin >> index;
				cout << "Result: ";
				list->GetValue(index);
				break;

			case 2:
				cout << "Result: ";
				list->GetSize();
				break;

			case 3:
				cout << "Enter value: ";
				cin >> value;
				list->Add(value);
				cout << "Update complete!";
				break;

			case 4:
				cout << "Result: ";
				list->Print();
				break;

			case 5:
				cout << "Enter value: ";
				cin >> value;
				cout << "Enter index: ";
				list->Insert(value, index);
				cout << "Update complete!";
				break;

			case 6: 
				cout << "Enter index: ";
				cin >> index;
				list->RemoveAt(index);
				cout << "Update complete!";
				break;

			case 7:
				list->Clear();
				cout << "Update complete!";
				break;

			case 8: 
				cout << "Enter value: ";
				cin >> value;
				list->RemoveAll(value);
				cout << "Update complete!";
				break;

			case 9: 
				int SizeRange, ValueRange;
				cout << "Enter size: ";
				cin >> SizeRange;
				for (int i = 0; i < SizeRange; i++) {
					cout << "Enter value: ";
					cin >> ValueRange;
					values.push_back(ValueRange);
				}
				list->AddRange(values);
				cout << "Update complete!";
				values.clear();
				break;

			case 10:
				cout << "Enter index: ";
				cin >> index;
				if (list->GetNode(index)) {
					cout << "Node value: " << list->GetNode(index)->data << endl;
				}
				else {
					cout << "Invalid";
				}
				break;

			case 11:
				cout << "Enter value: ";
				cin >> value;
				list->InsertHead(value);
				cout << "Update complete!";
				break;

			case 12:
				cout << "Enter value: ";
				cin >> value;
				list->InsertTail(value);
				cout << "Update complete!";
				break;


			case 13: 
				cout << "Enter index: ";
				cin >> index;
				cout << "Enter value: ";
				cin >> value;
				list->InsertAtNode(value, list->GetNode(index));
				cout << "Update complete!";
				break;
				
			case 14:
				cout << "Enter index: ";
				cin >> index;
				list->Remove(list->GetNode(index));
				cout << "Update complete!";
				break;

			case 0:
				cout << "Exit";
				break;

			default:
				cout << "Invalid option! Please choose again";
			}
		}
		while (choice != 0);

		delete list;
	}
}