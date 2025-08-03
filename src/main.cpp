#include "cli.h"
#include "items.h"


int main(int argc, char** argv)
{
    dsp::items::init_item_lookup();
    dsp::items::initialize_recipes();
    dsp::cli::CLI parser_o(argc, argv);
    parser_o.parse();
    return 0;
}