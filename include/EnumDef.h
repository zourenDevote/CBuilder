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

    enum StmtID {
        AssignID,   /// T ==> a = b;                    赋值语句
        IfId,       /// T ==> if(cond) {...}            条件语句
        ElseId,     /// T ==> else {...}                条件语句
        ForId,      /// T ==> for(xxx;xxx;xxx) {...}    for循环语句
        WhileId,    /// T ==> while(xxx) {...}          while循环语句
        SwitchId,   /// T ==> switch(xxx) {...}         switch语句
        CaseId,     /// T ==> case: {...}               case语句
        CallId,     /// T ==> func(xxx)                 函数调用语句
        ExprId,     /// T ==> a + b                     表达式语句
    };

}

#endif //CCODEBUILDER_ENUMDEF_H
