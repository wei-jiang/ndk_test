
#include "common.h"

using namespace std;

std::shared_ptr<spdlog::logger> g_logger = spdlog::rotating_logger_mt("cpp_svr", "logs/cpp_svr.log", 1048576 * 2, 3);;
auto console = spdlog::stdout_color_mt("cpp_svr");
// auto file_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
// auto daily_logger = spdlog::daily_logger_mt("daily_logger", "logs/daily.txt", 2, 30);