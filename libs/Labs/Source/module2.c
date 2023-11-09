#include "..\Headers\module2.h"

void outputWCHAR(wchar_t x,size_t index){
    wprintf(L"%lc",x);
}

void outputWCHAR_X16(wchar_t x,size_t index){
    wprintf(L"0x%x, ",x);
}

void outputWCHAR_x10(wchar_t x,size_t index){
    wprintf(L"%d, ",x);
}

bool utfComparer(wchar_t l,wchar_t r){
    return l == r;
}

void task(){
    static wchar_t name_ua[] = L"Щегель Максим Володимирович";
    static wchar_t name_en[] = L"Shchehel Maksym Volodymyrovych";

    _setmode(_fileno(stdout), 0x20000);
    setlocale(LC_CTYPE, "");

//2.1
    VectorUTF* ua = VectorUTF_initData(name_ua,28);
    wprintf(L"2.1\n");
    wprintf(L"\tUA name = %ls\n",ua->data);
    wprintf(L"\tx16: ");
    VectorUTF_showVector(ua,outputWCHAR_X16);
    wprintf(L"\n\tx10: ");
    VectorUTF_showVector(ua,outputWCHAR_x10);
    wprintf(L"\n");
//2.2
    VectorUTF* en = VectorUTF_initData(name_en,31);
    wprintf(L"2.1\n");
    wprintf(L"\tEN name = %ls\n",en->data);
    wprintf(L"\tx16 :");
    VectorUTF_showVector(en,outputWCHAR_X16);
    wprintf(L"\n\tx10 :");
    VectorUTF_showVector(en,outputWCHAR_x10);
    wprintf(L"\n");
//2.3
//2.3.1
    wprintf(L"2.3.1\n");
    wprintf(L"\tConcated = ");
    VectorUTF* combined = VectorUTF_concat(ua,en);
    VectorUTF_showVector(combined,outputWCHAR);
    wprintf(L"\n");
//2.3.2
    wprintf(L"2.3.2\n");
    wprintf(L"\tCompare result: ");
    bool* result = VectorUTF_compare(ua,en,utfComparer);
    const size_t SIZE = max(ua->size,en->size);
    for(size_t i = 0;i < SIZE;++i){
        wprintf(L"%d",result[i]);
    }
    wprintf(L"\n");
//2.3.3
    wprintf(L"2.3.3\n");
    VectorUTF* copy_ua = VectorUTF_initCopy(ua);
    VectorUTF* copy_en = VectorUTF_initCopy(en);
    wprintf(L"\tUA copy = %ls;Prev addres = %p;Current addres = %p\n",copy_ua->data,&ua->data[0],&copy_ua->data[0]);
    wprintf(L"\tEN copy = %ls;Prev addres = %p;Current addres = %p\n",copy_en->data,&en->data[0],&copy_en->data[0]);
//2.3.4
    wprintf(L"2.3.4\n");
    wprintf(L"\tLength of UA = %d\n",ua->size);
    wprintf(L"\tLength of EN = %d\n",en->size);
//delete vectors
    VectorUTF_free(copy_ua);
    VectorUTF_free(copy_en);
    VectorUTF_free(ua);
    VectorUTF_free(en);
    VectorUTF_free(combined);
}