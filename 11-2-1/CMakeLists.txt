SET ( CMAKE_CXX_STANDARD 11 )
SET ( TARGET MyVector )
SET ( SRCS main.cpp my_vector.cpp )

ADD_EXECUTABLE( ${TARGET} ${SRCS} )