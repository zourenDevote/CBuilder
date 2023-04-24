//
// Created by 20580 on 2023/4/22.
//

#include "CBType.h"
#include <string>

namespace ccb {

    CType *CType::getVoidTy     () { return VoidType::Create(); }
    CType *CType::getCharTy     () { return CharType::Create(); }
    CType *CType::getUCharTy    () { return UCharType::Create(); }
    CType *CType::getShortTy    () { return ShortType::Create(); }
    CType *CType::getUShortTy   () { return UShortType::Create(); }
    CType *CType::getIntTy      () { return IntType::Create(); }
    CType *CType::getUIntTy     () { return UIntType::Create(); }
    CType *CType::getLongTy     () { return LongType::Create(); }
    CType *CType::getULongTy    () { return ULongType::Create(); }
    CType *CType::getBoolTy     () { return BoolType::Create(); }
    CType *CType::getDoubleTy   () { return DoubleType::Create(); }
    CType *CType::getFloatTy    () { return FloatType::Create(); }
    CType *CType::getArrayTy    (CType *elemTy, size_t size) { return ArrayType::Create(elemTy, size); }
    CType *CType::getPointerTy  (CType *pointeeTy) { return PointerType::Create(pointeeTy); }

    void CType::dump(std::ostream &out) { out << getCKeyWord() << " size: " << typeSize(); }
    /* void */
    CType *VoidType::Create() { return new VoidType(); }

    /* char */
    CType *CharType::Create() { return new CharType(); }

    /* unsigned char */
    CType *UCharType::Create() { return new UCharType(); }

    /* short */
    CType *ShortType::Create() { return new ShortType(); }

    /* unsigned short */
    CType *UShortType::Create() { return new UShortType(); }

    /* int */
    CType *IntType::Create() { return new IntType(); }

    /* unsigned int */
    CType *UIntType::Create() { return new UIntType(); }

    /* long */
    CType *LongType::Create() { return new LongType(); }

    /* unsigned long */
    CType *ULongType::Create() { return new ULongType(); }

    /* bool */
    CType *BoolType::Create() { return new BoolType(); }

    /* double */
    CType *DoubleType::Create() { return new DoubleType(); }

    /* float */
    CType *FloatType::Create() { return new FloatType(); }

    /* array */
    void ArrayType::dump(std::ostream &out) {
        out << "un support array type";
    }
    CType *ArrayType::Create(CType *elemTy, size_t size) { return new ArrayType(elemTy, size); }

    /* pointer */
    void PointerType::dump(std::ostream &out) { out << pointeeType->getCKeyWord() << "* size: " << typeSize(); }
    CType *PointerType::Create(CType *pointeeTy) { return new PointerType(pointeeTy); }

    /* struct */
    void StructType::dump(std::ostream &out) {
        out << "struct " << structName << "{\n";
        for(const auto& p : structElems) {
            out << "\t" << p.first->getCKeyWord() << " " << p.second << ";\n";
        }
        out << "};\n";
    }

    CType *StructType::Create(const std::string& name) { return new StructType(name); }

    size_t StructType::typeSize() {
        size_t sz = 0;
        for(const auto& p : structElems)
            sz += p.first->typeSize();
        return sz;
    }

    void StructType::addElemType(CType *ty, const std::string &name) {
        structElems.push_back({ty, name});
    }

    bool StructType::setElemType(CType *ty, size_t index, const std::string &name) {
        if (index >= structElems.size())
            return false;
        structElems[index].first = ty;
        if(name != "")
            structElems[index].second = name;
    }

    CType *StructType::getElemType(size_t index) {
        if(index >= structElems.size()) return nullptr;
        return structElems[index].first;
    }

    const std::string &StructType::getElemTypeName(size_t index) {
        if(index >= structElems.size()) return "";
        return structElems[index].second;
    }

    void FunctionType::dump(std::ostream &out) {
        out << retType->getCKeyWord();
        out << " (";
        size_t i = 0, size = argsTypes.size() - 1;
        for(auto type : argsTypes) {
            if(i < size) {
                out << type->getCKeyWord();
                out << ", ";
            }
            else
                out << type->getCKeyWord();
            i++;
        }
        out<<")";
    }

    CType *FunctionType::getTypeByIndex(size_t i) {
        if(i >= argsTypes.size())
            return nullptr;
        return argsTypes[i];
    }

    CType *FunctionType::Create(CType *ret, const std::vector<CType *> &args) {
        return new FunctionType(ret, args);
    }
}
