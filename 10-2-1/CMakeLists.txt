set ( CMAKE_CXX_STANDARD 11 )
SET ( TARGET clock_time )
SET ( SRCS main.cpp clocks.cpp clock_time.cpp )

ADD_EXECUTABLE( ${TARGET} ${SRCS} )