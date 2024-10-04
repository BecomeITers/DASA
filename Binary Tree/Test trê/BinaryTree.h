#pragma once
#include <iostream>
#include "Node.h"
using namespace std;
struct BinaryTree {
	Node* root = NULL;

	void AddValue(int v) {
		if (root == NULL) { // Nếu gốc ko có giá trị
			root = new Node; // Ta gán gốc là nút mới
			root->value = v; // Gán giá trị
		}
		else {
			Node* foundNode = search(v, root); // Ta tìm vị trí nút phù hợp
			if (v == foundNode->value) { // Nếu giá trị cần thêm nó giống giá trị đã có sẵn trong nút nó sẽ ko gắn
				return;
			}
			Node* newNode = new Node; // Ta tạo 1 nút mới và gán giá trị cho nó
			newNode->value = v;
			if (v > foundNode->value) { // Nếu giá trị cần thêm lớn hơn giá trị nút tìm ra phù hợp
				foundNode->right = newNode; // Ta nối cái nút mới vào bên phải
			}
			else {
				foundNode->left = newNode; // Còn ko ta nối cái nút mới vào bên trái
			}
		}
	}

	Node* search(int v, Node* curNode) { // Ta tạo 1 hàm tìm kiếm đề nối phù hợp vào nút
		if (v == curNode->value) {
			return curNode;
		}
		else if (v > curNode->value) {
			if (curNode->right != NULL) {
				return search(v, curNode->right);
			}
			else {
				return curNode;
			}
		}
		else if (v < curNode->value) {
			if (curNode->left != NULL) {
				return search(v, curNode->left);
			}
			else {
				return curNode;
			}
		}
	}


};