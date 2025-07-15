Bài tập 3: Khảo sát các Trạng thái Tiến trình Đặc biệt
Quan sát và phân tích hai trạng thái đặc biệt thường gặp trong quản lý tiến trình là Zombie và Orphan.
Yêu cầu:
Tạo tiến trình Zombie:
Viết chương trình mà tiến trình con thoát ngay lập tức, nhưng tiến trình cha không gọi wait() mà sleep() trong một khoảng thời gian dài.
Sử dụng lệnh ps trong terminal để quan sát trạng thái <defunct> của tiến trình con.
Tạo tiến trình Orphan:
Viết chương trình mà tiến trình cha thoát ngay sau khi tạo con.
Tiến trình con sẽ sleep() một lúc và trong thời gian đó, liên tục in ra PID của tiến trình cha (PPID). Quan sát sự thay đổi của PPID.
Trong báo cáo, giải thích: Tại sao hai trạng thái này xuất hiện và ý nghĩa của chúng trong hệ thống Linux là gì?
