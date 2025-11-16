import os
import yaml
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_share = get_package_share_directory('netft_rdt_driver')
    yaml_file = os.path.join(pkg_share, 'config', 'setup.yaml')

    with open(yaml_file, 'r') as f:
        sensors_data = yaml.safe_load(f)

    ld = LaunchDescription()

    # Loop over all top-level keys (sensor_1, sensor_2, ...)
    for idx, (sensor_name, params) in enumerate(sensors_data.items(), start=1):
        node = Node(
            package='netft_rdt_driver',
            executable='netft_node',
            name=sensor_name,
            output='screen',
            parameters=[{
                'address': params.get('ip', ''),
                'bias': params.get('bias', False),
                'rate': params.get('rate', 50),
                'frame_id': params.get('frame_id', f"ft_frame_{idx}"),
                'alpha': params.get('alpha', 0.0),
                'rot': params.get('rot', 0.0),
                'scale_x': params.get('scale_x', 1.0),
                'scale_y': params.get('scale_y', 1.0),
                'scale_z': params.get('scale_z', 1.0)
            }]
        )
        ld.add_action(node)

    return ld
