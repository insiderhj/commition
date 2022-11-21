SET ( CMAKE_CXX_STANDARD 11 )
SET ( TARGET MyVector )
SET ( SRCS main.cpp my_vector2.cpp )

ADD_EXECUTABLE( ${TARGET} ${SRCS} )