//
// Created by 20580 on 2023/4/22.
//
#include "CBType.h"
#include <iostream>

using namespace ccb;
using namespace std;

static int testIndex = 0;

static void test(CType* tp, const std::string& ty) {
    cout << "=================================\n";
    cout << ++testIndex << ". test type " << ty << "\n";
    cout << ">>>>>>>>: ";
    tp->dump(cout);
    cout << "\n";
    if(tp->getCKeyWord() == ty)
        cout << "PASSED\n";
    else
        cout << "FAILED\n";
    cout << "=================================\n";
}

int main() {
    CType* tp;
    /* void type test */

    tp = CType::getVoidTy();
    test(tp, "void");
    delete tp;

    tp = CType::getCharTy();
    test(tp, "char");
    delete tp;

    tp = CType::getUCharTy();
    test(tp, "unsigned char");
    delete tp;

    tp = CType::getShortTy();
    test(tp, "short");
    delete tp;

    tp = CType::getUShortTy();
    test(tp, "unsigned short");
    delete tp;

    tp = CType::getIntTy();
    test(tp, "int");
    delete tp;

    tp = CType::getUIntTy();
    test(tp, "unsigned int");
    delete tp;

    tp = CType::getLongTy();
    test(tp, "long");
    delete tp;

    tp = CType::getULongTy();
    test(tp, "unsigned long");
    delete tp;

    tp = CType::getBoolTy();
    test(tp, "bool");
    delete tp;

    tp = CType::getDoubleTy();
    test(tp, "double");
    delete tp;

    tp = CType::getFloatTy();
    test(tp, "float");
    delete tp;

    tp = CType::getPointerTy(CType::getIntTy());
    test(tp, "int*");
    delete tp;

    StructType* st = dynamic_cast<StructType*>(StructType::Create("A"));
    st->addElemType(CType::getBoolTy(), "triggle");
    st->addElemType(CType::getIntTy(), "count");
    st->addElemType(CType::getPointerTy(st), "next");
    st->dump(cout);
}