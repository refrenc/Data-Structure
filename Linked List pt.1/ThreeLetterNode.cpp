class ThreeLetterChain;

class ThreeLetterNode {
friend class ThreeLetterChain;
private:
	char data[3];
	ThreeLetterNode* link;
};

class NodeA {
private:
	int data1;
	char data2;
	float data3;
	NodeA* linka;
	NodeB* linkb;
};

class NodeB {
private:
	int data;
	NodeB* link;
};

/*설계 시도1 : friend 선언X > 클래스 밖에서 접근 불가
설계 시도2 : 체인을 노드의 friend로 선언*/
class ThreeLetterChain {
public:
private:
	ThreeLetterNode* first;
};

/*설계 시도3 : 중첩 클래스 이용*/
class ThreeLetterChain {
public:
private:
	class ThreeLetterNode {
	public:
		char data[3];
		ThreeLetterNode* link;
	};
	ThreeLetterNode* first;
};

