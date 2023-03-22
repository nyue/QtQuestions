#include "util.h"
#include <iostream>
#include <boost/format.hpp>
#include <boost/dll/runtime_symbol_info.hpp>
#include <boost/filesystem.hpp>

int myfunction() {
    boost::filesystem::path prog_loc = boost::dll::program_location();
    boost::filesystem::path default_plugin_dir = prog_loc.parent_path();

	std::cout << boost::format("myfunction() called from '%1%'") % prog_loc.parent_path() << std::endl;
	int i=42;
	return i;
}
