#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <nav2_msgs/action/navigate_to_pose.hpp>

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("cancel_goals_node");
  using CancelAllGoals = nav2_msgs::action::NavigateToPose;
  using GoalHandle = rclcpp_action::ClientGoalHandle<CancelAllGoals>;
  auto action_client = rclcpp_action::create_client<CancelAllGoals>(node, "navigate_to_pose");


  if (!action_client->wait_for_action_server(std::chrono::seconds(5))) {
    RCLCPP_ERROR(node->get_logger(), "Action server not available.");
    return 1;
  }


  auto goal_msg = CancelAllGoals::Goal();
  auto goal_options = rclcpp_action::Client<CancelAllGoals>::SendGoalOptions();
  auto goal_handle_future = action_client->async_send_goal(goal_msg, goal_options);
  rclcpp::spin_until_future_complete(node, goal_handle_future);


  if (goal_handle_future.wait_for(std::chrono::seconds(1)) != std::future_status::ready) {
    RCLCPP_ERROR(node->get_logger(), "Failed to cancel goals.");
    return 1;
  }

  GoalHandle::SharedPtr goal_handle = goal_handle_future.get();

  if (!goal_handle) {
    RCLCPP_ERROR(node->get_logger(), "Goal canceled.");
    return 1;
  }

  RCLCPP_INFO(node->get_logger(), "Goals canceled.");

  rclcpp::shutdown();
  return 0;
}
