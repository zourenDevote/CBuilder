//
// Created by 20580 on 2023/4/24.
//

#ifndef CCODEBUILDER_CVALUE_H
#define CCODEBUILDER_CVALUE_H

#include "CBType.h"
#include "CSymbolTable.h"

namespace ccb {
    class CModule;
    class CScope;
    class CVariable;

    ///> 语句部分
    class CStatement{};
    class CDeclareStatement;/// T ==> example: int a
//    class CAssignStatement; /// T ==> example: a = b
//    class CExprStatement;   /// T ==> example: a + b
//    class CForStatement;    /// T ==> example: for(int i = 0 ; i < 10 ; i++) {...}
//    class CWhileStatement;  /// T ==> example: while(i < xxx) {...}
//    class CSwitchStatement; /// T ==> example: switch(xxx) case:{...} case:{...} default:{...}
//    class CIfStatement;     /// T ==> example: if(xxx) {...}
//    class CElseStatement;   /// T ==> example: else {...}
//    class CCondStatement;   /// T ==> example: a == 0?1:0;


    class CFunction {
    public:
        typedef std::vector<CVariable*>::iterator arg_var_iterator;

        CFunction(FunctionType* functy, const std::string& name, CModule* parent, const std::vector<CVariable*>& args);
        void dump(std::ostream& out = std::cout);

    public:
        void setExtern(bool ext) { isExtern = ext; }
        bool getExtern() const { return isExtern; }

        void setModule(CModule* mod) { parent = mod; }
        CModule* getModule() const { return parent; }

        void setFuncName(const std::string& name) { funcName = name; }
        const std::string& getFuncName() const { return funcName; }

        void setFuncType(FunctionType* functy) { funcTy = functy; }
        FunctionType* getFuncType() const { return funcTy; }

        void setFuncScope(CScope* scope) {
            if(scope) {
                funcScope = scope;
                setExtern(false);
            }
        }
        CScope* getFuncScope() const { return funcScope; }

        const std::vector<CVariable*>& getArgs() const { return argVars; }
        CVariable* getArg(size_t index);
        arg_var_iterator begin() { return argVars.begin(); }
        arg_var_iterator end() { return argVars.end(); }

    public:
        static CFunction* Create(FunctionType* funcTy, const std::string& name, CModule* parent = nullptr, const std::vector<CVariable*>& args = {});
    private:
        bool isExtern;                   ///> 是否是extern
        CModule* parent;                 ///> 父module
        CScope* funcScope;               ///> 函数作用域
        std::string funcName;            ///> 函数名
        FunctionType* funcTy;            ///> 函数类型
        std::vector<CVariable*> argVars; ///> 形参列表
    };

    class CScope{
    public:
        CScope(CScope *parent = nullptr);
        ~CScope();
        CVariable *findSymbol(const std::string& name);
        void addSymbol(CVariable *var);
        void addStatement(CStatement *stmt);
        void dump(std::ostream& out = std::cout);
    public:
        static CScope* Create(CScope* parent = nullptr);
    private:
        CSymbolTable *symTab;                   ///> 作用域符号表
        CScope *parentScope;                    ///> 父作用域
        std::vector<CStatement*> statements;    ///> 语句列表
    };

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

}

#endif //CCODEBUILDER_CVALUE_H2
