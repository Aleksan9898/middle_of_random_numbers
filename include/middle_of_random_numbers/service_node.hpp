#ifndef SERVICE_NODE_HPP_
#define SERVICE_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_srvs/srv/empty.hpp"

#include <stack>
#include <numeric>  

/**
 *  Класс ServiceNode представляет собой узел ROS 2, который обрабатывает входящие сообщения
 *   и вычисляет среднее значение последних чисел с использованием заданного размера окна.
 */
class ServiceNode: public rclcpp::Node{
public:
    /**
     *  Конструктор класса ServiceNode. Инициализирует узел, объявляет параметры и создает подписку на сообщения типа Int32.
     */
    ServiceNode();
private:
    /**
     * Обработчик для входящих сообщений типа Int32.
     * Указатель на полученное сообщение, содержащее целое число. Это число будет добавлено в стек для последующего усреднения.
     */
    void topic_callback(const std_msgs::msg::Int32::SharedPtr message);
    
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
    std::stack<int> numbers_;
    int window_size_;
};

#endif
