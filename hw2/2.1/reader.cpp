#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>

int main() {
    using namespace boost::interprocess;

    try {
        // Open the shared memory object created by the writer
        shared_memory_object shm(open_only, "SharedMemory", read_only);

        // Map the shared memory into this process
        mapped_region region(shm, read_only);

        // Get a pointer to the shared memory
        int* shared_data = static_cast<int*>(region.get_address());

        // Read the integer from shared memory
        std::cout << "Reader: Read " << *shared_data << " from shared memory." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Reader: Error - " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
