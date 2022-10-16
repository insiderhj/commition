set ( CMAKE_CXX_STANDARD 11 )
SET ( TARGET integer_set )
SET ( SRCS main.cpp intset.cpp )

ADD_EXECUTABLE( ${TARGET} ${SRCS} )