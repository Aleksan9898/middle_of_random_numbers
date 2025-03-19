from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='middle_of_random_numbers',
            executable='publisher_node',
            name='publisher_node',
            output='screen' 
        ),
        Node(
            package='middle_of_random_numbers',
            executable='service_node',
            name='service_node',
            output='screen'
        )
    ])
