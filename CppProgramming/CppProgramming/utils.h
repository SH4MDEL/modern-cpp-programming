#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace MyExcel {
	class Vector {
		std::string* data;
		int capacity;
		int length;

	public:
		Vector(int n = 1);

		void push_back(std::string s);
		std::string operator[](int i);
		void remove(int x);
		int size();

		~Vector();
	};

	class Stack {
		struct Node {
			Node* prev;
			std::string s;

			Node(Node* prev, std::string s) : prev(prev), s(s) {}
		};

		Node* current;		// 현재 최상위 노드를 가리킨다.
		Node start;			// 맨 밑바닥을 이루는 노드를 가리킨다.

	public:
		Stack();

		// 최상단에 새로운 원소를 추가한다.
		void push(std::string s);

		// 최상단의 원소를 제거하고 반환한다.
		std::string pop();

		// 최상단의 원소를 반환한다.
		std::string peek();

		// 스택이 비어있는지의 유무를 확인한다.
		bool is_empty();

		~Stack();
	};

	class NumStack {
		struct Node {
			Node* prev;
			double s;

			Node(Node* prev, double s) : prev(prev), s(s) {}
		};

		Node* current;		// 현재 최상위 노드를 가리킨다.
		Node start;			// 맨 밑바닥을 이루는 노드를 가리킨다.

	public:
		NumStack();

		// 최상단에 새로운 원소를 추가한다.
		void push(double s);

		// 최상단의 원소를 제거하고 반환한다.
		double pop();

		// 최상단의 원소를 반환한다.
		double peek();

		// 스택이 비어있는지의 유무를 확인한다.
		bool is_empty();

		~NumStack();
	};
}
#endif