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
        FuncPtrTy
    };

}

#endif //CCODEBUILDER_ENUMDEF_H
