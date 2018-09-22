set( lib profiler )

set( CMAKE_INCLUDE_CURRENT_DIR ON )

set( HEADERS_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" )

set( HDRS
    ${HEADERS_ROOT}/Profiler.h
)

set( SRCS
    ${HEADERS_ROOT}/Profiler.cpp
)

add_library( ${lib} ${SRCS} ${HDRS} )

target_include_directories( ${lib} INTERFACE
    ${HEADERS_ROOT}
)
