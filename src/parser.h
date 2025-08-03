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



