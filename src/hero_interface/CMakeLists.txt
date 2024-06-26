##############################################################################
# CMake
##############################################################################

cmake_minimum_required(VERSION 3.0)
project(hero_interface)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_module)
set(CMAKE_BUILD_TYPE Release)

##############################################################################
# Catkin
##############################################################################

# qt_build provides the qt cmake glue, roscpp the comms for a default talker
# find_package(catkin REQUIRED COMPONENTS qt_build roscpp
#   nav_msgs
#   geometry_msgs
#   actionlib
#   hero_judgesys
#   hero_common
#   hero_msgs
#   tf
#   roslib
#   )
  find_package(catkin REQUIRED COMPONENTS  roscpp
  nav_msgs
  geometry_msgs
  actionlib
  hero_judgesys
  hero_common
  hero_msgs
  tf
  roslib
  )

include_directories("/usr/include/eigen3")
include_directories("/usr/include/eigen3/Eigen")

include_directories(
    ${catkin_INCLUDE_DIRS}
    include
    include/hero_interface
)
# Use this to define what the package will export (e.g. libs, headers).
# Since the default here is to produce only a binary, we don't worry about
# exporting anything. 
catkin_package()

##############################################################################
# Qt Environment
##############################################################################

# this comes from qt_build's qt-ros.cmake which is automatically 
# included via the dependency call in package.xml
# rosbuild_prepare_qt4(QtCore QtGui) # Add the appropriate components to the component list here
find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})


##############################################################################
# Sections
##############################################################################

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/hero_interface/*.hpp)

QT4_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT4_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

##############################################################################
# Sources
##############################################################################

file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)

##############################################################################
# Binaries
##############################################################################

add_executable(hero_interface ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(hero_interface ${QT_LIBRARIES} ${catkin_LIBRARIES})
install(TARGETS hero_interface RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
