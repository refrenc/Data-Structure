#include <iostream>

using namespace std;

class String {
private:
	char* str;
	int length;
	int* f;			//실패함수
public:
	String(char* init, int m) : str(init), length(m) {
		f = new int[length];
		f[0] = -1;
	}
	~String() {
		delete str;
		delete f;
	}
	bool operator==(String t);
	bool operator!();
	int Length();
	String Concat(String t);
	String Substr(int i, int j);
	int Find(String pat);
	int FastFind(String pat);
	void FailureFunction();
};

bool String::operator==(String t) {
	if (t == *this) return true;
	else if (this->str == t.str && this->length == t.length) return true;
	else return false;
}

int String::Length() {
	return length;
}

int String::Find(String pat) {
	for (int start = 0; start <= Length() - pat.Length(); start++) {
		int j;
		for (j = 0; j < pat.Length() && str[start + j] == pat.Substr[j]; j++) {
			if (j == pat.Length()) return start;
		}
	}

	return -1;
}

int String::FastFind(String pat) {
	int posP = 0, posS = 0;
	int lengthP = pat.Length(), lengthS = Length();
	
	while ((posP < lengthP) && (posS < lengthS)) {
		if (pat.str[posP] == str[posS]) {
			posP++;
			posS++;
		}
		else {
			if (posP == 0)
				posS++;
			else posP = pat.f[posP - 1] + 1;
		}

		if (posP < lengthP) return -1;
		else return posS - lengthP;
	}
}

void String::FailureFunction() {
	int lengthP = Length();
	f[0] = -1;

	for (int j = 1; j < lengthP; j++) {
		int i = f[j - 1];
		while ((*(str + j) != *(str + i + 1)) && (i >= 0))
			i = f[i];
		if (*(str + j) == *(str + i + 1))
			f[j] = i + 1;
		else f[j] = -1;
	}
}