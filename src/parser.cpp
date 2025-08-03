// MIT License

// Copyright (c) 2025 kcExperts, Inc. All Rights Reserved.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "parser.h"

namespace parser
{

Parser::Parser(int argc, char** argv)
{
    for (size_t i = 0; i < argc; ++i)
        args.push_back(std::string(argv[i]));
}

bool Parser::has_flag(const std::string& flag) const
{
    for (size_t i = 1; i < args.size(); i++)
    {
        if (flag == args[i])
            return true;
    }
    return false;
};

std::vector<std::string> Parser::get_positional_args() const {
    std::vector<std::string> result;
    for (const auto& arg : args) {
        if (!arg.empty() && arg[0] != '-') {
            result.push_back(arg);
        }
    }
    return result;
}

std::vector<std::string> Parser::get_positional_args(const std::string& flag) const {
    std::vector<std::string> result;
    bool flag_found = false;
    size_t index = 1;
    for (; index < args.size(); index++)
    {
        if (args[index] == flag)
        {
            flag_found = true;
            break;
        }
    }
    if (!flag_found) return result;

    ++index; // Start after the flag

    for (; index < args.size(); ++index)
    {
        if (!args[index].empty() && args[index][0] == '-') break;
        result.push_back(args[index]);
    }
    return result;
}
} //namespace parser