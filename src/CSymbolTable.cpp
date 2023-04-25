//
// Created by 20580 on 2023/4/25.
//

#include "CSymbolTable.h"
#include "CValue.h"

namespace ccb {
    void CSymbolTable::addSymbol(CVariable *var) {
        symMap.insert({var->getVarName(), var});
    }

    CVariable *CSymbolTable::getVar(const std::string &name) {
        if(symMap.find(name) != symMap.end())
            return symMap[name];
        return nullptr;
    }
}

