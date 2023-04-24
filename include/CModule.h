//
// Created by 20580 on 2023/4/24.
//

#ifndef CCODEBUILDER_CMODULE_H
#define CCODEBUILDER_CMODULE_H

#include "CBType.h"

#include <string>
#include <vector>
#include <iostream>

namespace ccb {

    class CFunction;
    class CGlobalVariable;

    class CModule {
    public:
        CModule(const std::string& name);
        ///> 输出到文件
        void dump(std::ostream& out = std::cout);
        ///> 添加依赖module
        void addIncludeCMod(CModule* mod);
        void addFunc(CFunction* func);
        void addGlobalVar(CGlobalVariable* global);
        CFunction* getOrInsertCFunc(FunctionType* functy, const std::string& name = "");
        CGlobalVariable* getOrInsertCGlobalVariable(CType* ty, const std::string& name = "");
    private:
        std::string moduleName;
        bool        isHeadFile;
        std::vector<CModule*>        includeMods;
        std::vector<CFunction*>      funcs;
        std::vector<CGlobalVariable> globalVariables;
    };
}

#endif //CCODEBUILDER_CMODULE_H
