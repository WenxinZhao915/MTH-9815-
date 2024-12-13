#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

int main() {
    using namespace boost::interprocess;

    try {
        // Remove any previous shared memory object with the same name
        shared_memory_object::remove("SharedMemory");

        // Create a shared memory object
        shared_memory_object shm(create_only, "SharedMemory", read_write);

        // Set the size of the shared memory object
        shm.truncate(sizeof(int));

        // Map the shared memory into this process
        mapped_region region(shm, read_write);

        // Get a pointer to the shared memory
        int* shared_data = static_cast<int*>(region.get_address());

        // Write an integer to shared memory
        *shared_data = 42; // Example integer
        std::cout << "Writer: Wrote 42 to shared memory." << std::endl;

        // Keep the writer running to allow reader to access the memory
        std::cout << "Writer: Press Enter to exit..." << std::endl;
        std::cin.get();

        // Clean up shared memory
        shared_memory_object::remove("SharedMemory");
    } catch (const std::exception& e) {
        std::cerr << "Writer: Error - " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

'''
When I run:
(base) wenxin@wenxindeMacBook-Pro 2.1 % ./writer 
Writer: Wrote 42 to shared memory.
Writer: Press Enter to exit...

It shows:
(base) wenxin@wenxindeMacBook-Pro 2.1 % ./reader 
Reader: Read 42 from shared memory.
'''