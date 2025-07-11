### Bài tập 1: Khởi tạo và Thu dọn Tiến trình

## Khảo sát vòng đời cơ bản nhất của một tiến trình: được tạo ra, thực thi, kết thúc và được tiến trình cha chờ đợi.
## Yêu cầu:

### Viết chương trình tạo một tiến trình con bằng fork().
### Tiến trình cha: In ra PID của chính nó và PID của tiến trình con. Sau đó, sử dụng wait() để chờ con kết thúc. Dùng WIFEXITED() và WEXITSTATUS() để ghi nhận và in ### ra mã thoát của tiến trình con.
### Tiến trình con: In ra PID của chính nó, sau đó gọi exit() với một giá trị cụ thể (ví dụ: exit(10)).



orphan process:
    - dad dead, child alive -> systemd manage the child process

zombie process:
    - child dead, dad alive but not use wait() to clean up child's resouce -> child process still in process table



