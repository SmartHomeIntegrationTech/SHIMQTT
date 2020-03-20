/*
 * Copyright (c) 2020 Karsten Becker All rights reserved.
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */
#pragma once

#include <map>
#include <string>

#include "SHICommunicator.h"
#include "SHIFactory.h"
#include "SHIObject.h"
#include "SHISensor.h"
#include "ext/LeifHomieLib.h"

namespace SHI {

class MQTTConfig : public Configuration {
 public:
  MQTTConfig() {}
  explicit MQTTConfig(const JsonObject &obj);
  void fillData(JsonObject &doc) const override;
  std::string mqttServerIP = "192.168.188.250";
  std::string mqttServerUserName = "esphomie";
  std::string mqttServerPassword = "Jtsvc9TsP5NGfek8";
  std::string sensorTopic = "sensors";
  std::string sensorPostTopic = "/influxformat";

 protected:
  int getExpectedCapacity() const override;
};

class MQTT : public Communicator {
 public:
  explicit MQTT(const MQTTConfig &config)
      : Communicator("MQTT"), config(config) {}
  void setupCommunication() override;
  void loopCommunication() override;
  void newReading(const MeasurementBundle &reading) override;
  void newStatus(const Measurement &status, SHIObject *src) override;
  const Configuration *getConfig() const override { return &config; }
  bool reconfigure(Configuration *newConfig) override {
    config = castConfig<MQTTConfig>(newConfig);
    return true;
  }

 private:
  String updateData(const SHI::Measurement &data);
  HomieDevice homie;
  std::map<std::string, HomieProperty *> nameToProps;
  MQTTConfig config;
};

}  // namespace SHI
