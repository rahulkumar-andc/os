// ==============================================================================
// UNIVERSITY OF DELHI - OPERATING SYSTEMS PRACTICAL LAB (GE / PME)
// PRACTICAL 07
//
// QUESTION:
// Write a program to copy files using system calls (open, read, write, close).
// ==============================================================================

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

const int BUFFER_SIZE = 1024;

int main(int argc, char* argv[]) {
    // If command line arguments are not supplied, use default demonstration filenames
    string src_name = "os_source_test.txt";
    string dest_name = "os_destination_copy.txt";

    if (argc >= 3) {
        src_name = argv[1];
        dest_name = argv[2];
    } else {
        cout << "No CLI arguments provided. Creating test source file: " << src_name << endl;
        int init_fd = open(src_name.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
        string sample_data = "Operating Systems Lab: System Call Copy Demonstration.\nUniversity of Delhi.\n";
        write(init_fd, sample_data.c_str(), sample_data.size());
        close(init_fd);
    }

    cout << "Copying from [" << src_name << "] to [" << dest_name << "] using system calls..." << endl;

    // Step 1: Open Source file with Read-Only flag
    int src_fd = open(src_name.c_str(), O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return 1;
    }

    // Step 2: Open/Create Destination file (Write-only, Truncate, Permissions 0644)
    int dest_fd = open(dest_name.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error creating/opening destination file");
        close(src_fd);
        return 1;
    }

    // Step 3: Transfer data byte-by-byte using read() and write() system calls
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, total_bytes = 0;

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        ssize_t bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            return 1;
        }
        total_bytes += bytes_written;
    }

    if (bytes_read < 0) {
        perror("Error reading from source file");
    }

    // Step 4: Close file descriptors
    close(src_fd);
    close(dest_fd);

    cout << "SUCCESS: File copied successfully (" << total_bytes << " bytes transferred)." << endl;
    return 0;
}
