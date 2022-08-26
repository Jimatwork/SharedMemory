// SendCmd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <cstring>
#include <cstdlib>

#include <string>
int main(int argc, char* argv[])
{

    using namespace boost::interprocess;

     
       //Remove shared memory on construction and destruction
        struct shm_remove
        {
            shm_remove() { shared_memory_object::remove("CmdSharedMemory"); }
            ~shm_remove() { shared_memory_object::remove("CmdSharedMemory"); }
        } remover;

        //Create a shared memory object.
        shared_memory_object shm(create_only, "CmdSharedMemory", read_write);

        //Set size
        shm.truncate(100);

        //Map the whole shared memory in this process
        mapped_region region(shm, read_write);

        //Write all the memory to A
        char ch = 'A';
        std::memset(region.get_address(), ch, region.get_size());

    std::cout << "Command sent! Press a key to exit!\n";
    while (!getchar())
        {
            continue;
        }
    }

