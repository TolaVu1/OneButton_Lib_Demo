# Điều Khiển Đèn LED với OneButton Library

Dự án này mô tả cách điều khiển đèn LED sử dụng một nút nhấn đơn với thao tác single-click và double-click. Nút nhấn được xử lý bằng thư viện OneButton để nhận biết nhiều hành động mà không làm gián đoạn vòng lặp chính.

## Tính Năng
- **Single-click**: Bật hoặc tắt đèn LED.
- **Double-click**: Chuyển đèn LED vào chế độ nháy hoặc tắt chế độ nháy.
- **Nháy không gây nghẽn**: Đèn nháy được xử lý trong vòng lặp chính mà không làm gián đoạn chương trình.

## Yêu Cầu Phần Cứng
1. **ESP32 Dev Kit**.
2. **Đèn LED** kết nối với GPIO 4 (hoặc chân GPIO khác có thể cấu hình).
3. **Nút nhấn** kết nối với GPIO 13, với điện trở kéo lên hoặc kéo xuống để tránh trạng thái lơ lửng.
4. **Điện trở 330Ω** (để giới hạn dòng điện cho đèn LED).

### Sơ Đồ Kết Nối
- **Đèn LED**:
  - Kết nối **cực dương** của đèn LED với chân GPIO 4 (`LED_PIN`).
  - Kết nối **cực âm** của đèn LED với GND thông qua **điện trở 330Ω**.
  
- **Nút nhấn**:
  - Kết nối một đầu của nút nhấn với chân GPIO 13 (`BTN_PIN`).
  - Kết nối đầu còn lại của nút nhấn với **GND**.
  - Sử dụng **điện trở kéo lên 10kΩ** giữa chân nút và 3.3V (nếu cần).

## Cấu Hình PlatformIO
Đảm bảo tệp `platformio.ini` của bạn được cấu hình đúng cho bo ESP32 và các thư viện cần thiết. Dưới đây là một ví dụ cấu hình:

```ini
[env:esp32doit-devkit-v1]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino
monitor_speed = 115200
lib_deps = mathertel/OneButton@^2.6.1
build_flags =
    '-D BTN_PIN=13U'
    '-D BTN_ACT=LOW'
    '-D LED_PIN=4U'
    '-D LED_ACT=HIGH'
