cmake_minimum_required(VERSION 3.8)
project(netft_rdt_driver)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# --- Dependencies ---
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(diagnostic_msgs REQUIRED)
find_package(diagnostic_updater REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options thread)

# --- Generate service ---
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/StringCmd.srv"
  DEPENDENCIES std_msgs
)
# Get the generated typesupport target
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")

# --- Include dirs ---
include_directories(include)

# --- Library ---
add_library(${PROJECT_NAME}_lib  STATIC
  src/netft_rdt_driver.cpp
  src/netft_rdt_bias.cpp
  src/ft_listener.cpp
)

ament_target_dependencies(${PROJECT_NAME}_lib
  rclcpp
  geometry_msgs
  std_msgs
  diagnostic_updater
  diagnostic_msgs
  tf2
  tf2_ros
)

# Include your own headers
target_include_directories(${PROJECT_NAME}_lib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp>
  $<INSTALL_INTERFACE:include>
)


# --- Node executable ---
add_executable(netft_node src/netft_node.cpp)
target_link_libraries(netft_node ${PROJECT_NAME}_lib Boost::program_options Boost::thread)


ament_target_dependencies(netft_node
  rclcpp
  geometry_msgs
  diagnostic_updater
  diagnostic_msgs
  tf2
  tf2_ros
)

# Make node depend on generated service
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
add_dependencies(netft_node ${cpp_typesupport_target})
target_link_libraries(netft_node ${cpp_typesupport_target})


# --- Install ---
install(TARGETS
  ${PROJECT_NAME}_lib
  netft_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
