#pragma once
using DataType = char;

class CStack {
private:
	struct St {
		DataType Data;
		St* Next;
	};
	St* Top, * El;
public:
	CStack() {
		Top = nullptr;
		El = nullptr;
	}

	void Push(DataType D) {
		El = new St;
		El->Next = Top;
		El->Data = D;
		Top = El;
	}

	bool isEmpty() {
		return Top == nullptr;
	}

	DataType Pull() {
		if (!this->isEmpty()) 
			return Top->Data;
	}

	DataType Pop() {
		DataType D;
		if (!this->isEmpty()) {
			D = Top->Data;
			El = Top;
			Top = El->Next;
			delete El;
			return D;
		}
	}

	~CStack() {
		while (!this->isEmpty()) {
			El = Top;
			Top = El->Next;
			delete El;
		}
	}
};