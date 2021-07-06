#ifndef INCLUDE_BUILDER_HPP_
#define INCLUDE_BUILDER_HPP_

#include <async++.h>
#include <pthread.h>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/process.hpp>
#include <boost/program_options.hpp>
#include <future>
#include <iostream>
#include <string>

#include "process.hpp"

namespace po = boost::program_options;
using string = std::string;
using std::cout;
using std::endl;

const char error_mes[] =
    "**********BAD SYNTAX**********\n"
    "Look to --help or -h";

class Builder {
 public:
  static void create_program_options(po::options_description& desc,
                                     po::variables_map& vm, const int& argc,
                                     const char* argv[]);

  void start(const po::variables_map& vm);

  void init(const boost::log::trivial::severity_level& sev_lvl);

  boost::log::trivial::severity_level choose_sev_lvl(const string& sev_lvl_str);

  void settings_process(const po::variables_map& vm);

  bool run_process(const std::string& target, Process_info& process_info);

  ~Builder();

 private:
  Process* p_process;
};

#endif  // INCLUDE_BUILDER_HPP_
