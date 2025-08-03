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