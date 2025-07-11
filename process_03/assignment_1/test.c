#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    // int pid = 9;
    int stat;

    if (pid < 0) {
        // fork thất bại
        perror("fork failed");
        // exit(1);
    } else if (pid == 0) {
        // Đây là tiến trình con
        printf("Tiến trình con (PID: %d), cha PID: %d\n", getpid(), getppid());
        sleep(5);  // Ngủ 5 giây để cha có thể kết thúc trước
        printf("Tiến trình con tiếp tục, cha PID: %d\n", getppid());
        exit(19); 
    } else {
        // Đây là tiến trình cha
        printf("Tiến trình cha (PID: %d), tạo con PID: %d\n", getpid(), pid);
        pid_t cpid = wait(&stat);
        perror("wait lỗi");
        // sleep(30);
        printf("Tiến trình cha (PID: %d), ket thuc\n", getpid());
        printf("Child pid = %d\n", cpid);

        if (WIFEXITED(stat))
            printf("Exit status: %d\n", WEXITSTATUS(stat));
        else if (WIFSIGNALED(stat))
            psignal(WTERMSIG(stat), "Exit signal");

        exit(0);  // Cha kết thúc ngay lập tức
    }

    return 0;
}
