#pragma once
#include "utils.h"
#include <vector>
#include <fstream>

namespace mutantur
{
    using byte = unsigned char; // Define byte for readability, assuming utils.h or other includes define it if not, add it here

    class mutant
    {
    public:
        mutant(const char* filename = nullptr);
        ~mutant();

        bool open(const char* filename);
        void finalize_mutation(const char* filename);
        void mutate(byte* address, size_t fn_len);

        // New method for executing mutated code
        void execute_mutated_code();

    private:
        std::ifstream m_stream;
        std::vector<byte> m_source;

        bool read_file_source(const char* filename);
        size_t find_function_start_index(byte* address, size_t fn_len);
        void insert_mutation_flag_and_body(size_t start_idx, size_t fn_len, byte insertion_space);
        void mutate_function(size_t fn_start_idx);

        // Helper method for allocating executable memory
        void* allocate_executable_memory(size_t size);
    };
}
