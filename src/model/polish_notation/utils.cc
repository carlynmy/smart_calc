// Implementation utils methods class PolishNotation
// Include GetTypeTokenSeq

// Copyright (C) 2023-2023 School 21 License

#include "../token/token.h"
#include "polish_notation.h"

namespace s21 {

PolishNotation::TypeTokenSeq PolishNotation::GetTypeTokenSeq(const Token& a,
                                                             const Token& b) {
  if (a.IsSpecialToken() && a.GetSpecialToken()->IsEqualSign())
    return kSeqInvalid;
  if (b.IsSpecialToken() && b.GetSpecialToken()->IsEqualSign())
    return kSeqInvalid;
  if (a.IsSpecialToken() && a.GetSpecialToken()->IsOpenBracket() &&
      b.IsSpecialToken() && b.GetSpecialToken()->IsCloseBracket())
    return kSeqBracketCloseImmediately;

  if (a.IsOper() && a.GetOperation()->IsPrefix() &&
      a.GetOperation()->GetOperandCount() == 0 && b.IsSpecialToken() &&
      b.GetSpecialToken()->IsOpenBracket())
    return kSeqOpenBracketAfterZeroParamFunc;

  bool a_num_end =
      (a.IsNum() || a.IsVar() ||
       (a.IsSpecialToken() && a.GetSpecialToken()->IsCloseBracket()) ||
       (a.IsOper() && a.GetOperation()->IsPostfix()) ||
       (a.IsOper() && a.GetOperation()->IsPrefix() &&
        a.GetOperation()->GetOperandCount() == 0));

  bool a_need_num_start =
      (a.IsNull() ||
       (a.IsSpecialToken() && a.GetSpecialToken()->IsOpenBracket()) ||
       (a.IsSpecialToken() && a.GetSpecialToken()->IsOperandDelimetr()) ||
       (a.IsOper() && a.GetOperation()->IsInfix()) ||
       (a.IsOper() && a.GetOperation()->IsPrefix() &&
        a.GetOperation()->GetOperandCount() > 0));

  bool b_num_start =
      (b.IsNum() || b.IsVar() ||
       (b.IsSpecialToken() && b.GetSpecialToken()->IsOpenBracket()) ||
       (b.IsOper() && b.GetOperation()->IsPrefix()));

  if (a_num_end && b_num_start) return kSeqNeedMult;
  if (a_need_num_start && !b_num_start) return kSeqInvalid;

  return kSeqValid;
}

}  // namespace s21
