#include <boost/thread.hpp>
#include <iostream>
#define MAX 5
 
void
thread_1 () {
        for (int i = 0; i < MAX; i++) {
                std::cout << "hello" << std::endl;
                boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
        }
}
void
thread_2 () {
        for (int i = 0; i < MAX; i++) {
                std::cout << "world" << std::endl;
                boost::this_thread::sleep(boost::posix_time::milliseconds(1000));
        }
}
 
int
main(int argc, char const* argv[])
{
        boost::thread th1(thread_1);
        boost::thread th2(thread_2);
 
        th1.join ();
        th2.join ();
 
        return 0;
}
