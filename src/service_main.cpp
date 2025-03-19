#include "rclcpp/rclcpp.hpp"
#include "middle_of_random_numbers/service_node.hpp"

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ServiceNode>());
    rclcpp::shutdown();
    return 0;
}
