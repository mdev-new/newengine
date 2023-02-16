#pragma once

#include <utility>

// user must manually free the buffer
std::pair<void*, long> read_file(const char *filename, const char *mode);
