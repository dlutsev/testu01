#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("/dev/random", O_RDONLY);
    if (fd < 0) {
        perror("Error opening /dev/random");
        return 1;
    }

    FILE *file = fopen("random_data.bin", "wb");
    if (!file) {
        perror("Error opening output file");
        close(fd);
        return 1;
    }

    unsigned char buffer[1024];
    size_t bytes_to_read = 40000000;
    size_t total_read = 0;

    while (total_read < bytes_to_read) {
        ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read > 0) {
            fwrite(buffer, 1, bytes_read, file);
            total_read += bytes_read;
        } else {
            perror("Error reading /dev/random");
            break;
        }
    }

    fclose(file);
    close(fd);

    printf("Random data saved to random_data.bin\n");
    return 0;
}