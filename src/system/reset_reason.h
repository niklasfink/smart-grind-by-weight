#pragma once

#include <esp_system.h>

void capture_reset_reason();
esp_reset_reason_t get_last_reset_reason();
const char* get_last_reset_reason_label();
int get_last_reset_reason_code();
bool last_reset_was_unexpected();
