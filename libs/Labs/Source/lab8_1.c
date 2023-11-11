#include "..\Headers\lab8_1.h"

int minCoins(VectorInt* values,size_t sum) {
    static VectorInt* dp = 0;
    if(dp == NULL)dp = VectorInt_init(sum + 1);
    if(dp->size < sum)VectorInt_resize(dp,sum + 1);
    if(values == NULL)return -1;

    VectorInt_fill(dp, -1);
    dp->data[0] = 0;

    for(size_t i = 0;i < sum;++i){
        if(dp->data[i] == -1)continue;
        for(size_t j = 0;j < values->size;++j){
            if(i + values->data[j] > sum)continue;
            dp->data[i + values->data[j]] = dp->data[i + values->data[j]] == -1 ? 
                dp->data[i] + 1 : 
                min(dp->data[i + values->data[j]], dp->data[i] + 1)
            ;
        }
    }

    return dp->data[sum];
}

bool in_range(size_t l,size_t r, size_t x) { return l <= x && x <= r; }

MatrixInt* spiralOrder(size_t n,size_t m) {
    static int directions[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

    MatrixInt* result = MatrixInt_initMatrix(n,m);
    size_t dir = 0;
    size_t x = 0, y = 0;
    size_t row_l = 0,row_r = n - 1;
    size_t col_l = 0,col_r = m - 1;
    const size_t amount = n * m;

    for (int k = 0; k < amount; ++k) {

        result->data[y].data[x] = k + 1;

        if (!in_range(col_l,col_r,x + directions[dir][1]) || !in_range(row_l,row_r, y + directions[dir][0])) {
            if (dir == 0)++row_l;
            else if (dir == 1)--col_r;
            else if (dir == 2)--row_r;
            else ++col_l;
            dir = (dir + 1) % 4;
        }
        y += directions[dir][0];
        x += directions[dir][1];
    }

    return result;
}

//task3
int generateFill(size_t index){
    static const int FROM = -500;
    static const int TO = 500;
    return rand() % (TO - FROM) + FROM;
}

Matrix3D* generate3D(size_t z,size_t y,size_t x){
    Matrix3D* result = Matrix3D_initMatrix(z,y);
    
    for(size_t zi = 0;zi < z;++zi){
        for(size_t yi = 0;yi < y;++yi){
            result->data[zi].data[yi] = *VectorInt_init(x);
            VectorInt_fillWith(&result->data[zi].data[yi],generateFill);
        }
    }

    return result;
}

VectorInt* statistic(Matrix3D* data){
    static const int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(data == NULL)return NULL;
    VectorInt* result = VectorInt_init(0);
    VectorInt_reserve(result, data->size * 2 + 2);

    int most_min = INT_MAX;
    int most_max = INT_MIN;
    for(size_t year = 0;year < data->size;++year) {
        int min_temp = INT_MAX;
        int max_temp = INT_MIN;

        size_t months_amount = min(12,data->data[year].size);
        for(size_t month = 0;month < months_amount;++month) {

            size_t amount_days = min(months[month], data->data[year].data[month].size);
            for(size_t day = 0;day < amount_days;++day){
                min_temp = min(min_temp,data->data[year].data[month].data[day]);
                max_temp = max(max_temp,data->data[year].data[month].data[day]);
            }
        }

        VectorInt_push(result,min_temp);
        VectorInt_push(result,max_temp);
        most_min = min(most_min,min_temp);
        most_max = max(most_max,max_temp);
    }

    VectorInt_push(result,most_min);
    VectorInt_push(result,most_max);

    return result;
}


//task4
size_t sortNumber(size_t num){
    static char amount[10];
    
    memset(&amount[0],0,10);
    while(num > 0){
        ++amount[num%10];
        num /= 10;
    }

    for(int i = 1;i < 10;++i){
        while(amount[i]-- > 0){
            num = num * 10 + i;
        }
    }

    return num;
}

bool increasing(int l,size_t li,int r,size_t ri){
    return l < r;
}

bool rubik3(int num){
    if(num < 111 || num > 666)return false;
    if(num%10 == 0 || (num/10)%10 == 0)return false;
    return true;
}
bool rubik2(int num){
    if(num < 11 || num > 66)return false;
    if(num%10 == 0 || num/10 == 0)return false;
    return true;
}
bool rubik1(int num){
    if(num < 1 || num > 6)return false;
    return true;
}
bool rubik0(int num){
    return num == 0;
}

bool isRubiksCube(int cube[3][3][3]){
    static bool (*predicates[2][3][3])(int) = {
        {
            {rubik3,rubik2,rubik3},
            {rubik2,rubik1,rubik2},
            {rubik3,rubik2,rubik3}
        },
        {
            {rubik2,rubik1,rubik2},
            {rubik1,rubik0,rubik1},
            {rubik2,rubik1,rubik2}
        }
    };

    VectorInt* solo = VectorInt_init(0);
    VectorInt* duos = VectorInt_init(0);
    VectorInt* triplets = VectorInt_init(0);

    for(size_t z = 0;z < 3;++z){
        for(size_t y = 0;y < 3;++y){
            for(size_t x = 0;x < 3;++x){
                int num = cube[z][y][x];
                if(!predicates[z%2][y][x](num)){
                    return false;
                }
                else if(num < 7)VectorInt_push(solo,num);
                else if(num < 100)VectorInt_push(duos,num);
                else VectorInt_push(triplets,sortNumber(num));
            }
        }
    }

    //checking solo elements
    VectorInt_bubbleSort(solo,increasing);
    for(size_t i = 0;i < 7;++i){
        if(solo->data[i] != i){
            return false;
        }
    }

    MatrixInt* duos_check = MatrixInt_initMatrix(6,6); MatrixInt_fillMatrix(duos_check, 0);
    //check duos and extract opposites
    for(size_t i = 0;i < 12;++i){
        int l = duos->data[i] / 10 - 1;
        int r = (duos->data[i] % 10) - 1;
        ++duos_check->data[l].data[r];
        ++duos_check->data[r].data[l];
    }
    VectorInt_resize(solo,0);
    for(size_t r = 0;r < 6;++r){
        for(size_t c = 0;c < 6;++c){
            if(r != c && duos_check->data[r].data[c] == 0){
                VectorInt_push(solo,c);
            }
        }
    }
    if(solo->size != 6){
        return false;
    }
    VectorInt* copy = VectorInt_initCopy(solo);
    VectorInt_bubbleSort(copy,increasing);
    for(size_t i = 0;i < 6;++i){
        if(copy->data[i] != i)return false;
    }

    //checking triplets
    VectorInt* generated = VectorInt_init(0);
    for(size_t i = 0;i < 6;++i){
        for(size_t j = i+1;j < 6;++j){
            if(duos_check->data[i].data[j] == 0)continue;
            for(size_t k = j + 1;k < 6;++k){
                if(duos_check->data[i].data[k] == 0)continue;
                if(duos_check->data[j].data[k] == 0)continue;
                int num = sortNumber((i + 1)*100 + (j+1) * 10 + k+1);
                if(VectorInt_indexOf(generated,num,intEqual) == -1)VectorInt_push(generated, num);
            }
        }
    }
    VectorInt_bubbleSort(generated,increasing);
    VectorInt_bubbleSort(triplets,increasing);
    if(generated->size != 8)return false;

    for(size_t i = 0;i < 8;++i){
        if(generated->data[i] != triplets->data[i])return false;
    }

    return true;
}