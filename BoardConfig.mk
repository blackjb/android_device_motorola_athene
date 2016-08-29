#
# Copyright (C) 2016 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

include device/motorola/msm8952-common/BoardConfigCommon.mk

-include vendor/motorola/athene/BoardConfigVendor.mk

DEVICE_PATH := device/motorola/athene

# Asserts
TARGET_OTA_ASSERT_DEVICE := athene,athene_f,xt1621,xt1622,xt1625,xt1626,xt1640,xt1641,xt1642,xt1643,xt1644
