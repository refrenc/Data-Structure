#include <iostream>

using namespace std;

/*<행, 열, 값>으로 식별*/
class SparseMatrix;
class MatrixTerm {
	friend class SparseMatrix;
private:
	int row, col, value;
};

class SparseMatrix {
private:
	int rows, cols, terms, capacity;				//terms : 0이 아닌 항의 총수, capacity : smArray의 크기
	MatrixTerm* smArray;
public:
	SparseMatrix(int r, int c, int t) : rows(r), cols(c), terms(t) {
		capacity = terms;
		smArray = new MatrixTerm[capacity];
	}
	~SparseMatrix() { delete smArray; }
	void SortArray();
	SparseMatrix Transpose();
	SparseMatrix Add(SparseMatrix b);
	SparseMatrix Multiply(SparseMatrix b);
	SparseMatrix FastTranspose();
	void StoreSum(const int sum, const int r, const int c);
	void ChangeSize1D(const int newSize);
};

void SparseMatrix::SortArray() {
	for (int i = 0; i < capacity; i++) {
		for (int j = i; j < capacity; j++) {
			if ((smArray[i].row > smArray[j].row)) {
				MatrixTerm temp = smArray[i];
				smArray[i] = smArray[j];
				smArray[j] = temp;
			}
			else if ((smArray[i].row == smArray[j].row) && (smArray[i].col > smArray[j].col)) {
				MatrixTerm temp = smArray[i];
				smArray[i] = smArray[j];
				smArray[j] = temp;
			}
		}
	}
}

/*O(terms*cols)*/
SparseMatrix SparseMatrix::Transpose() {
	SparseMatrix b(cols, rows, terms);				//b의 행은 *this의 열
	if (terms > 0) {
		int currentB = 0;
		for (int c = 0; c < cols; c++) {			//*this의 열이 0인 것부터
			for (int i = 0; i < terms; i++) {		//smArray 배열 훑기
				if (smArray[i].col == c) {
					b.smArray[currentB].row = c;
					b.smArray[currentB].col = smArray[i].row;
					b.smArray[currentB++].value = smArray[i].value;
				}
			}
		}
	}

	return b;
}

/*O(terms+cols)*/
SparseMatrix SparseMatrix::FastTranspose() {
	SparseMatrix b(cols, rows, terms);
	if (terms > 0) {
		int* rowSize = new int[cols];
		int* rowStart = new int[cols];

		fill(rowSize, rowSize + cols, 0);		//0으로 초기화
		for (int i = 0; i < terms; i++) rowSize[smArray[i].col]++;

		rowStart[0] = 0;
		for (int i = 0; i < cols; i++) rowStart[i] = rowStart[i - 1] + rowSize[i - 1];

		for (int i = 0; i < terms; i++) {
			int j = rowStart[smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			rowStart[smArray[i].col]++;
		}

		delete[] rowSize;
		delete[] rowStart;
	}

	return b;
}

void SparseMatrix::StoreSum(const int sum, const int r, const int c) {
	if (sum != 0) {
		if (terms == capacity) ChangeSize1D(2 * capacity);
		smArray[terms].row = r;
		smArray[terms].col = c;
		smArray[terms++].value = sum;
	}
}

void SparseMatrix::ChangeSize1D(const int newSize) {		//smArray 크기 변경
	if (newSize < terms) throw "New size must be >= number of terms";
	MatrixTerm* temp = new MatrixTerm[newSize];
	copy(smArray, smArray + terms, temp);
	delete[] smArray;
	smArray = temp;
	capacity = newSize;
}

SparseMatrix SparseMatrix::Multiply(SparseMatrix b) {
	if (cols != b.rows) throw "Incompatible matrices";
	SparseMatrix bXpose = b.FastTranspose();
	SparseMatrix d(rows, b.cols, 0);
	int currRowIndex = 0, currRowBegin = 0, currRowA = smArray[0].row;

	if (terms == capacity) ChangeSize1D(terms + 1);

	bXpose.ChangeSize1D(bXpose.terms + 1);
	smArray[terms].row = rows;
	bXpose.smArray[b.terms].row = b.cols;
	bXpose.smArray[b.terms].col = -1;

	int sum = 0;
	while (currRowIndex < terms) {
		int currColB = bXpose.smArray[0].row;
		int currColIndex = 0;
		while (currColIndex < terms) {
			if (smArray[currRowIndex].row != currRowA) {
				d.StoreSum(sum, currRowA, currColB);
				sum = 0;
				currRowIndex = currRowBegin;

				while (bXpose.smArray[currColIndex].row == currColB) currColIndex++;
				currColB = bXpose.smArray[currColIndex].row;
			}
			else if (bXpose.smArray[currColIndex].row != currColB) {
				d.StoreSum(sum, currRowA, currColB);
				sum = 0;
				currRowIndex = currRowBegin;
				currColB = bXpose.smArray[currColIndex].row;
			}
			else if (smArray[currRowIndex].col < bXpose.smArray[currColIndex].col) currRowIndex++;
			else if (smArray[currRowIndex].col == bXpose.smArray[currColIndex].col) {
				sum += smArray[currRowIndex].value * bXpose.smArray[currColIndex].value;
				currRowIndex++;
				currColIndex++;
			}
			else currColIndex++;
		}

		while (smArray[currRowIndex].row == currRowA) currRowIndex++;
		currRowBegin = currRowIndex;
		currRowA = smArray[currRowIndex].row;
	}

	return d;
} 