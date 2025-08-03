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

#include <vector>
#include <string>

namespace parser
{

typedef std::string arg;
typedef std::vector<arg> cli_args_t;

// Performs deep copy
class Parser
{
    public:
    cli_args_t args;

    // Constructor
    Parser() = default;
    Parser(int argc, char** argv);

    // Destructor
    ~Parser() = default;

    // Check whether the parser has a specific flag (- and --)
    bool has_flag(const std::string& flag) const;

    // Returns all arguments that are not flags
    std::vector<std::string> get_positional_args() const;

    // Returns the argument descriptors that follow a given flag
    std::vector<std::string> get_positional_args(const std::string& flag) const;

};

} //namepsace parser



