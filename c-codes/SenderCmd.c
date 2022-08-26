// SenderCmd.cpp : 
//

#include <iostream>
#include "sender.h"

int main()
{
    int ret;

    sender S;

    ret= S.cmdSend(1);
   
    std::cout << "Commands sent!\n";
}

