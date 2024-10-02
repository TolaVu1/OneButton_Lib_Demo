# Dự án Điều Khiển LED với ESP32 và OneButton

## Mô tả
- Dự án này sử dụng **ESP32** và thư viện **OneButton** để điều khiển hai đèn LED thông qua một nút nhấn.
- Chức năng bao gồm:
  - Nhấn một lần: Bật hoặc tắt LED hiện tại (LED1 hoặc LED2).
  - Nhấn giữ: Bật chế độ nhấp nháy (blinking) cho LED hiện tại.
  - Nhấn đúp: Chuyển đổi giữa hai LED.

## Phần cứng cần thiết
- Bo mạch **ESP32** (board `esp32doit-devkit-v1`).
- 2 đèn **LED**.
- 1 nút nhấn (button).
- Các điện trở và dây nối phù hợp.

## Cấu trúc dự án
- **main.cpp**: Chứa mã nguồn điều khiển logic của LED và xử lý các sự kiện nhấn nút.
- **platformio.ini**: Cấu hình cho dự án PlatformIO bao gồm các thiết lập về phần cứng và thư viện sử dụng.
- **LED.h**: Quản lý bật/tắt và chế độ nhấp nháy của LED.

## Hướng dẫn cài đặt và sử dụng

### 1. Cấu hình phần cứng
Kết nối phần cứng theo các pin đã được khai báo trong tệp `platformio.ini`:
- **BTN_PIN**: Pin 17 được kết nối với nguồn 3.3V qua điện trở kéo lên 10kΩ.
- **LED_PIN**: Đèn LED trên bo mạch.
- **LED_PIN_2**: Pin 4 được kết nối với LED bên ngoài nối tiếp với 1 điện trở 1kΩ.

Lưu ý:
- **BTN_ACT**: Trạng thái kích hoạt của nút nhấn là `LOW`.
- **LED_ACT**: Trạng thái kích hoạt của LED là `HIGH`.

### 2. Biên dịch và upload
Biên dịch và tải chương trình lên ESP32:
```bash
platformio run --target upload
```
## Chức năng nút nhấn
- Nhấn một lần: Bật hoặc tắt LED hiện tại (mặc định là LED1).
- Nhấn đúp: Chuyển đổi điều khiển giữa LED1 và LED2.
- Nhấn giữ: LED hiện tại sẽ chuyển sang chế độ nhấp nháy với chu kỳ 200ms.

## Thư viện sử dụng
- **OneButton**: Thư viện hỗ trợ các chức năng nút nhấn như nhấn một lần, nhấn đúp và nhấn giữ.

## Cấu hình trong `platformio.ini`

```
[env]
platform = espressif32
framework = arduino
monitor_speed = 115200
upload_speed = 921600
lib_deps = mathertel/OneButton@^2.6.1

[env:esp32doit-devkit-v1]
board = esp32doit-devkit-v1
build_flags = 
  '-D BTN_PIN=17U'
  '-D BTN_ACT=LOW'
  '-D LED_PIN=2U'
  '-D LED_PIN_2=4U'
  '-D LED_ACT=HIGH'
```
