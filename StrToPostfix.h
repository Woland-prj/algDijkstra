#pragma once 
#include <string>
#include <map>
#include <set>
#include "Stack.h"
#include <iostream>

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
	std::string convertToRightStr(std::string str) {
		std::string rightStr = "";
		bool unarMinus = false;		
		if (str[0] == '-') {
			unarMinus = true;
		}
		for (size_t i = 0; i < str.size(); i++) {
			if (unarMinus && str[i] == '-')
				rightStr += "0-";
			else
				rightStr += str[i];
			unarMinus = false;
			if (str[i] == '(') unarMinus = true;
		}
		return rightStr;
	}


	std::string strToPostfix(std::string infS) {
		infS = convertToRightStr(infS);
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
			//std::cout << infS[i] << ' ' << operationPriority.at(infS[i]) << ' ' << st.Pull() << ' ' << operationPriority.at(st.Pull());
			if (infS[i] != '^' && (operationPriority.at(infS[i]) <= operationPriority.at(st.Pull()))) {
				while (!st.isEmpty() && st.Pull() != '(' && (operationPriority.at(st.Pull()) >= operationPriority.at(infS[i])))
					postS += st.Pop();
			}
			st.Push(infS[i]);
		};
		while (!st.isEmpty())
			postS += st.Pop();
		return postS;
	}
};