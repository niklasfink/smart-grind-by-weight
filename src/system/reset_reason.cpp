#include "reset_reason.h"

namespace {

esp_reset_reason_t last_reset_reason = ESP_RST_UNKNOWN;

} // namespace

void capture_reset_reason() {
    last_reset_reason = esp_reset_reason();
}

esp_reset_reason_t get_last_reset_reason() {
    return last_reset_reason;
}

const char* get_last_reset_reason_label() {
    switch (last_reset_reason) {
        case ESP_RST_POWERON: return "POWERON";
        case ESP_RST_EXT: return "EXT (Reset Pin)";
        case ESP_RST_SW: return "SW (esp_restart)";
        case ESP_RST_PANIC: return "PANIC (Exception)";
        case ESP_RST_INT_WDT: return "INT_WDT";
        case ESP_RST_TASK_WDT: return "TASK_WDT";
        case ESP_RST_WDT: return "WDT";
        case ESP_RST_DEEPSLEEP: return "DEEPSLEEP";
        case ESP_RST_BROWNOUT: return "BROWNOUT";
        case ESP_RST_SDIO: return "SDIO";
        case ESP_RST_UNKNOWN:
        default: return "UNKNOWN";
    }
}

int get_last_reset_reason_code() {
    return static_cast<int>(last_reset_reason);
}

bool last_reset_was_unexpected() {
    switch (last_reset_reason) {
        case ESP_RST_PANIC:
        case ESP_RST_INT_WDT:
        case ESP_RST_TASK_WDT:
        case ESP_RST_WDT:
        case ESP_RST_BROWNOUT:
            return true;
        default:
            return false;
    }
}
