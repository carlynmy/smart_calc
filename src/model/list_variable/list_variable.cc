// Implementation class ListVariable

// Copyright (C) 2023-2023 School 21 License

#include "list_variable.h"

#include <cstddef>
#include <list>
#include <string>

#include "../variable/variable.h"

namespace s21 {

ListVariable::ListVariable() {}

ListVariable::~ListVariable() {}

// -------------------------------------------------------------------------- //

void ListVariable::Add(const Variable& var) { list_.push_back(var); }

bool ListVariable::Remove(const Variable& var) { return Remove(var.GetName()); }

bool ListVariable::Remove(const std::string& name) {
  const_iterator iter = Begin();
  while (iter != End()) {
    if (iter->GetName() == name) {
      list_.erase(iter);
      return true;
    }
    ++iter;
  }

  return false;
}

void ListVariable::Clear() { list_.clear(); }

// -------------------------------------------------------------------------- //

size_t ListVariable::Size() const { return list_.size(); }

Variable* ListVariable::Get(const Variable& var) { return Get(var.GetName()); }

Variable* ListVariable::Get(const std::string& name) {
  for (iterator iter = Begin(); iter != End(); ++iter) {
    if (iter->GetName() == name) return &(*iter);
  }

  return nullptr;
}

const Variable* ListVariable::Get(const Variable& var) const {
  return Get(var.GetName());
}

const Variable* ListVariable::Get(const std::string& name) const {
  for (const_iterator iter = Begin(); iter != End(); ++iter) {
    if (iter->GetName() == name) return &(*iter);
  }

  return nullptr;
}

// -------------------------------------------------------------------------- //

ListVariable::iterator ListVariable::Begin() { return list_.begin(); }

ListVariable::iterator ListVariable::End() { return list_.end(); }

ListVariable::const_iterator ListVariable::Begin() const {
  return list_.begin();
}

ListVariable::const_iterator ListVariable::End() const { return list_.end(); }

}  // namespace s21
