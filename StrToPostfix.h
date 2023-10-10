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
public:
	std::string strToPostfix(std::string infS) {
		std::string postS = "";
		for (size_t i = 0; i < infS.size(); i++) {
			if (operations.find(infS[i]) != operations.end()) {
				postS += infS[i];
			}
		}
	}
};