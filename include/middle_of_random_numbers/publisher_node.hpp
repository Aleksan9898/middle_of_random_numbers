#ifndef PUBLISHER_NODE_HPP_
#define PUBLISHER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

#include <cstdlib>
#include <chrono>

/**
 * Класс PublisherNode представляет собой узел ROS 2, который публикует сообщения
 * типа Int32 на определённый топик с заданной периодичностью.
 */
class PublisherNode: public rclcpp::Node {
public: 
     /**
     * Конструктор класса PublisherNode.Инициализирует узел с именем "publisher_node" и настраивает
     * публикацию сообщений типа Int32 на топик "int32_topic" каждые 500 миллисекунд.
     */
    PublisherNode();
private:
     /**
     * Функция обратного вызова для таймера.Эта функция вызывается каждые 500 миллисекунд и отвечает за
     * создание и публикацию новых сообщений типа Int32.
     */
    void timer_callback();

    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

#endif