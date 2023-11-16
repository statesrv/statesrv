set(SRC
    src/exception.hpp
    src/lexer.hpp
    src/lexer.cpp
    src/statelang.cpp
    src/token.hpp
)

add_library(statelang SHARED ${SRC})

set_target_properties(statelang PROPERTIES
    CXX_STANDARD          11
    CXX_STANDARD_REQUIRED ON
)

install(TARGETS statelang
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)
