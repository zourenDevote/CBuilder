//
// Created by 20580 on 2023/4/28.
//

#ifndef CCODEBUILDER_CBASEVALUE_H
#define CCODEBUILDER_CBASEVALUE_H

#include "CBType.h"

namespace ccb {
    class CValue {
    public:
        CValue(CType* ty);
    public:
        CType* getType() const { return type; }
        virtual void dump(std::ostream& out = std::cout) = 0;
    private:
        CType* type;
    };
}

#endif //CCODEBUILDER_CBASEVALUE_H
