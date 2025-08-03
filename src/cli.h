#include "parser.h"
#include "defines.h"
#include <map>
#include <stdexcept>
#include <optional>
#include <unordered_set>

namespace dsp
{
namespace cli
{

struct flag_arg
{
    std::optional<char> s_flag; //Short form flag, e.g. h
    std::optional<std::vector<std::string>> opt; // Valid positional argument for flag
    std::string desc; // Description of flag for help msg
};

typedef std::string flag;
typedef bool flag_t;

class CLI
{
    private:
        unsigned int depth = 0;
        flag_t use_mul_f = false;
        flag_t display_time_f = false;
        flag_t organize_f = false;
        flag_t use_per_min_f = false;
        amount_t per_min = 30;
        enum user_belt_f
        {
            NONE,
            MK1,
            MK2,
            MK3
        } belt_f = NONE;
        static constexpr int belt_mk1 = 360;
        static constexpr int belt_mk2 = 720;
        static constexpr int belt_mk3 = 1800;


        std::map<flag, flag_arg> flags;
        void format_option(const std::map<std::string, flag_arg>::const_iterator& it);
        void print_craft_base_recursive(const item_t* item, int indent = 0,
                                         std::unordered_set<const item_t*>* visited = nullptr,
                                         unsigned int current_depth = 0,
                                         unsigned int multiplier = 1);
        void accumulate_raw_materials(
            const item_t* item,
            double multiplier,
            std::unordered_map<const item_t*, double>& raw_materials,
            unsigned int depth,
            unsigned int& max_depth_reached,
            unsigned int current_depth = 0);

        void print_raw_materials(
            const std::unordered_map<const item_t*, unsigned int>& raw_materials);
    public:

    // Essentially utility function
    ::parser::Parser* parser;


    // Constructor
    CLI(int argc, char** argv);

    // Destructor
    ~CLI();
    // Note that "help" is already in
    void add_arg(std::string l_flag, std::optional<char> s_flag,
                 std::optional<std::vector<std::string>> opt, std::string desc);

    void print_help(); 
    void print_items();
    // Basic craft print
    void print_craft_base(std::string item);
    // Usefull one
    void print_organized(const std::string& item_name);
    
    void parse();
    

};

} // namespace cli
} // namespace dsp
