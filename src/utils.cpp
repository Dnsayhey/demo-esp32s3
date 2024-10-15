// utils.cpp
#include <Arduino.h>
#include <esp_system.h>

uint32_t chipId = 0;

void printBoardInfo() {
    // 获取芯片 ID
    for(int i = 0; i < 17; i += 8) {
        chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
    }

    // 打印芯片信息
    Serial.printf("ESP32 Chip model = %s Rev %d\n", ESP.getChipModel(), ESP.getChipRevision());
    Serial.printf("This chip has %d cores\n", ESP.getChipCores());
    Serial.print("Chip ID: "); Serial.println(chipId);

    // 获取 CPU 频率
    uint32_t cpuFreqMHz = ESP.getCpuFreqMHz();
    Serial.printf("CPU Frequency: %u MHz\n", cpuFreqMHz);

    // 获取 SDK 版本
    const char* sdkVersion = esp_get_idf_version();
    Serial.printf("SDK Version: %s\n", sdkVersion);

    // 获取 Flash 大小（以字节为单位）
    uint32_t flashSize = ESP.getFlashChipSize();
    Serial.printf("Flash Size: %u bytes (%.2f MB)\n", flashSize, flashSize / 1048576.0);

    // 获取 Flash 芯片速度
    uint32_t flashSpeed = ESP.getFlashChipSpeed();
    Serial.printf("Flash Speed: %u Hz\n", flashSpeed);

    // 获取 Flash 芯片模式
    FlashMode_t flashMode = ESP.getFlashChipMode();
    const char* modeStr = (flashMode == FM_QIO ? "QIO" : flashMode == FM_QOUT ? "QOUT" :
                           flashMode == FM_DIO ? "DIO" : flashMode == FM_DOUT ? "DOUT" : "UNKNOWN");
    Serial.printf("Flash Mode: %s\n", modeStr);

    // 获取 PSRAM 的大小（以字节为单位）
    uint32_t psramSize = ESP.getPsramSize();
    Serial.printf("PSRAM Size: %u bytes (%.2f MB)\n", psramSize, psramSize / 1048576.0);

    // 获取 PSRAM 剩余内存
    uint32_t freePsram = ESP.getFreePsram();
    Serial.printf("Free PSRAM: %u bytes (%.2f MB)\n", freePsram, freePsram / 1048576.0);

    // 获取总内存
    uint32_t totalHeap = ESP.getHeapSize();
    Serial.printf("Total heap: %u bytes (%.2f MB)\n", totalHeap, totalHeap / 1048576.0);

    // 获取剩余内存
    uint32_t freeMemory = ESP.getFreeHeap();
    Serial.printf("Free Memory: %u bytes (%.2f MB)\n", freeMemory, freeMemory / 1048576.0);    
}