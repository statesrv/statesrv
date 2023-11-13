set(SRC
    src/lexer.hpp
    src/lexer.cpp
    src/statelang.cpp
    src/token.hpp
)

add_library(statelang SHARED ${SRC})

install(TARGETS statelang
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)
