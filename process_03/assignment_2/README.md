# Bài tập 2: Thay thế Mã thực thi và Tương tác với Môi trường
## Tìm hiểu cách một tiến trình có thể thay thế hoàn toàn mã lệnh đang chạy của nó bằng một chương trình khác và cách truyền thông tin qua biến môi trường.
## Yêu cầu:

###
Viết chương trình mà tiến trình cha thiết lập một biến môi trường (ví dụ: MY_COMMAND=ls).
Tiến trình con sẽ đọc biến môi trường này. Dựa vào giá trị đọc được, nó sẽ dùng họ hàm exec() (ví dụ execlp()) để thực thi lệnh tương ứng (ls, date,...).
Trong báo cáo, giải thích: Điều gì xảy ra với không gian địa chỉ và mã lệnh của tiến trình con sau khi exec() được gọi thành công?
###