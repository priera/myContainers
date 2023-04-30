file(GLOB my_SRC CONFIGURE_DEPENDS "*.h" "*.inl" "*.cpp")

add_library(my STATIC ${my_SRC})
set_target_properties(my PROPERTIES LINKER_LANGUAGE CXX)