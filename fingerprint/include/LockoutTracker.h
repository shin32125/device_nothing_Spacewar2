/*
 * Copyright (C) 2024 The LineageOS Project
 * Copyright (C) 2024 The halogenOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once
namespace aidl {
namespace android {
namespace hardware {
namespace biometrics {
namespace fingerprint {
#define LOCKOUT_TIMED_THRESHOLD 10
#define LOCKOUT_TIMED_DURATION 20 * 1000
#define LOCKOUT_PERMANENT_THRESHOLD 30
enum class LockoutMode {
    NONE,
    TIMED,
    PERMANENT
};
class LockoutTracker {
public:
    void reset(bool clearAttemptCounter);
    LockoutMode getMode();
    void addFailedAttempt();
    int64_t getLockoutTimeLeft();
private:
    int32_t mFailedCount = 0;
    int64_t mLockoutTimedStart;
    LockoutMode mCurrentMode;
};
} // namespace fingerprint
} // namespace biometrics
} // namespace hardware
} // namespace android
} // namespace aidl