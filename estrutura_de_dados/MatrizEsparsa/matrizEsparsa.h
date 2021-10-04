typedef struct matrix sparseMatrix;

sparseMatrix* create(int rows, int columns);

int assign(sparseMatrix* matrix, int row, int column, int data);

int getData(sparseMatrix* matrix, int row, int column, int* data);

void release(sparseMatrix* matrix);

int show(sparseMatrix* matrix);

int getPrimaryDiagonal(sparseMatrix* matrix);

int getSecondaryDiagonal(sparseMatrix* matrix);
