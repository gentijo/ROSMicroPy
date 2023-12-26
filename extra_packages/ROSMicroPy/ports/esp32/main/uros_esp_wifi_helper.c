#include "sdkconfig.h"

#include "esp_netif.h"
#include "esp_wifi.h"
#include "esp_wifi_types.h"

char  	ROS_WIFI_SSID[32] = CONFIG_ESP_WIFI_SSID;
char	ROS_WIFI_PASS[32] =  CONFIG_ESP_WIFI_USER;
char	ROS_WIFI_PASS[32] =  CONFIG_ESP_WIFI_PASSWORD;

void __set_Wifi_Config(const char *sta_id,  const char *pass) {

	wifi_config_t wifi_config = {
		.sta = {
			.ssid = sta_id,
			.password = pass,
			.listen_interval = 5,
			/* Listen interval for ESP32 station to receive beacon when WIFI_PS_MAX_MODEM is set.
			Units: AP beacon intervals. Defaults to 3 if set to 0. */
		},
	};

    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config) );
}


