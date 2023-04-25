//
// Created by 20580 on 2023/4/24.
//

#ifndef CCODEBUILDER_CSYMBOLTABLE_H
#define CCODEBUILDER_CSYMBOLTABLE_H

#include "CBType.h"
#include <map>


namespace ccb {
    class CVariable;

    class CSymbolTable {
    public:
        CSymbolTable() = default;
    public:
        void addSymbol(CVariable* var);
        CVariable* getVar(const std::string& name);
    private:
        std::map<std::string, CVariable*> symMap;
    };
}

#endif //CCODEBUILDER_CSYMBOLTABLE_H
