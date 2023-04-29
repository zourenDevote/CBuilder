//
// Created by 20580 on 2023/4/28.
//

#ifndef CCODEBUILDER_CSTATEMENT_H
#define CCODEBUILDER_CSTATEMENT_H

#include "CSymbolTable.h"
#include "CBaseValue.h"
#include "CVariable.h"
#include "CExpr.h"


namespace ccb {
    ///> 语句部分
    class CStatement : CValue{
    public:
        CStatement(StmtID, CType*);
    public:
        virtual void dump(std::ostream &out = std::cout) = 0;

    public:
        void setParent(CStatement *parent);
        CStatement *getParent() { return parent; }

    public:
        StmtID getStmtId() const { return stmtId; }
        bool canCastTo(StmtID id) { return id == stmtId; }

    private:
        StmtID stmtId;
        CStatement* parent = nullptr;
    };

    class CDeclareStatement : public CStatement{
    public:
        CDeclareStatement(CVariable* var, CStatement* init = nullptr);
    public:
        void dump(std::ostream &out = std::cout) override;

        void setVar(CVariable* var) { this->var = var; }
        void setInitExpr(CStatement* expr) { this->initExpr = expr; }

        CVariable* getVar() const { return var; }
        CStatement* getInitExpr() const { return initExpr; }

    private:
        CVariable* var;             ///> 变量名
        CStatement* initExpr;       ///> 初始化表达式
    };

    class CAssignStatement : public CStatement {
    public:
        CAssignStatement(CVariableRef *ref, CStatement *assign);

    public:
        void dump(std::ostream &out = std::cout) override;

        void setVarRef(CVariableRef *r) { this->ref = r; }
        void setAssignStmt(CStatement *stmt) { this->assignExpr = stmt; }

        CVariableRef *getVarRef() const { return this->ref; }
        CStatement *getAssignStmt() const { return this->assignExpr; }
    private:
        CVariableRef    *ref;           ///> 引用的变量
        CStatement      *assignExpr;
    };

    class CScopeStatement : CStatement {
    public:
        CScopeStatement(CScopeStatement *parent = nullptr);
        ~CScopeStatement();
    public:
        CVariable *findSymbol(const std::string& name);
        void addSymbol(CVariable *var);
        void addStatement(CStatement *stmt);
    public:
        void dump(std::ostream &out = std::cout) override;
    public:
        static CScopeStatement* Create(CScopeStatement* parent = nullptr);

    private:
        CSymbolTable *symTab;                   ///> 作用域符号表
        std::vector<CStatement*> statements;    ///> 语句列表
    };

    class CExprStatement : CStatement {

    };

    class CForStatement : CStatement {
    public:
        CForStatement(CExpr *s1 = nullptr, CExpr *s2 = nullptr, CExpr *s3 = nullptr);
        void dump(std::ostream &out = std::cout) override;
    public:
        void setExpr1(CExpr *s1) { this->stmt1 = s1; }
        void setExpr2(CExpr *s2) { this->stmt2 = s2; }
        void setExpr3(CExpr *s3) { this->stmt3 = s3; }
        void setScopeStmt(CScopeStatement *stmt) { this->scopeStmt = stmt; }

        CExpr *getExpr1() const { return this->stmt1; }
        CExpr *getExpr2() const { return this->stmt2; }
        CExpr *getExpr3() const { return this->stmt3; }
        CScopeStatement *getScopeStmt() const { return scopeStmt; }
    public:
        CForStatement *Create(CExpr *s1 = nullptr, CExpr *s2 = nullptr, CExpr *s3 = nullptr);
    private:
        CExpr *stmt1;
        CExpr *stmt2;
        CExpr *stmt3;
        CScopeStatement *scopeStmt;
    };

    class CWhileStatement : CStatement {
    public:
        CWhileStatement(CExpr*, CScopeStatement*);
        void dump(std::ostream &out = std::cout) override;
    public:
        static CWhileStatement* Create(CExpr *, CScopeStatement *);

    public:
        void setCondExpr(CExpr* cond) { this->condExpr = cond; }
        void setScopeStmt(CScopeStatement *stmt) { this->scopeStmt = stmt; }
        CExpr *getCondExpr() const { return condExpr; }
        CScopeStatement *getScopeStmt() const { return scopeStmt; }
    private:
        CExpr* condExpr;
        CScopeStatement* scopeStmt;
    };

    class CCaseStatement : CStatement {};

    class CSwitchStatement : CStatement {
    public:
        CSwitchStatement(CExpr *cond);
        void dump(std::ostream &out = std::cout) override;
    public:
        void addCase(CCaseStatement *stmt);
        void setCond(CExpr *cond) { this->condExpr = cond; }
        void setDefaultStmt(CStatement *defaultSt) { this->defaultStmt = defaultSt; }

        CExpr *getCondExpr() const { return condExpr; }
        CCaseStatement *getCase(size_t index);
        CStatement *getDefaultStmt() const { return defaultStmt; }
    public:
        CSwitchStatement *Create(CExpr *cond);
    private:
        CExpr *condExpr;
        std::vector<CCaseStatement *> cases;
        CStatement *defaultStmt;
    };

    class CElseStatement : CStatement {
    public:
        CElseStatement(CStatement *stmt);
        void dump(std::ostream &out = std::cout) override;
    public:
        void setStatement(CStatement *stmt) { this->stmt = stmt; }

        CStatement *getStmt() const { return stmt; }
    public:
        static CElseStatement *Create(CStatement *stmt);

    private:
        CStatement *stmt;
    };

    class CIfStatement : CStatement {
    public:
        CIfStatement(CExpr* cond, CScopeStatement *scope);
        void dump(std::ostream &out = std::cout) override;
    public:
        static CIfStatement *Create(CExpr *cond, CScopeStatement *scope);

    public:
        void setCond(CExpr* cond) { this->condExpr = cond; }
        void setScopeStmt(CScopeStatement *stmt) { this->scopeStmt = stmt; }
        void setElseStmt(CElseStatement *stmt) { this->elseStmt = stmt; }

        CExpr *getExpr() { return condExpr; }
        CElseStatement *getElseStmt() { return elseStmt; }
        CScopeStatement *getScopeStmt() { return scopeStmt; }
    private:
        CExpr *condExpr;
        CElseStatement *elseStmt;
        CScopeStatement *scopeStmt;
    };
}

#endif //CCODEBUILDER_CSTATEMENT_H
