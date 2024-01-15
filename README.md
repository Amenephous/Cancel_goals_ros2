# ros2-Cancel_goals
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/Version-1.0-blue)](https://github.com/Amenephous/Cancel_goals_ros2/releases)

This repository showcases a ROS2 node specifically designed to halt the movement of a bot. It achieves this by canceling the set goals, effectively setting the `geometry_msgs` to null.


## Implementation

[![Cancel Goals Demonstration](https://github.com/Amenephous/Cancel_goals_ros2/assets/48127920/b95aa4d9-044f-4217-a215-502a0120f1f5)](https://github.com/Amenephous/ros2-Cancel_goals_ros2/assets/48127920/b95aa4d9-044f-4217-a215-502a0120f1f5)

Video Demonstration of stopping a mobile bot while navigating to goal location which was set by slam toolbox in rviz2.

## Usage

Once you have any mobile bot or entity which is publishing geometry_msgs, 
   ```bash
  git clone https://github.com/Amenephous/Cancel_goals_ros2.git
  cd ros2-Cancel_goals
  colcon build
  source install/setup.bash
  ros2 run Cancel_goals_ros2 stop_node
```

## Contributions

Contributions are welcome! Feel free to open issues or submit pull requests.
## License

This project is licensed under the MIT License - see the LICENSE file for details.
