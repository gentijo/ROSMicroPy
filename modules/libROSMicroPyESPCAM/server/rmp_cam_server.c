#include "rmp_cam_server.h"
#include "example_interfaces/srv/add_two_ints.h"

void service_callback(const void *req, void *res)
{
  sensor_msgs__msg__CompressedImage *response = (sensor_msgs__msg__CompressedImage *)res;
  std_msgs__msg__Header *request = (std_msgs__msg__Header *) req;


  printf("Received request with frame_id: %s\n", request->frame_id.data);

  camera_fb_t *img = esp_camera_fb_get();

  if (img != NULL)
  {
    int file_size = img->len;

    // Allocate memory for the image data
    response->data.data = (uint8_t *)malloc(file_size * sizeof(uint8_t));
    memcpy(response->data.data, img->buf, file_size);

    response->data.size = file_size;
    response->data.capacity = file_size;

    // Fill in the header
    response->header.stamp.sec = 0;
    response->header.stamp.nanosec = 0;
    response->header.frame_id.data = (char *)malloc(255 * sizeof(char));
    snprintf(response->header.frame_id.data, 255, "frame");
    response->header.frame_id.size = strlen(response->header.frame_id.data);
    response->header.frame_id.capacity = 255;

    // Fill in the format
    response->format.data = (char *)malloc(255 * sizeof(char));
    snprintf(response->format.data, 255, "jpeg");
    response->format.size = strlen(response->format.data);
    response->format.capacity = 255;
  }
}

rcl_service_t service;
rclc_executor_handle_t handle;

sensor_msgs__msg__CompressedImage response_msg;
std_msgs__msg__Header request_msg;

void init_camera_service()
{
  // Create a service
  service = rcl_get_zero_initialized_service();

  rclc_service_init_default(
      &service,
      &rmp_rcl_node,
      ROSIDL_GET_SRV_TYPE_SUPPORT(example_interfaces, srv, AddTwoInts),
      CAM_TopicName);

rclc_executor_add_service(
  &rmp_rclc_executor, 
  &service, 
  &request_msg,
  &response_msg,
  service_callback);
}
