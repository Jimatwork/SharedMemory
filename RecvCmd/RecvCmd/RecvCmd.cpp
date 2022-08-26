// RecvCmd.cpp :  
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>

int main()

{
    char strBuf[100];

    using namespace boost::interprocess;

    //Open already created shared memory object.
    shared_memory_object shm(open_only, "CmdSharedMemory", read_only);

    //Map the whole shared memory in this process
    mapped_region region(shm, read_only);

    //Check that memory was initialized to A
    char* mem;
    mem = (char*)(region.get_address());
    for (std::size_t i = 0; i < region.get_size(); ++i)
        strBuf[i]=*mem++;

  
    //strcpy_s(strBuf, mem);
    std::cout << strBuf;
    std::cout << " \nPress a key to exit!\n";
    while (!getchar())
    {
        continue;
    }
}

