#pragma once
#include <cstdint>

struct Hasher {
	uint32_t operator()(const uint32_t &h) const { return h; }
};

[[gnu::noinline]] uint32_t hash_str(char const* str, bool removeCases = false);

consteval uint32_t consthash(char const* str, bool removeCases = false) {
	uint32_t hash = 0, i = 0;
	char c = 0;
	while(c = str[i]) {
		if(removeCases && 'A' <= c && c <= 'Z') c += 'a' - 'A';
		hash = (hash * 0x811C9DC5) ^ c;
		i++;
	}
	return hash;
}