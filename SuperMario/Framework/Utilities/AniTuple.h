#pragma once
#include <unordered_map>
#include <tuple>
#include "Animation.h"

// tuple < figure, state -- action, direction > 
typedef std::tuple<int, int, int> ANITUPLE;

struct key_hash : public std::unary_function<ANITUPLE, std::size_t>
{
    std::size_t operator()(const ANITUPLE& k) const
    {
        return std::get<0>(k) ^ std::get<1>(k) ^ std::get<2>(k);
    }
};

struct key_equal : public std::binary_function<ANITUPLE, ANITUPLE, bool>
{
    bool operator()(const ANITUPLE& v0, const ANITUPLE& v1) const
    {
        return (
            std::get<0>(v0) == std::get<0>(v1) &&
            std::get<1>(v0) == std::get<1>(v1) &&
            std::get<2>(v0) == std::get<2>(v1)
            );
    }
};

typedef std::unordered_map<ANITUPLE, LPANIMATION, key_hash, key_equal> ANISMAP;