#pragma once 
#include <string>
#include <map>
#include <set>
#include "Stack.h"

class CStrToPostfix {
private:
	const std::set<char> operations = { '+', '-', '*', '/', '^' };
	const std::map<char, int> operationPriority = {
		{'+', 1},
		{'-', 1},
		{'*', 2},
		{'/', 2},
		{'^', 3}
	};
	CStack st;
	bool isOpInSt = false;
	char tempChar;
public:
	std::string strToPostfix(std::string infS) {
		std::string postS = "";
		for (size_t i = 0; i < infS.size(); i++) {
			if (infS[i] == '(') {
				st.Push(infS[i]);
				continue;
			}
			if (infS[i] == ')') {
				tempChar = ' ';
				while (!st.isEmpty() && tempChar != '(') {
					if (tempChar != ' ') postS += tempChar;
					tempChar = st.Pop();
				}
				continue;
			}
			if (operations.find(infS[i]) == operations.end()) {
				postS += infS[i];
				continue;
			}
			if (st.isEmpty() || (!st.isEmpty() && st.Pull() == '(')) {
				st.Push(infS[i]);
				continue;
			}
			if (infS[i] != '^' && operationPriority.at(infS[i]) <= operationPriority.at(st.Pull())) {
				tempChar = ' ';
				while (!st.isEmpty() && tempChar != '(' && (tempChar == ' ' || operationPriority.at(tempChar) < operationPriority.at(infS[i]))) {
					if (tempChar != ' ') postS += tempChar;
					tempChar = st.Pop();
				}
			}
			if (infS[i] == '^') {
				tempChar = ' ';
				while (!st.isEmpty() && tempChar != '(') {
					if (tempChar != ' ') postS += tempChar;
					tempChar = st.Pop();
				}
			}
			st.Push(infS[i]);
		};
		while (!st.isEmpty())
			postS += st.Pop();
		// std::cout << postS << std::endl;
		return postS;
	}
};