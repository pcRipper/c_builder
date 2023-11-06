#include "..\Headers\lab8.h"

DEFINE_VECTOR_TYPE(VectorInt,int)
DEFINE_VECTOR_TYPE(MatrixInt,VectorInt)

DEFINE_VECTOR_TYPE(VectorChar,char)
DEFINE_VECTOR_TYPE(MatrixChar,VectorChar)
DEFINE_VECTOR_TYPE(Matrix3D,MatrixChar)

#pragma region Functions

int randomFillNegatives(size_t index){
    static const int FROM = -100;
    static const int TO = 100;
    return rand() % (TO - FROM) + FROM;
}

char signsFill(size_t index){
    static const char POSSIBLE_SIGNS[15] = { ' ','0','1','2','3','4','5','6','7','8','9','+','-','/','*'};
    return POSSIBLE_SIGNS[rand() % 14];
}

#pragma endregion


void taskI19_1() {
    static const size_t SIZE = 10;
    VectorInt* vector = VectorInt_init(SIZE);
    VectorInt_fillWith(vector,randomFill);

    VectorInt_showVector(vector,intOutput);

    int num;
    printf("Input number to remove: ");
    scanf("%d",&num);

    int l = 0;
    for(int i = 0;i < vector->size;++i){
        if(vector->data[i] == num)continue;
        vector->data[l++] = vector->data[i];
    }

    if(l == vector->size){
        l += 1;
        VectorInt_push(vector,num);
    }

    VectorInt_resize(vector,l);
    VectorInt_showVector(vector,intOutput);
    VectorInt_free(vector);
}

void taskI19_2() {
    static const size_t SIZE = 70;

    VectorInt* vector = VectorInt_init(SIZE);
    VectorInt_resize(vector,SIZE);
    VectorInt_fillWith(vector,randomFillNegatives);

    VectorInt_showVector(vector,intOutput);
    
    int top = 0;
    int bottom = 0;
    for(int i = 0;i < vector->size;++i){
        top += vector->data[i];
        bottom += abs(vector->data[i]);
    }

    printf("Z = %lf\n",bottom == 0 ? 0 : (double)top / bottom);

    VectorInt_free(vector);
}

void taskI19_3() {
    static const size_t ROWS = 7;
    static const size_t COLUMNS = 8;
    MatrixInt* matrix = MatrixInt_init(ROWS);
    
    //create matrix and fill
    for(size_t r = 0;r < ROWS;++r){
        matrix->data[r] = *VectorInt_init(COLUMNS);
        for(size_t c = 0;c < COLUMNS;++c){
            matrix->data[r].data[c] = (r + c)&1 ? 0 : 1; 
        }
        VectorInt_showVector(&matrix->data[r],intOutput);
    }

    //delete matrix
    for(int i = 0;i < matrix->size;++i){
        VectorInt_free(&matrix->data[i]);
    }
    MatrixInt_free(matrix);
}

void taskI19_4() {
    static const size_t ROWS = 10;
    static const size_t COLUMNS = 10;
    MatrixInt* matrix = MatrixInt_init(ROWS);

    //create, generate and output the matrix
    for(size_t r = 0;r < ROWS;++r){
        matrix->data[r] = *VectorInt_init(COLUMNS);
        VectorInt_fillWith(&matrix->data[r],randomFillNegatives);
        VectorInt_showVector(&matrix->data[r],intOutput);
    }
    //Count amount of negative numbers in each column
    VectorInt* amount = VectorInt_init(COLUMNS);
    for(size_t c = 0;c < COLUMNS;++c) {
        int at_column = 0;
        for(size_t r = 0;r < ROWS;++r) {
            at_column += matrix->data[r].data[c] < 0;
        }
        amount->data[c] = at_column;
    }
    //output calculated vector
    printf("Amount of negatives in each column: ");
    VectorInt_showVector(amount,intOutput);
    //delete vector
    VectorInt_free(amount);
    //delete matrix
    for(int i = 0;i < matrix->size;++i){
        VectorInt_free(&matrix->data[i]);
    }
    MatrixInt_free(matrix);
}

void taskI19_5() {
    static const size_t SHEETS = 12;
    static const size_t ROWS = 50;
    static const size_t COLUMNS = 30;
    
    //Create and generate
    Matrix3D* book = Matrix3D_init(SHEETS);
    for(size_t s = 0;s < SHEETS; ++s){
        book->data[s] = *MatrixChar_init(ROWS);
        for(size_t r = 0;r < ROWS;++r){
            book->data[s].data[r] = *VectorChar_init(COLUMNS);
            VectorChar_fillWith(&book->data[s].data[r],signsFill);
        }
    }

    //output whole book
    for(size_t s = 0;s < SHEETS; ++s){
        printf("Page #%d\n",s+1);
        for(size_t r = 0;r < ROWS;++r){
            VectorChar_showVector(&book->data[s].data[r],charOutput);
        }
    }

    //calculate
    int general_amount = 0;
    int grades = 0;
    for(size_t s = 0;s < SHEETS; ++s){
        for(size_t r = 0;r < ROWS;++r){
            VectorChar* row = &book->data[s].data[r];
            for(size_t c = 0;c < COLUMNS;++c){
                if(row->data[c] != '5')continue;
                general_amount += 1;
                if((s & 1) == 0 && c < COLUMNS - 4)continue;
                if((s & 1) == 1 && c > 3)continue;
                if((c+1 == COLUMNS || row->data[c+1] == ' ') && (c == 0 || row->data[c-1] == ' ')){
                    grades += 1;
                    printf("%dx%dx%d, ",s,r,c);
                }
            }       
        }
    }

    //output result
    printf("\nGeneral amount of 5 = %d;Amount of grades = %d;\n",general_amount,grades);

    //delete matrix
    for(size_t s = 0;s < SHEETS;++s){
        for(size_t r = 0;r < ROWS;++r){
            VectorChar_free(&book->data[s].data[r]);
        }
        MatrixChar_free(&book->data[s]);
    }
    Matrix3D_free(book);
}
