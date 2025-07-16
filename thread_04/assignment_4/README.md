Bài tập 4: Tối ưu hóa Truy cập với Read-Write Lock
Trong các hệ thống có tần suất đọc dữ liệu cao hơn nhiều so với ghi, sử dụng Mutex có thể gây tắc nghẽn không cần thiết. Read-Write Lock là một cơ chế khóa chuyên biệt, cho phép nhiều luồng đọc đồng thời nhưng vẫn đảm bảo tính độc quyền cho luồng ghi.

Yêu cầu:
Viết chương trình mô phỏng một tài nguyên dữ liệu (một biến nguyên toàn cục).
Tạo ra 5 luồng đọc (Reader) và 2 luồng ghi (Writer).
Reader: Chỉ đọc và in ra giá trị của tài nguyên.
Writer: Tăng giá trị của tài nguyên lên 1.
Sử dụng pthread_rwlock_t để đồng bộ hóa:
Các Reader phải yêu cầu khóa đọc (pthread_rwlock_rdlock).
Các Writer phải yêu cầu khóa ghi (pthread_rwlock_wrlock).
Quan sát và in ra các hoạt động đọc/ghi để thấy rằng nhiều Reader có thể chạy song song, nhưng Writer phải chạy độc quyền.