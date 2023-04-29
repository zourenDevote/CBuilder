//
// Created by 20580 on 2023/4/28.
//

#ifndef CCODEBUILDER_CVARIABLE_H
#define CCODEBUILDER_CVARIABLE_H

#include "CBaseValue.h"

namespace ccb {

    class CVariable {
    public:
        CVariable(CType* ty, const std::string& name);
        CType* getType() const { return varTy; }
        const std::string& getVarName() const { return varName; }
    public:
        static CVariable* Create(CType* ty, const std::string& name);
        void dump(std::ostream& out = std::cout);
    private:
        CType* varTy;
        std::string varName;
    };

    class CGlobalVariable : public CVariable{
    public:
        CGlobalVariable(CType* ty, const std::string& name);
    };

    class CVariableRef : public CValue {

    };
}

#endif //CCODEBUILDER_CVARIABLE_H
