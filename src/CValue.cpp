//
// Created by 20580 on 2023/4/25.
//

#include "CValue.h"

namespace ccb {

    ///////////////////////////////////////////////////////////
    ///CFunction
    ///========================================================
    CFunction::CFunction(FunctionType *functy, const std::string &name, CModule *parent,
                         const std::vector<CVariable*> &args) :
                         funcTy(functy), funcName(name), parent(parent), argVars(args){
        this->funcScope = nullptr;
        this->isExtern = true;
    }

    void CFunction::dump(std::ostream &out) {
        unsigned index = 0, size = argVars.size() - 1;
        if(isExtern)
            out << "extern ";
        out << funcTy->getRetType()->getCKeyWord() << " ";
        out << funcName << "(";
        for(auto* arg : argVars) {
            out << arg->getType()->getCKeyWord() << " " << arg->getVarName();
            if(index < size)
                out << ", ";
            index++;
        }
        out << ")";
        if(isExtern)
            out << ";\n";
        else
            funcScope->dump(out);
    }

    CVariable *CFunction::getArg(size_t index) {
        if(index >= argVars.size())
            return nullptr;
        return argVars[index];
    }

    CFunction *CFunction::Create(FunctionType *funcTy, const std::string &name, CModule *parent,
                                 const std::vector<CVariable *> &args) {
        return new CFunction(funcTy, name, parent, args);
    }
    ///========================================================

    ///////////////////////////////////////////////////////////
    ///CScope
    ///========================================================
    CScope::CScope(CScope *parent) : parentScope(parent) {
        this->symTab = new CSymbolTable();
    }

    CScope::~CScope() { delete this->symTab; this->symTab = nullptr; }

    CVariable *CScope::findSymbol(const std::string &name) {
        CVariable* var = this->symTab->getVar(name);
        if(var)
            return var;
        if(parentScope)
            return parentScope->findSymbol(name);
        return nullptr;
    }

    void CScope::addSymbol(CVariable *var) {
        this->symTab->addSymbol(var);
    }

    void CScope::addStatement(CStatement *stmt) {
        statements.push_back(stmt);
    }

    void CScope::dump(std::ostream &out) {}

    CScope *CScope::Create(CScope *parent) { return new CScope(parent); }
    ///========================================================

    ///////////////////////////////////////////////////////////
    ///CVariable
    ///========================================================
    CVariable::CVariable(CType *ty, const std::string &name) : varTy(ty), varName(name) {}

    void CVariable::dump(std::ostream &out) {}

    CVariable *CVariable::Create(CType *ty, const std::string &name) { return new CVariable(ty, name); }
    ///========================================================

    ///////////////////////////////////////////////////////////
    ///CGlobalVariable
    ///========================================================
    CGlobalVariable::CGlobalVariable(CType *ty, const std::string &name) : CVariable(ty, name) {}
    ///========================================================
}


