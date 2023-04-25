//
// Created by 20580 on 2023/4/26.
//

#include "CModule.h"
#include "CValue.h"

using namespace ccb;

int main() {
    std::vector<CVariable*> args;
    args.push_back(CVariable::Create(CType::getIntTy(), "size"));
    args.push_back(CVariable::Create(CType::getPointerTy(CType::getIntTy()), "ptr"));
    FunctionType* funcTy = dynamic_cast<FunctionType*>(FunctionType::Create(CType::getVoidTy(), {args[0]->getType(), args[1]->getType()}));
    CFunction* func = CFunction::Create(funcTy, "quicksort", nullptr, args);
    func->dump();
}