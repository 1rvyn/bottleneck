# run_tests.sh
#!/bin/bash

echo "Starting I/O Benchmark Tests..."

echo "---- Running C Programs ----"
echo "Running C/bottleneck"
./C/bottleneck

echo "Running C/buffered"
./C/buffered

echo "Running C/stream"
./C/stream

echo "---- Running C++ Programs ----"
echo "Running CPP/bottleneck"
./CPP/bottleneck

echo "Running CPP/buffered"
./CPP/buffered

echo "Running CPP/stream"
./CPP/stream

echo "---- Running Go Programs ----"
echo "Running GO/bottleneck"
./GO/bottleneck

echo "Running GO/buffered"
./GO/buffered

echo "Running GO/stream"
./GO/stream

echo "---- Running Rust Programs ----"
echo "Running Rust/bottleneck"
./Rust/bottleneck

echo "Running Rust/buffered"
./Rust/buffered

echo "Running Rust/stream"
./Rust/stream

echo "I/O Benchmark Tests Completed."