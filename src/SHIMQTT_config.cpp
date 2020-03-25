/*
 * Copyright (c) 2020 Karsten Becker All rights reserved.
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

// WARNING, this is an automatically generated file!
// Don't change anything in here.
// Last update 2020-03-25

# include <iostream>
# include <string>


# include "SHIMQTT.h"
// Configuration implementation for class SHI::MQTTConfig

namespace {
    
}  // namespace

SHI::MQTTConfig::MQTTConfig(const JsonObject &obj):
      mqttServerIP(obj["mqttServerIP"] | "192.168.188.250"),
      mqttServerUserName(obj["mqttServerUserName"] | "esphomie"),
      mqttServerPassword(obj["mqttServerPassword"] | "Jtsvc9TsP5NGfek8"),
      sensorTopic(obj["sensorTopic"] | "sensors"),
      sensorPostTopic(obj["sensorPostTopic"] | "/influxformat")
  {}

void SHI::MQTTConfig::fillData(JsonObject &doc) const {
    doc["mqttServerIP"] = mqttServerIP;
  doc["mqttServerUserName"] = mqttServerUserName;
  doc["mqttServerPassword"] = mqttServerPassword;
  doc["sensorTopic"] = sensorTopic;
  doc["sensorPostTopic"] = sensorPostTopic;
}

int SHI::MQTTConfig::getExpectedCapacity() const {
  return JSON_OBJECT_SIZE(5);
}

