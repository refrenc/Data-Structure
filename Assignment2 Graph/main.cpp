// �Ʒ��� ���� main�Լ����� �������� �ۼ��� graph.h ������ include�Ͽ�
// �־��� ������ �����ϰ� �˴ϴ�.
// *** ����! �Ʒ��� ������ ������ ��� ����ó���� �� �ֽ��ϴ�. **
#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

int main(void) {
    Graph g;

    string filename;
    getline(cin, filename);

    g.LoadMatrix(filename);
    g.PrintShortestPathWeight(0);

    return 0;
}