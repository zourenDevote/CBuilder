//
// Created by 20580 on 2023/4/28.
//

#ifndef CCODEBUILDER_CCONSTANT_H
#define CCODEBUILDER_CCONSTANT_H

#include "CBaseValue.h"

namespace ccb {
    class Constant : public CValue {
        Constant(CType* ty);
    public:
        template<class T>
                T* getValue() { return *((T*)constValue); }
        void dump(std::ostream &out = std::cout) override;
    public:
        static CValue* Create(CType *ty, void* v);
    private:
        void* constValue;
    };
}

#endif //CCODEBUILDER_CCONSTANT_H
