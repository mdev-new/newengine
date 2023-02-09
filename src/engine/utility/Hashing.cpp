#include "Hashing.hpp"

[[gnu::noinline]] uint32_t hash_str(char const* str, bool lowercase) {
	uint32_t hash = 0;
	char c, i = 0; // lets not hash strings > 256 chars
	while(c = str[i++]) {
		hash = (hash * 0x811C9DC5) ^ ((lowercase)? c | 0x20 : c);
	}
	return hash;
}