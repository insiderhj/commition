set ( CMAKE_CXX_STANDARD 11 )
SET ( TARGET Animals )
SET ( SRCS main.cpp animal.cpp )

ADD_EXECUTABLE( ${TARGET} ${SRCS} )