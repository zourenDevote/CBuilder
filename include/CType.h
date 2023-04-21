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
    class EnumType;
    class FuncPtrType;

    class CType{
    private:
        CCbTypeId typeId;

        CCbTypeId getTypeId() const { return typeId; }
    public:
        CType(CCbTypeId id);
        ~CType() = delete;
        /* cast 相关 */
        bool canCastTo(CCbTypeId id) { return id == typeId; }

        /* 打印 */
        virtual void dump(std:::std::ostream& out = std::cout) = 0;
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
        static CType* getArrayTy    (CType* elemTy, size_t size);
        static CType* getPointerTy  (CType* pointeeTy);
    };

    ////////////////////////////////////////////////////////////////////////
    //// C语言void类型
    class VoidType : public CType {
    private:
        VoidType() : CType(VoidTy) {};
        ~VoidType() = delete;
    public:
        size_t typeSize() override { return sizeof(void); }
        void dump() override;
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言char类型
    class CharType : public CType {
    private:
        CharType() : CType(CharTy) {};
        ~CharType() = delete;
    public:
        size_t typeSize() override { return sizeof(char); }
        void dump() override;
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言unsigned char类型
    class UCharType : public CType {
    private:
        UCharType() : CType(UCharTy) {};
        ~UCharType() = delete;
    public:
        size_t typeSize() override { return sizeof(unsigned char); }
        void dump() override;
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言short类型
    class ShortType : public CType {
    private:
        ShortType() : CType(ShortTy) {};
        ~ShortType() = delete;
    public:
        size_t typeSize() override { return sizeof(short); }
        void dump() override;
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言unsigned short类型
    class UShortType : public CType {
    private:
        UShortType() : CType(UShortTy) {};
        ~UShortType() = delete;
    public:
        size_t typeSize() override { return sizeof(unsigned short); }
        void dump() override;
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言int类型
    class IntType : public CType {
    private:
        IntType() : CType(IntTy) {};
        ~IntType() = delete;
    public:
        size_t typeSize() override { return sizeof(int); }
        void dump() override;
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言unsigned int类型
    class UIntType : public CType {
    private:
        UIntType() : CType(UIntTy) {};
        ~UIntType() = delete;
    public:
        size_t typeSize() override { return sizeof(unsigned int); }
        void dump() override;
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言long类型
    class LongType : public CType {
    private:
        LongType() : CType(LongTy) {};
        ~LongType() = delete;
    public:
        size_t typeSize() override { return sizeof(long); }
        void dump() override;
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言unsigned long类型
    class ULongType : public CType {
    private:
        ULongType() : CType(ULongTy) {};
        ~ULongType() = delete;
    public:
        size_t typeSize() override { return sizeof(unsigned long); }
        void dump() override;
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言bool类型
    class BoolType : public CType {
    private:
        BoolType() : CType(BoolTy) {};
        ~BoolType() = delete;
    public:
        size_t typeSize() override { return sizeof(bool); }
        void dump() override;
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言double类型
    class DoubleType : public CType {
    private:
        DoubleType() : CType(DoubleTy) {};
        ~DoubleType() = delete;
    public:
        size_t typeSize() override { return sizeof(double); }
        void dump() override;
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言float类型
    class FloatType : public CType {
    private:
        FloatType() : CType(FloatTy) {};
        ~FloatType() = delete;
    public:
        size_t typeSize() override { return sizeof(float); }
        void dump() override;
    public:
        static CType* Create();
    };
    ////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //// C语言数组类型
    class ArrayType : public CType {
    private:
        ArrayType(CType* elemTy, size_t size) : CType(ArrayTy), elementTy(elemTy), arraySize(size) {};
        ~ArrayType() = delete;
    public:
        size_t typeSize() override { return size * elementTy->typeSize(); }
        void dump() override;
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
        PointerType(CType* pointeeTy) : CType(PointerTy), pointeeType(pointeeTy) {};
        ~PointerType() = delete;
    public:
        size_t typeSize() override { return sizeof(void*); }
        void dump() override;
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
        StructType(const std::string& name) : CType(StructTy), structName(name){};
        ~PointerType() = delete;
    public:
        size_t typeSize() override;
        void dump() override;
    public:
        void addType(CType* ty, const std::string& name);
        void setStructName(const std::string& name) { structName = name; }
        const std::string & getStructName() const { return structName; }
        void setType(CType* ty, size_t index, const std::string& name = "");
        CType* getType(size_t index);
        const std::string& getTypeName(size_t index);
    public:
        static CType* Create();

    private:
        std::vector<std::pair<CType*, std::string>> structElems;
        std::string structName;
    };
    ////////////////////////////////////////////////////////////////////////
}

#endif //CCODEBUILDER_CTYPE_H
