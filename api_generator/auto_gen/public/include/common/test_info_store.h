// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from info.djinni

#pragma once

#include "sex_mode_enum.h"
#include <cstdint>
#include <string>
#include <utility>

namespace test { namespace hello {

struct TestInfoStore final {
    int32_t id;
    std::string name;
    std::string project;
    SexModeEnum sex;

    TestInfoStore(int32_t id_,
                  std::string name_,
                  std::string project_,
                  SexModeEnum sex_)
    : id(std::move(id_))
    , name(std::move(name_))
    , project(std::move(project_))
    , sex(std::move(sex_))
    {}
};

} }  // namespace test::hello
