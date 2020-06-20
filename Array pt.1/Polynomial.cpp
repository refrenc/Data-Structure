#include <iostream>
#define MaxDegree 0

using namespace std;

/*���� �迭 : ���� �ٸ� �������� ������������ ��������*/
class Polynomial1 {
private:
	int degree;
	float coef[MaxDegree + 1];			//��� �迭, ������ ������������ ����
public:
	
};

/*���� �迭 : ���� ������ ����� �������� > ������ �߰�*/
class Polynomial2 {						// ��� ���׽Ŀ��� ��������
private:
	int degree;
	float* coef;
public:
	Polynomial2(int d) : degree(d) {
		coef = new float[degree + 1];
	}
};

/*Term array : ��� ���׽��� �迭 termArray�� �̿��� ǥ��*/
class Polynomial3;
class term {
	friend Polynomial3;
private:
	float coef;		//���
	int exp;		//����
};


class Polynomial3 {
private:
	term* termArray;	//0�� �ƴ� ���� �迭
	int capacity;		//termArray�� ũ��
	int terms;			//0�� �ƴ� ���� ��
public:
	void NewTerm(const float theCoeff, const int theExp);
	Polynomial3 Add(Polynomial3 b);
};

void Polynomial3::NewTerm(const float theCoef, const int theExp) {
	if (terms == capacity) {
		capacity *= 2;				//termArray�� ũ�⸦ �ι�� Ȯ��
		term* temp = new term[capacity];
		copy(termArray, termArray + terms, temp);
		delete[] termArray;
		termArray = temp;
	}

	termArray[terms].coef = theCoef;
	termArray[terms++].exp = theExp;
}

Polynomial3 Polynomial3::Add(Polynomial3 b) {
	Polynomial3 c;													//�� ��ü
	int aPos = 0, bPos = 0;
	while ((aPos < terms) && (bPos < b.terms)) {					//0�� �ƴ� ���� ������ ���� ����
		if (termArray[aPos].exp == b.termArray[bPos].exp) {			//a, b�� ������ ������
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t) c.NewTerm(t, termArray[aPos].exp);
			aPos++;
			bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp) {		//a ������ b���� ������
			c.NewTerm(termArray[bPos].coef, b.termArray[bPos].exp);	//b�� ���� ����
			bPos++;
		}
		else {														//b ������ a���� ������
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);	//a�� ���� ����
			aPos++;
		}
	}

	for (; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	for (; bPos < b.terms; bPos++)
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);

	return c;
}