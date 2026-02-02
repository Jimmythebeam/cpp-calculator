#pragma once

#include <string>

using Number = double;

bool ReadNumber(Number& result);

bool SaveLoad(const std::string& oper, Number& store, Number& result, bool& was_stored);

bool RunCalculatorCycle();
