#include <stdint.h>
#include <stddef.h>
// Include the Fuzzbuzz library used to control the fuzzer
#include "fuzzbuzz.hxx"
// Include the header with the function we want to call
#include "broken.h"

// The FZBZ_TARGET_CLASS helper lets Fuzzbuzz know that
// it should fuzz test this class
FZBZ_TARGET_CLASS(FuzzBrokenFunction);
struct FuzzBrokenFunction {
	// The constructor of this class takes a fzbz::Fuzzer, a handle that
	// allows configuration of the fuzz test
	FuzzBrokenFunction(fzbz::Fuzzer &f) {
		// Define the data the fuzzer should generate: in this case a byte array
		auto data = fzbz::generator::byteArray<std::vector<uint8_t>>();
		// We can define settings on the byte array, such as a max length:
		data.setMaxLength(100);

		// Create the fuzz "target" - this is the function that the 
		// fuzzer will repeatedly call with generated inputs
		auto target = fzbz::fuzzTarget([&](auto data) {
			BrokenFunction(data.data(), data.size());
		}, data); // a list of generators that correspond to the arguments of the function
		
		// Tell the fuzzer to begin fuzzing this target
		f.addFuzzTarget(target);
	}
};

