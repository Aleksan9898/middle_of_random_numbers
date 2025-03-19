#include "rclcpp/rclcpp.hpp"
#include "middle_of_random_numbers/publisher_node.hpp"

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PublisherNode>());
    rclcpp::shutdown();
    return 0;
}

