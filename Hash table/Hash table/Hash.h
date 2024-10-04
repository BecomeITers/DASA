#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace HashTable {
	struct HashItem {
		string key;
		string value;
		HashItem* next;
		HashItem* prev;
	};
	struct HashTable {
		vector<HashItem*>table;
		int capacity;

		HashTable(int size) {
			capacity = size;
			table.resize(size, nullptr);
		}

		int HashFunction(const string& key) {
			int hash = 0;
			for (char ch : key) {
				hash = (hash * 31 + ch) % capacity;
			}
			return hash;
		}

		string GetValue(const string& k) {
			int index = HashFunction(k);
			HashItem* curItem = table[index];
			while (curItem) {
				if (curItem->key == k) {
					return curItem->value;
					break;
				}
				curItem = curItem->next;
			}
			cout << "Invalid";
			return "";
		}

		string GetKey(const string& v) {
			for (int i = 0; i < capacity; i++) {
				HashItem* curItem = table[i];
				while (curItem) {
					if (curItem->value == v) {
						return curItem->key;
					}
					curItem = curItem->next;
				}
			}
			cout << "Invalid" << endl;
			return "";
		}

		void Add(const string& v, const string& k) {
			int index = HashFunction(k);
			HashItem* newItem = new HashItem();
			newItem->key = k;
			newItem->value = v;
			newItem->next = nullptr;
			newItem->prev = nullptr;

			if (table[index] == nullptr) {
				table[index] = newItem;
			}
			else {
				HashItem* curItem = table[index];
				while (curItem->next != nullptr) {
					curItem = curItem->next;
				}
				curItem->next = newItem;
				newItem->prev = curItem;
			}
		}

		void Remove(const string& k) {
			int index = HashFunction(k);
			HashItem* curItem = table[index];
			while (curItem && curItem->key != k) {
				curItem = curItem->next;
			}
			if (curItem == nullptr) {
				cout << "Invalid";
				return;
			}
			HashItem* prevItem = curItem->prev;
			HashItem* nextItem = curItem->next;
			if (prevItem) {
				prevItem->next = nextItem;
			}
			if (nextItem) {
				nextItem->prev = prevItem;
			}
			delete curItem;
		}

		void Print() {
			for (int i = 0; i < capacity; i++) {
				HashItem* curItem = table[i];
				while (curItem) {
					cout << curItem->value << " ";
					curItem = curItem->next;
				}
			}
			cout << endl;
		}

		void Clear() {
			for (int i = 0; i < capacity; i++) {
				HashItem* curItem = table[i];
				while (curItem) {
					curItem = curItem->next;
				}
				table[i] = nullptr;
			}
		}
	};

	void MainHashTable() {
		HashTable ht(100);
		int choice;
		string key, value;

		do {
			cout << "\nMenu:\n";
			cout << "1. Get value\n";
			cout << "2. get key\n";
			cout << "3. Add\n";
			cout << "4. Remove\n";
			cout << "5. Print\n";
			cout << "6. Clear\n";
			cout << "0. Exit\n";
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) {
			case 1:
				cout << "Enter key: ";
				cin >> key;
				cout << "Result: " << ht.GetValue(key);
				break;

			case 2:
				cout << "Enter value: ";
				cin >> value;
				cout << "Result: " << ht.GetKey(value);
				break;

			case 3:
				cout << "Enter value: ";
				cin >> value;
				cout << "Enter key: ";
				cin >> key;
				ht.Add(value, key);
				cout << "Update complete!";
				break;

			case 4:
				cout << "Enter key: ";
				cin >> key;
				ht.Remove(key);
				cout << "Update complete!";
				break;

			case 5:
				cout << "Result: ";
				ht.Print();
				break;

			case 6:
				cout << "Result: ";
				ht.Clear();
				break;

			case 0:
				cout << "Exit";
				break;

			default:
				cout << "Invalid option! Please choose again";
			}
		} while (choice != 0);
	}
}