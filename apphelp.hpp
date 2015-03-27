#pragma once
#include "apphelp.h"
#include <map>
#include <string>
#include <boost/utility/string_ref.hpp>

extern std::map<boost::string_ref, TAG>  TAGs;
TAG FindTagByStr(const std::string&);