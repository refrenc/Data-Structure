struct Term {
	int coef;
	int exp;
	Term Set(int c, int e) { coef = c; exp = e; return *this; };
};

class Polynomial {
public:
	Polynomial operator+(const Polynomial& b) const;		//�ڵ� ��û ��. p.182
private:
	Chain<Term> poly;
};