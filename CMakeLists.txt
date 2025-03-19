cmake_minimum_required(VERSION 3.8)
project(middle_of_random_numbers)

set(CMAKE_CXX_STANDARD 14)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)

include_directories(
  include
)

add_executable(publisher_node src/publisher_main.cpp src/publisher_node.cpp)
ament_target_dependencies(publisher_node rclcpp std_msgs)

add_executable(service_node src/service_main.cpp src/service_node.cpp)
ament_target_dependencies(service_node rclcpp std_msgs std_srvs)

install(TARGETS
  publisher_node
  service_node
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
