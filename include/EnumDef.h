//
// Created by 20580 on 2023/4/22.
//

#ifndef CCODEBUILDER_ENUMDEF_H
#define CCODEBUILDER_ENUMDEF_H

namespace ccb {

    ///> C语言的Type ID
    enum CCbTypeId {
        /* 基本类型 */
        VoidTy,
        CharTy,
        UCharTy,
        ShortTy,
        UShortTy,
        IntTy,
        UIntTy,
        LongTy,
        ULongTy,
        BoolTy,
        DoubleTy,
        FloatTy,
        /* 数组类型 */
        ArrayTy,
        /* 指针类型 */
        PointerTy,
        /* 结构体类型 */
        StructTy,
        /* 枚举类型 */
        EnumTy,
        /* 函数指针类型 */
        FuncPtrTy,
        /* 函数类型 */
        FuncTy
    };

    enum OperatorID {
        OpAdd,      /// T ==> +
        OpSub,      /// T ==> -
        OpDiv,      /// T ==> /
        OpMul,      /// T ==> *
        OpGt,       /// T ==> >
        OpGe,       /// T ==> >=
        OpLt,       /// T ==> <
        OpLe,       /// T ==> <=
        OpRm,       /// T ==> >>
        OpLm,       /// T ==> <<
        OpEq,       /// T ==> ==
        OpNe,       /// T ==> !=
        OpBitAnd,   /// T ==> &
        OpBitOr,    /// T ==> |
        OpBitNot,   /// T ==> !
        OpAnd,      /// T ==> &&
        OpOr,       /// T ==> ||
        OpBitEor,   /// T ==> ^
    };

}

#endif //CCODEBUILDER_ENUMDEF_H
