//
// Created by 20580 on 2023/4/22.
//

#ifndef CCODEBUILDER_CTYPE_H
#define CCODEBUILDER_CTYPE_H

#include "EnumDef.h"

#include <iostream>
#include <string>
#include <vector>

namespace ccb{
    class VoidType;
    class CharType;
    class UCharType;
    class ShortType;
    class UShortType;
    class IntType;
    class UIntType;
    class LongType;
    class ULongType;
    class BoolType;
    class DoubleType;
    class FloatType;
    class ArrayType;
    class PointerType;
    class StructType;
    class FunctionType;
//    class EnumType;
//    class FuncPtrType;

    class CType{
    private:
        CCbTypeId typeId;
        // 类型的C关键字
        std::string typeKeyWord;
        CCbTypeId getTypeId() const { return typeId; }
    public:
        CType(CCbTypeId id, const std::string& keyword) : typeId(id), typeKeyWord(keyword) {}
//        ~CType() = delete;
        /* cast 相关 */
        bool canCastTo(CCbTypeId id) { return id == typeId; }

        /* 打印 */
        virtual void dump(std::ostream& out = std::cout);
        /* sizeof */
        virtual size_t typeSize() = 0;
        virtual CType* getPointeeType() { return nullptr; }
        virtual CType* getElementType() { return nullptr; }
    public:
        bool isVoidTy   () { return typeId == VoidTy; }
        bool isCharTy   () { return typeId == CharTy; }
        bool isUCharTy  () { return typeId == UCharTy; }
        bool isShortTy  () { return typeId == ShortTy; }
        bool isUShortTy () { return typeId == UShortTy; }
        bool isIntTy    () { return typeId == IntTy; }
        bool isUIntTy   () { return typeId == UIntTy; }
        bool isLongTy   () { return typeId == LongTy; }
        bool isULongTy  () { return typeId == ULongTy; }
        bool isBoolTy   () { return typeId == BoolTy; }
        bool isDoubleTy () { return typeId == DoubleTy; }
        bool isFloatTy  () { return typeId == FloatTy; }
        bool isPointerTy() { return typeId == PointerTy; }
        bool isStructTy () { return typeId == StructTy; }
        bool isEnumTy   () { return typeId == EnumTy; }
        bool isArrayTy  () { return typeId == ArrayTy; }
        bool isFuncPtrTy() { return typeId == FuncPtrTy; }
    public:
        const std::string& getCKeyWord() const { return typeKeyWord; }
        void setTypeKeyWord(const std::string& keyword) { typeKeyWord = keyword; }
    public:
        static CType* getVoidTy     ();
        static CType* getCharTy     ();
        static CType* getUCharTy    ();
        static CType* getShortTy    ();
        static CType* getUShortTy   ();
        static CType* getIntTy      ();
        static CType* getUIntTy     ();
        static CType* getLongTy     ();
        static CType* getULongTy    ();
        static CType* getBoolTy     ();
        static CType* getDoubleTy   ();
        static CType* getFloatTy    ();
        static CType* getArrayTy    (CType* elemTy, size_t size);
        static CType* getPointerTy  (CType* pointeeTy);
    };

    ////////////////////////////////////////////////////////////////////////
    //// C语言void类型
    class VoidType : public CType {
    private:
        VoidType() : CType(VoidTy, "void") {};
    public:
        size_t typeSize() override { return 0; };
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言char类型
    class CharType : public CType {
    private:
        CharType() : CType(CharTy, "char") {};
    public:
        size_t typeSize() override { return sizeof(char); }
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言unsigned char类型
    class UCharType : public CType {
    private:
        UCharType() : CType(UCharTy, "unsigned char") {};
    public:
        size_t typeSize() override { return sizeof(unsigned char); }
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言short类型
    class ShortType : public CType {
    private:
        ShortType() : CType(ShortTy, "short") {};
    public:
        size_t typeSize() override { return sizeof(short); }
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言unsigned short类型
    class UShortType : public CType {
    private:
        UShortType() : CType(UShortTy, "unsigned short") {};
    public:
        size_t typeSize() override { return sizeof(unsigned short); }
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言int类型
    class IntType : public CType {
    private:
        IntType() : CType(IntTy, "int") {};
    public:
        size_t typeSize() override { return sizeof(int); }
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言unsigned int类型
    class UIntType : public CType {
    private:
        UIntType() : CType(UIntTy, "unsigned int") {};
    public:
        size_t typeSize() override { return sizeof(unsigned int); }
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言long类型
    class LongType : public CType {
    private:
        LongType() : CType(LongTy, "long") {};
    public:
        size_t typeSize() override { return sizeof(long); }
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言unsigned long类型
    class ULongType : public CType {
    private:
        ULongType() : CType(ULongTy, "unsigned long") {};
    public:
        size_t typeSize() override { return sizeof(unsigned long); }
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言bool类型
    class BoolType : public CType {
    private:
        BoolType() : CType(BoolTy, "bool") {};
    public:
        size_t typeSize() override { return sizeof(bool); }
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言double类型
    class DoubleType : public CType {
    private:
        DoubleType() : CType(DoubleTy, "double") {};
    public:
        size_t typeSize() override { return sizeof(double); }
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言float类型
    class FloatType : public CType {
    private:
        FloatType() : CType(FloatTy, "float") {};
    public:
        size_t typeSize() override { return sizeof(float); }
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言数组类型
    class ArrayType : public CType {
    private:
        ArrayType(CType* elemTy, size_t size) : CType(ArrayTy, elemTy->getCKeyWord()), elementTy(elemTy), arraySize(size) {};
    public:
        size_t typeSize() override { return arraySize * elementTy->typeSize(); }
        void dump(std::ostream &out = std::cout) override;
        CType * getElementType() override { return elementTy; }
    public:
        static CType* Create(CType* elemTy, size_t size);
    private:
        CType* elementTy;
        size_t arraySize;
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言指针类型
    class PointerType : public CType {
    private:
        PointerType(CType* pointeeTy) : CType(PointerTy, pointeeTy->getCKeyWord() + "*"), pointeeType(pointeeTy) {};
    public:
        size_t typeSize() override { return sizeof(void*); }
        void dump(std::ostream &out = std::cout) override;
    public:
        static CType* Create(CType* pointeeTy);

    private:
        CType* pointeeType;
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言结构体类型
    class StructType : public CType {
    private:
        StructType(const std::string& name) : CType(StructTy, "struct " + name), structName(name){};
    public:
        size_t typeSize() override;
        void dump(std::ostream &out = std::cout) override;
    public:
        void addElemType(CType* ty, const std::string& name);
        void setStructName(const std::string& name) { structName = name; }
        const std::string & getStructName() const { return structName; }
        bool setElemType(CType* ty, size_t index, const std::string& name = "");
        CType* getElemType(size_t index);
        const std::string& getElemTypeName(size_t index);
    public:
        static CType* Create(const std::string& name);

    private:
        std::vector<std::pair<CType*, std::string>> structElems;
        std::string structName;
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言函数类型
    class FunctionType : public CType {
    public:
        typedef std::vector<CType*>::iterator arg_iterator;
    private:
        FunctionType(CType *ret, const std::vector<CType *> &args) : CType(FuncTy, ""), retType(ret), argsTypes(args) {};
    public:
        size_t typeSize() override { return 0; }
        void dump(std::ostream &out = std::cout) override;
    public:
        CType* getRetType() const { return retType; }
        arg_iterator arg_begin() { return argsTypes.begin(); }
        arg_iterator arg_end() { return argsTypes.end(); }

        CType* getTypeByIndex(size_t i);
    public:
        static CType* Create(CType* ret, const std::vector<CType*>& args);
    private:
        std::vector<CType*> argsTypes;
        CType* retType;
    };
    ////////////////////////////////////////////////////////////////////////
}

#endif //CCODEBUILDER_CTYPE_H
