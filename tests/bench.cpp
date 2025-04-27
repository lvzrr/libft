#include <iostream>
#include <string>
#include <chrono>
#include <map>
#include <iomanip>
#include <cmath>

extern "C" {
	#include "tstr.h"
	#include "cstr.h"
}

using namespace std;
using namespace std::chrono;


struct Result {
	long long ns;
	size_t bytes;
};

map<string, Result> stats;

// Macro to benchmark and record result with memory
#define DO_AND_RECORD_MEM(func, label, mem_expr)                          \
	{                                                                      \
		auto start = high_resolution_clock::now();                          \
		func();                                                             \
		auto end = high_resolution_clock::now();                            \
		auto avg = duration_cast<nanoseconds>(end - start).count() / rounds; \
		size_t mem = (mem_expr);                                            \
		stats[label] = {avg, mem};                                          \
	}

const char* trim_input = "   grow   ";
const int rounds = 50000;
const size_t reserve_size = 200000;

void bench_tstr_pushstr() {
	t_string str = ft_tstr_new(0);
	ft_tstr_reserve(&str, reserve_size);

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; i++) {
		ft_tstr_clear(&str);
		ft_tstr_pushstr(&str, "grow");
	}
	auto end = high_resolution_clock::now();

	cout << "ft_tstr_pushstr (optimized): \n"
	     << "  Final alloc size: " << str.alloc_size << " bytes\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per call: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";

	ft_tstr_free(&str);
}

void bench_std_string_append() {
	string str;
	str.reserve(reserve_size);

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; i++) {
		str.clear();
		str.append("grow");
	}
	auto end = high_resolution_clock::now();

	cout << "std::string.append (reserved): \n"
	     << "  Final capacity: " << str.capacity() << " bytes\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per call: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";
}

void bench_tstr_trim() {
	t_string str = ft_tstr_from_cstr(trim_input);

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; i++) {
		ft_tstr_trim(&str, " ");
		ft_tstr_clear(&str);
		ft_tstr_pushstr(&str, trim_input);
	}
	auto end = high_resolution_clock::now();

	cout << "ft_tstr_trim: \n"
	     << "  Final len: " << str.len << "\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per call: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";

	ft_tstr_free(&str);
}

void bench_std_string_trim() {
	auto trim = [](string& s) {
		s.erase(s.find_last_not_of(" ") + 1);
		s.erase(0, s.find_first_not_of(" "));
	};

	string str(trim_input);

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; i++) {
		trim(str);
		str = trim_input;
	}
	auto end = high_resolution_clock::now();

	cout << "std::string trim: \n"
	     << "  Final size: " << str.size() << "\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per call: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";
}

void bench_tstr_pop_push() {
	t_string str = ft_tstr_new(0);
	const char* word = "hello world";

	ft_tstr_reserve(&str, 128);
	ft_tstr_pushstr(&str, word);

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; i++) {
		char c = ft_tstr_pop(&str);
		ft_tstr_push(&str, c);
	}
	auto end = high_resolution_clock::now();

	cout << "ft_tstr_pop/push: \n"
	     << "  Final len: " << str.len << "\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per cycle: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";

	ft_tstr_free(&str);
}

void bench_std_string_pop_push() {
	string str = "hello world";

	str.reserve(128);

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; i++) {
		char c = str.back();
		str.pop_back();
		str.push_back(c);
	}
	auto end = high_resolution_clock::now();

	cout << "std::string.pop/push: \n"
	     << "  Final size: " << str.size() << "\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per cycle: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";
}

void bench_tstr_insert() {
	t_string str = ft_tstr_new(0);
	ft_tstr_reserve(&str, reserve_size);

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; i++) {
		ft_tstr_clear(&str);
		ft_tstr_pushstr(&str, "gogogogo");
		ft_tstr_insert(&str, "__", 2);
	}
	auto end = high_resolution_clock::now();

	cout << "ft_tstr_insert: \n"
	     << "  Final alloc size: " << str.alloc_size << " bytes\n"
	     << "  Final len: " << str.len << "\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per call: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";

	ft_tstr_free(&str);
}

void bench_std_string_insert() {
	string str;
	str.reserve(reserve_size);

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; i++) {
		str.clear();
		str = "gogogogo";
		str.insert(2, "__");
	}
	auto end = high_resolution_clock::now();

	cout << "std::string.insert: \n"
	     << "  Final capacity: " << str.capacity() << " bytes\n"
	     << "  Final size: " << str.size() << "\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per call: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";
}


void bench_tstr_fit() {
	t_string str = ft_tstr_new(256);
	ft_tstr_pushstr(&str, "grow");

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; i++) {
		ft_tstr_fit(&str);
		ft_tstr_reserve(&str, 256);
	}
	auto end = high_resolution_clock::now();

	cout << "ft_tstr_fit: \n"
	     << "  Final alloc size: " << str.alloc_size << "\n"
	     << "  Final len: " << str.len << "\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per call: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";

	ft_tstr_free(&str);
}

void bench_std_string_fit() {
	string str;
	str.reserve(256);
	str = "grow";

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; i++) {
		str.shrink_to_fit();
		str.reserve(256);
	}
	auto end = high_resolution_clock::now();

	cout << "std::string.shrink_to_fit: \n"
	     << "  Final size: " << str.size() << "\n"
	     << "  Final capacity: " << str.capacity() << "\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per call: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";
}

void bench_tstr_repeat() {
	const char* pattern = "abc";
	t_string str = ft_tstr_new(0);
	ft_tstr_reserve(&str, 4096);

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; ++i) {
		ft_tstr_clear(&str);
		ft_tstr_repeat(&str, pattern, 10);
	}
	auto end = high_resolution_clock::now();

	cout << "ft_tstr_repeat:\n"
	     << "  Final len: " << str.len << "\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per call: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";

	ft_tstr_free(&str);
}

void bench_std_string_repeat() {
	const string pattern = "abc";
	string str;
	str.reserve(4096);

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; ++i) {
		str.clear();
		for (int j = 0; j < 10; ++j)
			str += pattern;
	}
	auto end = high_resolution_clock::now();

	cout << "std::string repeat:\n"
	     << "  Final size: " << str.size() << "\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per call: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";
}

const char* haystack_cstr = "the quick brown fox jumps over the lazy dog";
const char* needle = "lazy";

void bench_tstr_instr() {
	t_string str = ft_tstr_from_cstr(haystack_cstr);
	ssize_t index = -1;

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; ++i) {
		index = ft_tstr_instr(&str, needle);
	}
	auto end = high_resolution_clock::now();

	cout << "ft_tstr_instr: \n"
	     << "  Last result index: " << index << "\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per call: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";

	ft_tstr_free(&str);
}

void bench_std_string_find() {
	string str(haystack_cstr);
	size_t index = string::npos;

	auto start = high_resolution_clock::now();
	for (int i = 0; i < rounds; ++i) {
		index = str.find(needle);
	}
	auto end = high_resolution_clock::now();

	cout << "std::string::find: \n"
	     << "  Last result index: " << index << "\n"
	     << "  Elapsed time: " << duration_cast<microseconds>(end - start).count() << " µs\n"
	     << "  Avg per call: " << (duration_cast<nanoseconds>(end - start).count() / rounds) << " ns\n\n";
}

#include <map>
#include <iomanip>
#include <vector>

int main() {
	DO_AND_RECORD_MEM(bench_tstr_pushstr,         "ft_tstr_pushstr",         reserve_size);
	DO_AND_RECORD_MEM(bench_std_string_append,    "std_string_append",       reserve_size);

	DO_AND_RECORD_MEM(bench_tstr_trim,            "ft_tstr_trim",            128);
	DO_AND_RECORD_MEM(bench_std_string_trim,      "std_string_trim",         128);

	DO_AND_RECORD_MEM(bench_tstr_pop_push,        "ft_tstr_pop_push",        128);
	DO_AND_RECORD_MEM(bench_std_string_pop_push,  "std_string_pop_push",     128);

	DO_AND_RECORD_MEM(bench_tstr_insert,          "ft_tstr_insert",          reserve_size);
	DO_AND_RECORD_MEM(bench_std_string_insert,    "std_string_insert",       reserve_size);

	DO_AND_RECORD_MEM(bench_tstr_fit,             "ft_tstr_fit",             256);
	DO_AND_RECORD_MEM(bench_std_string_fit,       "std_string_fit",          256);

	DO_AND_RECORD_MEM(bench_tstr_repeat,          "ft_tstr_repeat",          4096);
	DO_AND_RECORD_MEM(bench_std_string_repeat,    "std_string_repeat",       4096);

	DO_AND_RECORD_MEM(bench_tstr_instr,           "ft_tstr_instr",           128);
	DO_AND_RECORD_MEM(bench_std_string_find,      "std_string_find",         128);

	vector<pair<string, string>> pairs = {
		{"ft_tstr_pushstr",     "std_string_append"},
		{"ft_tstr_trim",        "std_string_trim"},
		{"ft_tstr_pop_push",    "std_string_pop_push"},
		{"ft_tstr_insert",      "std_string_insert"},
		{"ft_tstr_fit",         "std_string_fit"},
		{"ft_tstr_repeat",      "std_string_repeat"},
		{"ft_tstr_instr",       "std_string_find"},
	};

	cout << "\033[35m═══════════════════════════════════════════════════════════════\033[0m\n";
	cout << "\033[1;35m  AVERAGE TIME + MEMORY SUMMARY:\033[0m\n";

	long long tstr_total_ns = 0, std_total_ns = 0;
	size_t tstr_total_bytes = 0, std_total_bytes = 0;

	for (const auto& [tstr_label, std_label] : pairs) {
		const auto& tstr = stats[tstr_label];
		const auto& stds = stats[std_label];

		double tstr_score = static_cast<double>(tstr.ns) * log2(static_cast<double>(tstr.bytes) + 1.0);
		double std_score = static_cast<double>(stds.ns) * log2(static_cast<double>(stds.bytes) + 1.0);

		cout << "  " << left << setw(24) << tstr_label
		     << ": " << setw(5) << tstr.ns << " ns, "
		     << setw(7) << tstr.bytes << " B, "
		     << "score = " << fixed << setprecision(2) << tstr_score << "\n";

		cout << "  " << left << setw(24) << std_label
		     << ": " << setw(5) << stds.ns << " ns, "
		     << setw(7) << stds.bytes << " B, "
		     << "score = " << fixed << setprecision(2) << std_score << "\n\n";

		tstr_total_ns += tstr.ns;
		tstr_total_bytes += tstr.bytes;
		std_total_ns += stds.ns;
		std_total_bytes += stds.bytes;
	}

	cout << "\033[1;35m  Totals:\n";
	cout << "    ft_tstr       → time: " << tstr_total_ns << " ns, memory: " << tstr_total_bytes << " bytes\n";
	cout << "    std::string   → time: " << std_total_ns << " ns, memory: " << std_total_bytes << " bytes\033[0m\n";

	cout << "\033[35m═══════════════════════════════════════════════════════════════\033[0m\n";

	return 0;
}
