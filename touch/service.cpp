/*
 * Copyright (C) 2020-2023 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "lineage.touch@1.0-service.rhodep"

#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>

#include "HighTouchPollingRate.h"

using ::vendor::lineage::touch::V1_0::IHighTouchPollingRate;
using ::vendor::lineage::touch::V1_0::implementation::HighTouchPollingRate;

int main() {
    android::sp<IHighTouchPollingRate> highTouchPollingRate = new HighTouchPollingRate();

    android::hardware::configureRpcThreadpool(1, true /*callerWillJoin*/);

    if (highTouchPollingRate->registerAsService() != android::OK) {
        LOG(ERROR) << "Cannot register touchscreen high polling rate HAL service.";
        return 1;
    }

    LOG(INFO) << "Touchscreen HAL service ready.";

    android::hardware::joinRpcThreadpool();

    LOG(ERROR) << "Touchscreen HAL service failed to join thread pool.";
    return 1;
}
