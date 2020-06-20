#include <iostream>
#define MaxDegree 0

using namespace std;

/*정적 배열 : 서로 다른 지수들을 내림차순으로 정돈하자*/
class Polynomial1 {
private:
	int degree;
	float coef[MaxDegree + 1];			//계수 배열, 지수의 내림차순으로 저장
public:
	
};

/*동적 배열 : 전용 데이터 멤버를 선언하자 > 생성자 추가*/
class Polynomial2 {						// 희소 다항식에서 공간낭비
private:
	int degree;
	float* coef;
public:
	Polynomial2(int d) : degree(d) {
		coef = new float[degree + 1];
	}
};

/*Term array : 모든 다항식은 배열 termArray를 이용해 표현*/
class Polynomial3;
class term {
	friend Polynomial3;
private:
	float coef;		//계수
	int exp;		//지수
};


class Polynomial3 {
private:
	term* termArray;	//0이 아닌 항의 배열
	int capacity;		//termArray의 크기
	int terms;			//0이 아닌 항의 수
public:
	void NewTerm(const float theCoeff, const int theExp);
	Polynomial3 Add(Polynomial3 b);
};

void Polynomial3::NewTerm(const float theCoef, const int theExp) {
	if (terms == capacity) {
		capacity *= 2;				//termArray의 크기를 두배로 확장
		term* temp = new term[capacity];
		copy(termArray, termArray + terms, temp);
		delete[] termArray;
		termArray = temp;
	}

	termArray[terms].coef = theCoef;
	termArray[terms++].exp = theExp;
}

Polynomial3 Polynomial3::Add(Polynomial3 b) {
	Polynomial3 c;													//빈 객체
	int aPos = 0, bPos = 0;
	while ((aPos < terms) && (bPos < b.terms)) {					//0이 아닌 항의 수보다 적은 동안
		if (termArray[aPos].exp == b.termArray[bPos].exp) {			//a, b의 지수가 같으면
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			if (t) c.NewTerm(t, termArray[aPos].exp);
			aPos++;
			bPos++;
		}
		else if (termArray[aPos].exp < b.termArray[bPos].exp) {		//a 지수가 b보다 작으면
			c.NewTerm(termArray[bPos].coef, b.termArray[bPos].exp);	//b를 새로 만듦
			bPos++;
		}
		else {														//b 지수가 a보다 작으면
			c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);	//a를 새로 만듦
			aPos++;
		}
	}

	for (; aPos < terms; aPos++)
		c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
	for (; bPos < b.terms; bPos++)
		c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);

	return c;
}