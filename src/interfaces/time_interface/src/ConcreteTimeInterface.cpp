#include "interfaces/time_interface/ConcreteTimeInterface.hpp"
#include <stdio.h>
#include <errno.h>
#include <linux/unistd.h>       /* for _syscallX macros/related stuff */
#include <linux/kernel.h>       /* for struct sysinfo */
#include <sys/sysinfo.h>

interfaces::TimePoint interfaces::ConcreteTimeInterface::actualTime()
{
    return std::chrono::system_clock::now();
}

interfaces::TimePoint interfaces::ConcreteTimeInterface::startTime()
{
    struct sysinfo s_info;
    int error = sysinfo(&s_info);
    if(error != 0)
    {
      printf("code error = %d\n", error);
    }
    return actualTime() - std::chrono::seconds{s_info.uptime};
}
