set ( CMAKE_CXX_STANDARD 11 )
SET ( TARGET shapes )
SET ( SRCS main.cpp shape.cpp )

ADD_EXECUTABLE( ${TARGET} ${SRCS} )