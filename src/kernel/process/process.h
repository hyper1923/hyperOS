#pragma once
#include "../../lib/iostream.h"
#include "../memory/memory.h"


class Process{
public:
    virtual void Init() = nullptr;
    virtual void Loop() = nullptr;
};