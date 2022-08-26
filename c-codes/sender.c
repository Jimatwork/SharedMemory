#include "sender.h"
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <cstring>

int  sender::cmdSend(char* argv[])
{
    
    using namespace boost::interprocess;

    //Create a native windows shared memory object.
    windows_shared_memory shm(create_only, "SharedCmd", read_write, 1000);

    //Map the whole shared memory in this process
    mapped_region region(shm, read_write);

    char Ch = 'A';
    //Write all the memory to A
    std::memset(region.get_address(), Ch, region.get_size());

    //Launch child process
    std::string s(argv[0]); s += " child ";
    if (0 != std::system(s.c_str()))
        return 1;
    //windows_shared_memory is destroyed when the last attached process dies...
}