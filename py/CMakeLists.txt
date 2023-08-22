if(MSVC)
    add_definitions(-DFCAbbRobot -DHAVE_ACOSH -DHAVE_ASINH -DHAVE_ATANH)
else(MSVC)
    add_definitions(-DHAVE_LIMITS_H -DHAVE_CONFIG_H)
endif(MSVC)



include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
    ${OCC_INCLUDE_DIR}
    ${EIGEN3_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${ZLIB_INCLUDE_DIR}
    ${XercesC_INCLUDE_DIRS}
)
link_directories(${OCC_LIBRARY_DIR})

set(RobotAbb_LIBS
    ${QT_QTCORE_LIBRARY}
    FreeCADApp
)

SET(RobotAbb_SRCS
     activationrecord.cpp  
     activationrecord.h
     actunitnode.cpp
     actunitnode.h
     arccnode.cpp
     arccnode.h
     arcendnode.cpp
     arcendnode.h
     arclnode.cpp
     arclnode.h
     arclstartnode.cpp
     arclstartnode.h
     arraydatanode.cpp
     arraydatanode.h
     assignmentnode.cpp
     assignmentnode.h
     astnode.cpp
     astnode.h
     buildin.cpp
     buildin.h
     ast.h
     casenode.cpp
     casenode.h
     deactunitnode.cpp
     deactunitnode.h
     declaration_list.cpp
     declaration_list.h
     dimnumnode.cpp
     dimnumnode.h
     elseifnode.cpp
     elseifnode.h
     fornode.cpp
     fornode.h
     functioncallnode.cpp
     functioncallnode.h
     functionnode.cpp
     functionnode.h
     goto.cpp
     goto.h
     IAction.cpp
     IAction.h
     identifiernode.cpp
     identifiernode.h
     ifnode.cpp
     ifnode.h
     jointtargetnode.cpp
     jointtargetnode.h
     labelnode.cpp
     labelnode.h
     lexer.cpp
     modulenode.cpp
     modulenode.h
     moveabsjnode.cpp
     moveabsjnode.h
     movejnode.cpp
     movejnode.h
     movelnode.cpp
     movelnode.h
     nullnode.cpp
     nullnode.h
     numberliteralnode.cpp
     numberliteralnode.h
     operatornode.cpp
     operatornode.h
     parameternode.cpp
     parameternode.h
     paramnode.cpp
     paramnode.h
     parser.tab.cpp
     parser.tab.hpp
     printnode.cpp
     printnode.h
     returnnode.cpp
     returnnode.h
     robtargetnode.cpp
     robtargetnode.h
     speeddata.cpp
     speeddata.h
     statementlistnode.cpp
     statementlistnode.h
     stopnode.cpp
     stopnode.h
     stringliteralnode.cpp
     stringliteralnode.h
     switch.cpp
     switch.h
     switch_case_list.cpp
     switch_case_list.h
     symboltable.cpp
     symboltable.h
     tooldatanode.cpp
     tooldatanode.h
     tpwritenode.cpp
     tpwritenode.h
     translator.cpp
     translator.hpp
     twait.cpp
     twait.h
     type.cpp
     type.h
     variable.cpp
     variable.h
     whilenode.cpp
     whilenode.h
     wobjdatanode.cpp
     wobjdatanode.h
     lexer.hpp
     stack.hh
     errors.h
     FlexLexer.h
     PreCompiled.cpp
     PreCompiled.h
)

add_library(RobotAbb SHARED ${RobotAbb_SRCS})
target_link_libraries(RobotAbb ${RobotAbb_LIBS})

unset(_flag_found CACHE)
check_cxx_compiler_flag("-Wno-dev -Wno-deprecated-copy" _flag_found)
if (_flag_found)
  target_compile_options(RobotAbb PRIVATE -Wno-dev -Wno-deprecated-copy)
endif()

if(MINGW)
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--export-all-symbols")
endif()

SET_BIN_DIR(RobotAbb RobotAbb /Mod/Robot)
SET_PYTHON_PREFIX_SUFFIX(RobotAbb)

INSTALL(TARGETS RobotAbb DESTINATION ${CMAKE_INSTALL_LIBDIR})
