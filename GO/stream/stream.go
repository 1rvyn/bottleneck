package main

import (
	"fmt"
	"io"
	"os"
	"time"
)

func main() {
	start := time.Now()

	// Open input file
	inputFile, err := os.Open("../../input.txt")
	if err != nil {
		fmt.Println("Error opening input file:", err)
		return
	}
	defer inputFile.Close()

	// Open output file
	outputFile, err := os.Create("stream_output_go.txt")
	if err != nil {
		fmt.Println("Error creating output file:", err)
		return
	}
	defer outputFile.Close()

	buffer := make([]byte, 4096) // 4KB buffer
	for {
		n, err := inputFile.Read(buffer)
		if n > 0 {
			if _, err := outputFile.Write(buffer[:n]); err != nil {
				fmt.Println("Error writing to output file:", err)
				return
			}
		}
		if err == io.EOF {
			break
		}
		if err != nil {
			fmt.Println("Error reading input file:", err)
			return
		}
	}

	duration := time.Since(start)
	fmt.Printf("Stream I/O Time taken: %v\n", duration)
}
