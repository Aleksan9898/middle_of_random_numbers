#include "middle_of_random_numbers/service_node.hpp"

ServiceNode::ServiceNode() : Node("service_node"), window_size_(10)
{
    this->declare_parameter("window_size", window_size_);
    this->get_parameter("window_size", window_size_);

    subscription_ = this->create_subscription<std_msgs::msg::Int32>("random_numbers", 10,
        std::bind(&ServiceNode::topic_callback, this, std::placeholders::_1)
    );

}

void ServiceNode::topic_callback(const std_msgs::msg::Int32::SharedPtr message)
{
    numbers_.push(message->data);
    if (numbers_.size() == window_size_)
    {
        double average = 0.0;
        while(!numbers_.empty()){
            average+=numbers_.top();
            numbers_.pop();
        }
        average = average / window_size_;
        RCLCPP_INFO(this->get_logger(), "Average of last %d numbers: %.2f", window_size_, average);
    }
}


