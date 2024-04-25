// Implementation class ListUserFunction

// Copyright (C) 2023-2023 School 21 License

#include "list_user_function.h"

#include <cstddef>
#include <list>
#include <string>

#include "../user_function/user_function.h"

namespace s21 {

ListUserFunction::ListUserFunction() {}

ListUserFunction::~ListUserFunction() {}

// ------------------------------------------------------------------------- //

void ListUserFunction::Add(const UserFunction& var) { list_.push_back(var); }

bool ListUserFunction::Remove(const UserFunction& var) {
  return Remove(var.GetName());
}

bool ListUserFunction::Remove(const std::string& name) {
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

void ListUserFunction::Clear() { list_.clear(); }

// ------------------------------------------------------------------------- //

size_t ListUserFunction::Size() const { return list_.size(); }

UserFunction* ListUserFunction::Get(const UserFunction& var) {
  return Get(var.GetName());
}

UserFunction* ListUserFunction::Get(const std::string& name) {
  for (iterator iter = Begin(); iter != End(); ++iter) {
    if (iter->GetName() == name) return &(*iter);
  }

  return nullptr;
}

const UserFunction* ListUserFunction::Get(const UserFunction& var) const {
  return Get(var.GetName());
}

const UserFunction* ListUserFunction::Get(const std::string& name) const {
  for (const_iterator iter = Begin(); iter != End(); ++iter) {
    if (iter->GetName() == name) return &(*iter);
  }

  return nullptr;
}

// ------------------------------------------------------------------------- //

ListUserFunction::iterator ListUserFunction::Begin() { return list_.begin(); }

ListUserFunction::iterator ListUserFunction::End() { return list_.end(); }

ListUserFunction::const_iterator ListUserFunction::Begin() const {
  return list_.begin();
}

ListUserFunction::const_iterator ListUserFunction::End() const {
  return list_.end();
}

}  // namespace s21
