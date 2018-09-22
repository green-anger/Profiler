#include <sstream>

#include "Profiler.h"


using namespace alt;


int main( int argc, char** argv )
{
    Profiler profMain( "total time", true );

    { // block-1
        Profiler profBlock1( "block-1", true );

        for ( int i = 0; i < 1000000; ++i ) // 1M
            int n = i * i - i / 3;
    }

    { // block-2
        Profiler profBlock1( "block-2", true );

        for ( int i = 0; i < 1000000; ++i ) // 1M
            int n = i / 3 + i * 10 - i / 5 + 19;
    }

    for ( int k = 0; k < 19; ++k )
    {
        Profiler profOp( "operation" );

        for ( int i = 0; i < 1000000; ++i ) // 1M
            int n = i + i * i;
    }

    Profiler::printStatistics();

    std::ostringstream oss;
    Profiler::printStatistics( oss );
    std::cout << "Statistics from stream\n" << oss.str() << std::endl;

    return 0;
}
