#include "middle_of_random_numbers/publisher_node.hpp"

PublisherNode::PublisherNode(): Node("publisher_node")
{
    publisher_ = this->create_publisher<std_msgs::msg::Int32>("random_numbers",10);
    timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&PublisherNode::timer_callback, this));
}

void PublisherNode::timer_callback()
{
    auto message = std_msgs::msg::Int32();
    message.data = rand()%100;
    publisher_->publish(message);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", message.data);
}