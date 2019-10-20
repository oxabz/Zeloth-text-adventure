cmake_minimum_required(VERSION 3.14)
project(Zeloth)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Zeloth main.cpp class/Event.cpp class/Event.h class/Action.cpp class/Action.h class/Consequence.h class/Consequences/CDisplayText.cpp class/Consequences/CDisplayText.h class/Utils/DisplayUtils.cpp class/Utils/DisplayUtils.h class/Situation.cpp class/Situation.h class/Consequences/CChangeEvent.cpp class/Consequences/CChangeEvent.h class/GameState.cpp class/GameState.h class/Consequences/CExitMesage.cpp class/Consequences/CExitMesage.h class/Utils/Condition.h class/Utils/Conditions/CondSuperior.cpp class/Utils/Conditions/CondSuperior.h class/Utils/Conditions/CondSuperiorE.cpp class/Utils/Conditions/CondSuperiorE.h class/Utils/Conditions/CondAnd.cpp class/Utils/Conditions/CondAnd.h class/Utils/Conditions/CondOr.cpp class/Utils/Conditions/CondOr.h class/Consequences/CIf.cpp class/Consequences/CIf.h class/Consequences/CChangeVariable.cpp class/Consequences/CChangeVariable.h class/Consequences/CIncVariable.cpp class/Consequences/CIncVariable.h class/Utils/DeserializationUtils.cpp class/Utils/DeserializationUtils.h class/Utils/JsonAmalgamate/json/json.h class/Utils/JsonAmalgamate/jsoncpp.cpp class/Utils/Conditions/CondEquals.cpp class/Utils/Conditions/CondEquals.h class/Consequences/CHelp.cpp class/Consequences/CHelp.h class/Utils/ProceduralPicking.cpp class/Utils/ProceduralPicking.h class/StartingEvent.cpp class/StartingEvent.h)
add_executable(Test Test.cpp class/View/GameView.cpp class/View/GameView.h class/View/DrawableElement.cpp class/View/DrawableElement.h class/View/ElementContainer.cpp class/View/ElementContainer.h class/View/Scroll.cpp class/View/Scroll.h class/View/BackgroundedElement.cpp class/View/BackgroundedElement.h class/View/AspectRatioElement.cpp class/View/AspectRatioElement.h class/View/ScrollingContentElement.cpp class/View/ScrollingContentElement.h class/View/WrappedTextElement.cpp class/View/WrappedTextElement.h class/View/ScrollingText.cpp class/View/ScrollingText.h class/View/InputElement.cpp class/View/InputElement.h)
target_link_libraries(Zeloth ${CURSES_LIBRARIES} sfml-graphics sfml-audio)
target_link_libraries(Test sfml-graphics sfml-audio)


file(COPY Resources/variables.json Resources/events.json DESTINATION ${CMAKE_BINARY_DIR}/Resources/)