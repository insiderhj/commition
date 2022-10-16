set ( CMAKE_CXX_STANDARD 11 )
SET ( TARGET simple_int_set )
SET ( SRCS main.cpp setfunc.cpp )

ADD_EXECUTABLE( ${TARGET} ${SRCS} )