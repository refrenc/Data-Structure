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

/*���� �õ�1 : friend ����X > Ŭ���� �ۿ��� ���� �Ұ�
���� �õ�2 : ü���� ����� friend�� ����*/
class ThreeLetterChain {
public:
private:
	ThreeLetterNode* first;
};

/*���� �õ�3 : ��ø Ŭ���� �̿�*/
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

