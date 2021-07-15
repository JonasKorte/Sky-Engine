#pragma once
#include <iostream>
#define LOG(x) std::cout << x;
#define LOGN(x) std::cout << x << std::endl;
#define NL() std::cout << std::endl;
#define LOGINFO(x) std::cout << "INFO:" << x << std::endl;
#define LOGSUCCESS(x) std::cout << "SUCCESS: " << x << std::endl;
#define LOGWARN(x) std::cout << "WARNING: " << x << std::endl;
#define LOGERR(x) std::cerr << "ERROR: " << x << std::endl;
#define LOGFATAL(x) std::cerr << "FATAL: " << x << std::endl;