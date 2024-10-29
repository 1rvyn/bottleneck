FROM --platform=linux/arm64 debian:latest

# Install dependencies
RUN apt-get update && \
    apt-get install -y gcc bash && \
    rm -rf /var/lib/apt/lists/*

# Set up working directory
WORKDIR /benchmarks

# Copy all source files
COPY . .

# Compile the input file generator and create input.txt
RUN cd utils && gcc -o 1gb 1gb.c && ./1gb

# Make the test script executable
RUN chmod +x run_bmarks.sh

# Compile C programs
RUN cd C && gcc -o bottleneck bottleneck.c && gcc -o buffered buffered.c && gcc -o stream stream.c

# Run the benchmark script using bash
CMD ["bash", "./run_bmarks.sh"]