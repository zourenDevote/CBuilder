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

}

#endif //CCODEBUILDER_CVALUE_H2
